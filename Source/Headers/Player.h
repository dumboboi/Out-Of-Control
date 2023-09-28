#pragma once
#include <SFML/Graphics.hpp>
#include <Global.h>
class Player
{
public:
	Player();
	void draw(sf::RenderWindow* window);
	void update(Map* currentLevel , std::vector<sf::Vector2f>enemiesPos, EnemyType enemy,unsigned short Level);
	void reset(unsigned short Level);
	void resetPos(unsigned short Level);

	sf::Vector2f getPos();

	void damage(unsigned short dps);


	bool Attacking();
	bool dead();
	bool isFlipped();

	sf::FloatRect getGlobalBounds();

public:
	bool damageEnemy;
	bool died;
	short dps;


private:
	//sfml variables
	sf::Vector2f Position;
	sf::Texture textureSheet;
	sf::Sprite Spr;

	//float variables
	const float speed = 2.5f;
	float Gravity = 5.f;
	float vertical_speed;
	float jumpingCountdown;
	float dashingTimer;
	float attackingTimer;
	float damageCD;
	float jumpSpeed = -6.8f;
	float jumpHeight = 25.f;
	float hurttimer = 120;
	float freezTimer;
	float deathAnimTimer;
	float respawnTimer;
	//double variables
	double hitDistance;

	//bool variables
	bool isMoving;
	bool flipped;
	bool isJumping;
	bool OnGround;
	bool isAttacking;
	bool isDashing;
	bool canDamage;
	bool hurting;
	bool canMove;

	//short variable
	short health = 8;

	//VECTORS
	std::vector<sf::RectangleShape> healthBar;
};

