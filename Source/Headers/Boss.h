#pragma once
#include <SFML/Graphics.hpp>
#include <Global.h>

class Boss
{
public:
	Boss(const unsigned short ID);

	//drawing the enemy
	void draw(sf::RenderWindow* window);
	//draw healthBar //RECURSION
	void drawHealthBar(sf::RenderWindow* window , std::vector<sf::RectangleShape> healthBar ,unsigned short heart);
	
	//boss updated
	void update(sf::Vector2f playerPos);
	
	//updates for movements
	void movementsUpdates(sf::Vector2f playerPos);
	
	
	//reseting boss
	void reset();
	
	//flying on top of the window
	void guardingState();
	
	//following/attacking player
	void attackingPlayer(sf::Vector2f playerPos);
	
	//decrease health
	void damage(short dps);
	
	//when his health gets under the half -> boss becomes dangerous (damage faster).
	void phase2update();

	//return boss position coords
	sf::Vector2f getPos();

	//checks if boss is attacking
	bool Attacking();
	
	//checks if health is < 1
	bool dead();

	//check if boss transformed (health < half)
	bool Transformed();




	//variables
public:
	bool attacked;
	bool dangerous;
	bool droppedLoot;
	bool isDown;

	float dps;

private:
	//sfml variables
	sf::Texture texture;
	sf::Sprite Spr;
	sf::Vector2f Position;
	sf::Color originalCol;

	//bool variables
	bool flipped;
	bool goingDown;
	bool goingUp;
	bool isUp;
	bool isHurt;
	bool canAttack;
	bool UsingAbility;
	bool animatingability;
	bool healed;

	//float variables
	const float speed = 2.8f;
	float idleAnimTimer;
	float attackAnimTimer;
	float deathAnimTimer;
	float abilityAnimTimer;
	float circlingDownTimer;
	float circlingUpTimer;
	float hurtingTimer;
	float hurtingCooldown;
	float attackCD;
	float abilityCD;

	//short variables
	short health;
	unsigned short ID; 

	//vectors
	std::vector<sf::RectangleShape> healthBar;
};

