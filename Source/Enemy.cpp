#include "Enemy.h"
#include "Global.h"
#include "Animation.h"
#include "SFML/Graphics.hpp"
#include "Collision.h"
#include "iostream"

Animation anim;


Enemy::Enemy(sf::Vector2f spawningPos,float minX,float maxX,short h,unsigned short dangerLevel):
	//setting animation timers
	getDamTimer(20),
	deathTimer(60),
	attackAnimTimer(60)
{
	this->spawningPos = spawningPos;
	this->minX = minX;
	this->maxX = maxX,
	this->dangerLevel = dangerLevel;
	switch (dangerLevel)
	{
	case 1:
	{
		dps = 1;
		break;
	}
	case 2:
	{
		dps = 3;
		break;
	}
	default:
		break;
	}
	maxhealth = h;
	texture.loadFromFile("../assets/mummy_frames.png");
	Spr.setTexture(texture);
	Spr.setTextureRect(sf::IntRect(0,48,48,48));
	reset();
	sf::RectangleShape heart; heart.setSize(sf::Vector2f(10, 2));	heart.setFillColor(sf::Color::Red);

	for (short h = 0; h < maxhealth; h++)
	{
		healthBar.push_back(heart);
	}
}


//drawing enemy
void Enemy::draw(sf::RenderWindow* window)
{

	if (dead() && deathTimer > 0)
	{
		deathTimer--;
		anim.mummy_died(&Spr);
	}
	else if (attackAnimTimer < 60 && !dead()) // if enemy if attacking
	{
		anim.mummy_attack(&Spr, &attackAnimTimer, flipped);
	}
	else if (gettingDamage && !dead()) // if enemy is hit and not dead
	{
		anim.mummy_hurt(&Spr, flipped);
	}
	else if(!dead()) // walking animation
	{
		anim.mummy_walk(&Spr, flipped);
	}
	window->draw(Spr);

	//drawing heart bar
	for (unsigned short h = 0 ; h < health ; h++)
	{
		window->draw(healthBar[h]);
	}
}

//updating enemy
void Enemy::update(sf::Vector2f playerPos)
{
	float c;
	if (dangerLevel == 1)
	{
		c = Position.x + 8;
		if (!flipped)
			c -= 20;
	}
	else if (dangerLevel == 2)
	{
	    c = Position.x -90;
		if (flipped)
			c += 20;
	}
	for (short u = 0; u < healthBar.size(); u++)
	{
		healthBar[u].setPosition(c, Position.y +3);
			c += 10;
	}
	if(distance(playerPos,Position)<CELL_WIDTH *2)
	{
		followPlayer(playerPos);
		if (gettingDamage)
		{
			if (playerPos.x > Position.x)
				Position.x -= 3.f;
			else
				Position.x += 3.f;
		}
	}
	else
	{
		idleMovement();
	}

	Spr.setPosition(Position);
	if (gettingDamage)
	{
		if (getDamTimer > 0)
		{
			getDamTimer--;
		}
		else
		{
			getDamTimer = 20;
			gettingDamage = 0;
		}
	}
	if (!gettingDamage)
	{
		if (distance(Position, playerPos) < 10  && canAttack)
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


//return global bounds
sf::FloatRect Enemy::getGlobalBounds()
{
	return Spr.getGlobalBounds();
}

//following player
void Enemy::followPlayer(sf::Vector2f playerPos)
{
	if (Position.x > minX && Position.x < maxX)
	{
		if (playerPos.x > Position.x)
		{
			flipped = 0;
			Position.x += speed;
		}
		else if (playerPos.x <= Position.x + 2)
		{
			flipped = 1;
			Position.x -= speed;
		}
	}
}



void Enemy::reset()
{
	Position = spawningPos;
	Spr.setPosition(Position);
	flipped = 1;
	health = maxhealth;
	deathTimer = 120;
	gettingDamage = 0;
	attackCD = 120;
	canAttack = 1;
}

//check if attacking
bool Enemy::Attacking()
{
	return attacked;
}

void Enemy::idleMovement()
{
	if (Position.x < minX+ 5)
	{
		flipped = 0;
		Position.x += speed;
	}
	else if(Position.x >=maxX-5)
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


//returns enemy position coords
sf::Vector2f Enemy::getPos()
{
	return Position;
}

//decrease health
void Enemy::damage(unsigned short dps)
{
	health-= dps;
	gettingDamage = 1;

}


//check if health < 1
bool Enemy::dead()
{
	return health < 1;
}