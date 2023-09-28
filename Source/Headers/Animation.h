#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation();
	
	//player animation
	void idle(sf::Sprite* sprite,bool flipped);
	void moving(sf::Sprite* sprite, bool flipped);
	void hurt(sf::Sprite* sprite, bool flipped);
	void p_dash(sf::Sprite* sprite, bool flipped);
	void p_attack(sf::Sprite* sprite, bool flipped);
	void p_death(sf::Sprite* sprite,float *timer, bool flipped);

	//mummy animations
	void mummy_walk(sf::Sprite* sprite, bool flipped);
	void mummy_hurt(sf::Sprite* sprite, bool flipped);
	void mummy_died(sf::Sprite* sprite);
	void mummy_attack(sf::Sprite* sprite, float *timer,  bool flipped);
	
	//coinsAnim
	void coinFlip(sf::Sprite* sprite);

	//boss animations
	void b_idle(sf::Sprite* sprite, float* timer, bool flipped);
	void b_attack(sf::Sprite* sprite, float* timer, bool flipped);
	void b_death(sf::Sprite*, float* timer);
	void b_skill(sf::Sprite* sprite, float* timer, bool flipped);

//TIMERS
private:
	float idleTimer;
	float movingTimer;
	float hurtTimer;
	float mummywalkTimer;
	float dashTimer;
	float p_attackTimer;
	float m_hurtTimer;
	float m_deathTimer;
	float coinsTimer;
};

