#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(sf::Vector2f spawningPos,float minX,float maxX,short h,unsigned short dangerLevel);

	//draw functions
	void draw(sf::RenderWindow* window);

	//update function
	void update(sf::Vector2f playerPos);
	
	//function that resets the enemy
	void reset();

	//movements
	
	//idle movements (going left and right / guarding the position)
	void idleMovement();
	//following the player 
	void followPlayer(sf::Vector2f playerPos);
	
	//decrease enemy health
	void damage(unsigned short dps);

	//check if enemy is dead
	bool dead();

	//returns enemy position
	sf::Vector2f getPos();

	//check if enemy attacked
	bool Attacking();

	sf::FloatRect getGlobalBounds();


public:
	bool attacked;
	unsigned  short dps;

private:
	//sfml variables
	sf::Vector2f spawningPos;
	sf::Vector2f Position;
	sf::Texture texture;
	sf::Sprite Spr;

	//float variables
	const float speed = 1.f;
	float minX;
	float maxX;
	float getDamTimer;
	float deathTimer;
	float attackCD;
	float attackAnimTimer;

	//bool variables 
	bool flipped;
	bool gettingDamage;
	bool canAttack;

	//short variables
	short health;
	short maxhealth;
	unsigned short dangerLevel;

	//vectors
	std::vector<sf::RectangleShape> healthBar;

};

