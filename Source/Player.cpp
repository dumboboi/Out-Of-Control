#include "Player.h"
#include <Animation.h>
#include <Collision.h>
#include <iostream>
Animation animator;

Player::Player()
{
	textureSheet.loadFromFile("../assets/Warrior_SheetnoEffect.png");
	Spr.setTexture(textureSheet);
	Spr.setTextureRect(sf::IntRect(0, 0, 69, 44));
    sf::RectangleShape heart; heart.setSize(sf::Vector2f(10, 2));	heart.setFillColor(sf::Color::Green);

    for (short h = 0; h < health; h++)
    {
        healthBar.push_back(heart);
    }
}

void Player::draw(sf::RenderWindow* window)
{
    if (dead() && deathAnimTimer > 0)
    {
        animator.p_death(&Spr, &deathAnimTimer, flipped);
    }
    else if (isDashing && !dead())
    {
        animator.p_dash(&Spr, flipped);
    }
    else if (isAttacking && !dead())
    {
        animator.p_attack(&Spr, flipped);
    }
    else if (hurting &&!dead())
    {
        animator.hurt(&Spr, flipped);
    }
	else if (isMoving == 1 &&!dead())
	{
		animator.moving(&Spr,flipped);
	}
	else if(!dead())
	{
		animator.idle(&Spr, flipped);
	}
	window->draw(Spr);
    //drawing healthbar
    for (unsigned short h = 0; h < health; h++)
    {
        window->draw(healthBar[h]);
    }
}


void Player::update(Map* currentLevel , std::vector<sf::Vector2f>enemiesPos, EnemyType enemy,unsigned short Level)
{
    if (dead())
    {
        if (respawnTimer > 0)
            respawnTimer--;
        else
        {
            reset(Level);
        }
    }

    //movements
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !dead())
	{ 
        Position.x = std::min(static_cast<float>(SCREEN_WIDTH - 36), Position.x + speed);
        if (map_collision(Position.x + 1, Position.y- 2.f,currentLevel, { Cell::Ground }) && !OnGround)
            Position.x -= speed;

		flipped = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !dead())
	{ 
        Position.x = std::max(static_cast<float>(5), Position.x - speed);
        if (map_collision(Position.x - 1, Position.y -2.f, currentLevel, { Cell::Ground }) && !OnGround)
            Position.x += speed;
        flipped = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		isMoving = 1;
	else
		isMoving = 0;

	/*if (Position.x > SCREEN_WIDTH - 100)
		Position.x = 10;*/
	//tests
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && OnGround && jumpingCountdown == 80 && !dead())
    {
        isJumping = 1;
        jumpingCountdown--;
    }
    if (jumpingCountdown != 80)
    {
        if (jumpingCountdown > 0)
            jumpingCountdown--;
        else
            jumpingCountdown = 80;
    }
    if (isJumping == 1)
    {
        if (jumpHeight > 0)
        {
            Position.y += jumpSpeed;
            if (map_collision(Position.x, Position.y - 1, currentLevel, { Cell::Ground }))
            {
                Position.y -= jumpSpeed;
            }
            jumpHeight--;
        }
        if (jumpHeight <= 0)
        {
            jumpHeight = 25.f;
            isJumping = 0;
            vertical_speed = 2.5f;
        }
    }
    short c = Position.x - 15;
    if (flipped)
    {
        c += 15;
    }
    //updating healthbar position
    for (short u = 0; u < healthBar.size(); u++)
    {
        healthBar[u].setPosition(c, Position.y + 3);
        c += 10;
    }

    //standing collision
    if (map_collision(Position.x, Position.y + vertical_speed, currentLevel, {Cell::Ground,Cell::Edge, Cell::Wall}))
    {
        OnGround = 1;
        vertical_speed = 0;
    }
    else
    {
        if (!OnGround)
            vertical_speed = 2.6f;
        if (isJumping == 0 && jumpingCountdown == 80)
        {
            vertical_speed = 2.5f;
        }
        OnGround = 0;
    }

    //checking i player is hurting
    if (hurting)
    {
        if (hurttimer > 0)
            hurttimer--;
        else
        {
            hurttimer = 120;
            hurting = 0;
        }
    }
    //checking if pressed Left Shift to Dash
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && !isDashing && !dead())
    {
        isDashing = 1;
    }
    if (isDashing)
    {
        if(flipped)
        {
            Position.x = std::max(static_cast<float>(5), Position.x - 1.f);
        }
        else
        {
            Position.x = std::min(static_cast<float>(SCREEN_WIDTH - 36), Position.x + 1.f);
        }
        if (dashingTimer > 0)
        {
            dashingTimer--;
        }
        else
        {
            dashingTimer = 70;
            isDashing = 0;
        }
    }
    //checking if clicked left click to attack
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isAttacking && !dead())
    {
        isAttacking = 1;
    }
    //if player is  attacking
    if (isAttacking)
    {
        switch (enemy)
        {
        case EnemyType::Mummy:
        {
            hitDistance = CELL_WIDTH/2;
            break;
        }
        case EnemyType::SoulReaper:
        {
            hitDistance = CELL_WIDTH + CELL_WIDTH/2;
            break;
        }
            default:
                break;

        }
        for (unsigned short e = 0; e < enemiesPos.size(); e++)
        {
            if (distance(Position, enemiesPos[e]) < hitDistance && canDamage)
            {
                damageEnemy = 1;
                canDamage = 0;
            }
        }
        if (attackingTimer > 0)
        {
            attackingTimer--;
        }
        else
        {
            attackingTimer = 120;
            isAttacking = 0;
        }
    }
    //if player damage is on cooldown(cannot damage an enemy)
    if (!canDamage)
    {
        if (damageCD > 0)
            damageCD--;
        else
        {
            damageCD = 150;
            canDamage = 1;
        }
    }


    //std::cout << "Player Health : " << health << std::endl;
    Position.y += vertical_speed;
    Spr.setPosition(Position);
}
void Player::resetPos(unsigned short Level)
{
    switch (Level)
    {
    case 1:
    {
        Position = sf::Vector2f(10, SCREEN_HEIGHT / 2 + 50);

        break;
    }
    case 2:
    {
        Position = sf::Vector2f(32, SCREEN_HEIGHT / 2 + 160);
        break;
    }
    case 3:
    {
        Position = sf::Vector2f(SCREEN_WIDTH - 160, CELL_HEIGHT*3);
        break;
    }
    case 4:
    {
        Position = sf::Vector2f(32, SCREEN_HEIGHT / 2 + 160);
        break;
    }
    default:
        break;
    }
    Spr.setPosition(Position);

    isMoving = 0;
    OnGround = 0;

    jumpingCountdown = 80;
    dashingTimer = 70;
    attackingTimer = 120;
    damageEnemy = 0;
    canDamage = 1;
    damageCD = 150;
    deathAnimTimer = 110;
    died = 0;
    deathAnimTimer = 110;
    respawnTimer = 160;
}




