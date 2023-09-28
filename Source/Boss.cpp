#include "Boss.h"
#include <Global.h>
#include <Animation.h>
#include <Collision.h>
#include "iostream"

Animation bossAnim;

Boss::Boss(const unsigned short ID):
	idleAnimTimer(80),
	attackAnimTimer(130),
	deathAnimTimer(360),
	abilityAnimTimer(120)
{
	healed = false;
	this->ID = ID;
	dps = 1;
	texture.loadFromFile("../assets/boss1.png.");
	Spr.setTexture(texture);
	Spr.setTextureRect(sf::IntRect(0, 0, 100, 100));
	reset();
	Spr.setScale(2.f, 2.f);
	abilityCD = 600;
	originalCol = Spr.getColor();

	sf::RectangleShape heart; heart.setSize(sf::Vector2f(5, 2));	heart.setFillColor(sf::Color::Yellow);

	for (short h = 0; h < health; h++)
	{
		healthBar.push_back(heart);
	}

}


void Boss::draw(sf::RenderWindow* window)
{
	if (UsingAbility && abilityAnimTimer > 0)
	{
		abilityAnimTimer--;
		bossAnim.b_skill(&Spr, &abilityAnimTimer, flipped);
		animatingability = true;
		if (abilityAnimTimer <= 0)
			animatingability = false;
	}
	else if (dead() && deathAnimTimer > 0)
	{
		deathAnimTimer--;
		bossAnim.b_death(&Spr,&deathAnimTimer);
	}
	else if (isUp && !dead())
	{
		bossAnim.b_idle(&Spr, &idleAnimTimer, flipped);
	}
	else if(!dead())
	{
		if(!dead() && attackAnimTimer < 130)
			bossAnim.b_attack(&Spr, &attackAnimTimer, flipped);
		else
			bossAnim.b_idle(&Spr, &idleAnimTimer, flipped);

	}
	if (isHurt)
		Spr.setColor(sf::Color::Red);
	else
		Spr.setColor(originalCol);

	window->draw(Spr);
	drawHealthBar(window, healthBar, 0);
}

void Boss::drawHealthBar(sf::RenderWindow* window, std::vector<sf::RectangleShape> healthBar , unsigned short heart)
{
	if (heart < health)
	{
		window->draw(healthBar[heart]);
		drawHealthBar(window, healthBar, heart + 1);
	}

}


sf::Vector2f  Boss::getPos()
{
	return Position;
}

void Boss::movementsUpdates (sf::Vector2f playerPos)
{
	if (isUp)
	{
		guardingState();
		if (circlingUpTimer > 0)
		{
			circlingUpTimer--;
		}
		else
		{
			circlingUpTimer = 700;
			isUp = 0;
			goingDown = 1;
		}
	}
	else if (goingDown)
	{
		if (Position.y < 400)
		{
			if (playerPos.x > Position.x)
			{
				Position.x += speed;
			}
			else
			{
				Position.x -= speed;
			}

			Position.y++;

		}
		else
		{
			goingDown = 0;
			isDown = 1;
		}
	}
	else if (isDown)
	{
		if(ID == 1)
			attackingPlayer(playerPos);
		else
		{
			if (abilityCD >=599 && !UsingAbility)
			{
				UsingAbility = 1;

			}
			if (UsingAbility && abilityAnimTimer >0)
			{
				if (abilityCD > 0)
					abilityCD--;
				else
				{
					abilityCD = 600;
					UsingAbility = 0;
					abilityAnimTimer = 122;
				}
			}
			else
			{
			     attackingPlayer(playerPos);
			}
		}
		if (circlingDownTimer > 0)
		{
			circlingDownTimer--;
		}
		else
		{
			circlingDownTimer = 500;
			isDown = 0;
			goingUp = 1;
			abilityCD = 600;
			UsingAbility = 0;
			abilityAnimTimer = 121;
		}
	}
	else if (goingUp)
	{
		if (Position.y > 200)
		{
			Position.y--;
		}
		else
		{
			goingUp = 0;
			isUp = 1;
		}
	}

	//checking if boss is hurting
	if (isHurt)
	{
		if (hurtingCooldown > 0)
		{
			hurtingCooldown--;
		}
		else
		{
			hurtingCooldown = hurtingTimer;
			isHurt = 0;
		}
	}
	else // if boss can attack
	{
		if (distance(Position, playerPos) < 140.f && canAttack)
		{
			attacked = 1;
			attackCD--;
			canAttack = 0;
			attackAnimTimer--;
		}
	}
	if (!canAttack)
	{
		if (attackCD > 0)
			attackCD--;
		else
		{
			attackCD = 120;
			canAttack = 1;
		}
	}
}



void Boss::update(sf::Vector2f playerPos)
{

	movementsUpdates(playerPos);


	Spr.setPosition(Position);
	//updating healthbar position
	short c = (short)(Spr.getPosition().x - 55);
	if (flipped)
		c += 5;
	for (short u = 0; u < healthBar.size(); u++)
	{
		healthBar[u].setPosition(c, Position.y + 10);
		c += 5;
	}
	if (ID == 2)
	{
		if (animatingability)
		{
			dps = 5;
		}
		else
		{
			dps = 1;
		}
		if (!healed && health < 20)
		{
			health += 28;
			healed = true;
		}
	}
}





//idle movements
void Boss::guardingState()
{
	if (Position.x < 100)
	{
		flipped = 0;
		Position.x += speed;
	}
	else if (Position.x >= SCREEN_WIDTH - 100)
	{
		flipped = 1;
		Position.x -= speed;
	}
	if (flipped)
	{
		Position.x -= speed;

	}
	else
	{
		Position.x += speed;
	}
}

//following player
void Boss::attackingPlayer(sf::Vector2f playerPos)
{
	if (distance(playerPos, Position) >= 20)
	{

		if (playerPos.x -2.8f > Position.x)
		{
			flipped = 0;
			Position.x += speed;
		}
		else if (playerPos.x +2.8f < Position.x )
		{
			flipped = 1;
			Position.x -= speed;
		}
	}
}


void Boss::damage(short dps)
{
	health-=dps;
	isHurt = 1;
	hurtingTimer = hurtingCooldown;
}

bool Boss::dead()
{
	return health < 1;
}

bool Boss::Attacking()
{
	return attacked;
}


void Boss::reset()
{
	Position = sf::Vector2f(SCREEN_WIDTH / 2, 200);
	Spr.setPosition(Position);
	health = 60;
	isUp = 1;
	isDown = 0;
	goingDown = 0;
	goingUp = 0;
	circlingDownTimer = 500;
	circlingUpTimer = 700;
	isHurt = 0;
	canAttack = 1;
	hurtingTimer = 200;
	hurtingCooldown = hurtingTimer;
	dangerous = false;
	droppedLoot = false;
}

void Boss::phase2update()
{
	hurtingTimer = 90;
	dangerous = true;
}

bool Boss::Transformed()
{
	return !dangerous && health <= 30;
}