//if looking left
bool Player::isFlipped()
{
    return flipped;
}

//if attacking
bool Player::Attacking()
{
    return damageEnemy;
}

//player get damaged
void Player::damage(unsigned short dps)
{
    health-=dps;
    hurting = 1;
}

//returns player sprites global bounds
sf::FloatRect Player::getGlobalBounds()
{
    return Spr.getGlobalBounds();
}

//check if player died - > health < 1.
bool  Player::dead()
{
    return health < 1;
}

//reset player(position / damage per second / status)
void Player::reset(unsigned short Level)
{
    switch (Level)
    {
    case 1:
    {
        Position = sf::Vector2f(10, SCREEN_HEIGHT / 2 + 150);
        dps = 1;
        break;
    }
    case 2:
    {
        Position = sf::Vector2f(32, SCREEN_HEIGHT / 2 + 160);
        dps = 3;
        break;
    }
    case 3:
    {
        Position = sf::Vector2f(SCREEN_WIDTH - 160, CELL_HEIGHT*3);
        dps = 5;
        break;
    }
    case 4:
    {
        Position = sf::Vector2f(32, SCREEN_HEIGHT / 2 + 160);
        dps = 8;
        break;
    }
    default:
        break;

    }

	Spr.setPosition(Position);
	isMoving = 0;
	flipped = 0;
    vertical_speed = 0;
    OnGround = 0;
    jumpingCountdown = 80;
    isJumping = 0;
    isDashing = 0;
    dashingTimer = 70;
    attackingTimer = 120;
    damageEnemy = 0;
    canDamage = 1;
    damageCD = 150;
    health = 8;
    deathAnimTimer = 110;
    died = 0;
    deathAnimTimer = 110;
    respawnTimer = 160;
}

//returns player position
sf::Vector2f Player::getPos()
{
    return Position;
}