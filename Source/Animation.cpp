#include "Animation.h"
#include <Global.h>

Animation::Animation() :
	idleTimer(60),
	movingTimer(120),
	hurtTimer(80),
	mummywalkTimer(60),
	dashTimer(70),
	p_attackTimer(120),
	m_hurtTimer(20),
	m_deathTimer(120),
	coinsTimer(80)
{}


void Animation::idle(sf::Sprite* sprite, bool flipped)
{
	if (idleTimer > 50)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(0, 0, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(759, 0, 69, 44));
	}
	else if (idleTimer > 40)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(69, 0, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(690, 0, 69, 44));
	}	
	else if (idleTimer > 30)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(138, 0, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(621, 0, 69, 44));
	}
	else if (idleTimer > 20)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(207, 0, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(552, 0, 69, 44));
	}
	else if (idleTimer > 10)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(276, 0, 69, 44));

		else
			sprite->setTextureRect(sf::IntRect(483, 0, 69, 44));
	}
	else if (idleTimer > 0)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(345, 0, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(414, 0, 69, 44));
	}
	else
		idleTimer = 60;
	idleTimer--;
}


void Animation::moving(sf::Sprite* sprite, bool flipped)
{
	if (movingTimer > 105)
		if(!flipped)
			sprite->setTextureRect(sf::IntRect(0, 44, 69, 44));
		else 
			sprite->setTextureRect(sf::IntRect(759, 44, 69, 44));
	else if (movingTimer > 90)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(69, 44, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(690, 44, 69, 44));
	}
	else if (movingTimer > 75)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(138, 44, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(552, 44, 69, 44));

	}
	else if (movingTimer > 60)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(207, 44, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(483, 44, 69, 44));

	}
	else if (movingTimer > 45)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(276, 44, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(414, 44, 69, 44));
	}
	else if (movingTimer > 30)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(345, 44, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(345, 44, -69, 44));

	}
	else if (movingTimer > 15)
	{
		if (!flipped)
			sprite->setTextureRect(sf::IntRect(0, 88, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(759, 88, 69, 44));

	}
	else if (movingTimer > 0)
	{
		if(!flipped)
			sprite->setTextureRect(sf::IntRect(69, 88, 69, 44));
		else
			sprite->setTextureRect(sf::IntRect(690, 88, 69, 44));
	}
	else
		movingTimer = 120;
	movingTimer--;
}

void Animation::hurt(sf::Sprite* sprite, bool flipped)
{
	if (hurtTimer > 60)
	{
		sprite->setTextureRect(sf::IntRect(138, 264, 69, 44));

	}
	else if (hurtTimer > 40)
	{
		sprite->setTextureRect(sf::IntRect(207, 264, 69, 44));

	}
	else if (hurtTimer > 20)
	{
		sprite->setTextureRect(sf::IntRect(276, 264, 69, 44));

	}
	else if (hurtTimer > 0)
	{
		sprite->setTextureRect(sf::IntRect(345, 264, 69, 44));
	}
	else
	{
		hurtTimer = 80;
	}
	hurtTimer--;
}

void Animation::mummy_walk(sf::Sprite* sprite, bool flipped)
{
	if (mummywalkTimer > 50)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0,48,48,48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(240, 0, 48, 48));
		}
	}
	else if (mummywalkTimer > 40)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(48, 48, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(192, 0, 48, 48));
		}

	}
	else if (mummywalkTimer > 30)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(96, 48, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(144, 0, 48, 48));
		}

	}
	else if (mummywalkTimer > 20)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(144, 48, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(96, 0, 48, 48));
		}

	}
	else if (mummywalkTimer > 10)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(192, 48, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(48, 0, 48, 48));
		}

	}
	else if (mummywalkTimer > 0)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(240, 48, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 0, 48, 48));
		}

	}
	else
	{
		mummywalkTimer = 60;
	}
	mummywalkTimer--;
}

void Animation::p_dash(sf::Sprite* sprite, bool flipped)
{
	if (dashTimer > 60)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*3, CELL_HEIGHT * 11, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 8, CELL_HEIGHT * 11, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (dashTimer > 50)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 4, CELL_HEIGHT * 11, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 7, CELL_HEIGHT * 11, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (dashTimer > 40)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 5, CELL_HEIGHT * 11, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 6, CELL_HEIGHT * 11, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (dashTimer > 30)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 11, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (dashTimer > 20)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 10, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (dashTimer > 10)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*2, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 9, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (dashTimer > 0)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 3, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 8, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else
	{
		dashTimer = 60;
	}
	dashTimer--;

}

void Animation::p_attack(sf::Sprite* sprite, bool flipped)
{
	if (p_attackTimer > 110)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 2, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 9, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (p_attackTimer > 100)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 3, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 8, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 90)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 4, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 7, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 80)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 5, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 6, CELL_HEIGHT * 2, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 70)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH* 11, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 60)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 10, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 50)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*2, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*9, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 40)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 3, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 8, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 30)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 4, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 7, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (p_attackTimer > 20)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 5, CELL_HEIGHT * 3, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 6, CELL_HEIGHT * 12, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 10)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 11, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else if (p_attackTimer > 0)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 10, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}

	}
	else
	{
		p_attackTimer = 60;
	}
	p_attackTimer--;

}

void Animation::mummy_hurt(sf::Sprite* sprite, bool flipped)
{
	if (m_hurtTimer > 10)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0,144,48,48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(48, 96, 48, 48));
		}
	}
	else if (m_hurtTimer > 0)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(48, 144, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 96, 48, 48));
		}
	}
	else
		m_hurtTimer = 20;
	m_hurtTimer--;
}

void Animation::mummy_died(sf::Sprite* sprite)
{
	if (m_deathTimer > 100)
	{
		sprite->setTextureRect(sf::IntRect(0, 48*4, 48, 48));
	}
	else if (m_deathTimer > 80)
	{
		sprite->setTextureRect(sf::IntRect(48, 48 * 4, 48, 48));

	}
	else if (m_deathTimer > 60)
	{
		sprite->setTextureRect(sf::IntRect(48*2, 48 * 4, 48, 48));
	}
	else if (m_deathTimer > 40)
	{
		sprite->setTextureRect(sf::IntRect(48*3, 48 * 4, 48, 48));
	}
	else if (m_deathTimer > 20)
	{
		sprite->setTextureRect(sf::IntRect(48*4, 48 * 4, 48, 48));
	}
	else if (m_deathTimer > 0)
	{
		sprite->setTextureRect(sf::IntRect(48*5, 48 * 4, 48, 48));
	}
	else
		m_deathTimer = 120;
	m_deathTimer--;

}

void Animation::mummy_attack(sf::Sprite* sprite,float *timer, bool flipped)
{
	if (*timer > 50)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, 48 * 5, 48 ,48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(48*5, 48 * 6, 48, 48));
		}
	}
	else if (*timer > 40)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(48, 48 * 5, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(48*4, 48 * 6, 48, 48));
		}
	}
	else if (*timer > 30)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(48*2, 48 * 5, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(48*3, 48 * 6, 48, 48));
		}
	}
	else if (*timer > 20)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(48 * 3, 48 * 5, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(48 * 2, 48 * 6, 48, 48));
		}
	}
	else if (*timer > 10)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(48 * 4, 48 * 5, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(48 , 48 * 6, 48, 48));
		}
	}
	else if (*timer > 0)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(48 * 5, 48 * 5, 48, 48));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 48 * 6, 48, 48));
		}
	}
	else
	{
		*timer = 61;
	}
	(*timer)--;

}

void Animation::p_death(sf::Sprite* sprite, float* timer, bool flipped)
{
	if (*timer > 100)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 2, CELL_HEIGHT*4, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 9, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 90)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 3, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 8, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 80)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 4, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 7, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 70)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 5, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 6, CELL_HEIGHT * 4, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 60)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*11, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 50)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 10, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 40)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*2, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 9, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 30)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*3, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 8, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 20)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*4, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 7, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 10)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH*5, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 6, CELL_HEIGHT * 5, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else if (*timer > 0)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, CELL_HEIGHT * 6, CELL_WIDTH, CELL_HEIGHT));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(CELL_WIDTH * 11, CELL_HEIGHT * 6, CELL_WIDTH, CELL_HEIGHT));
		}
	}
	else
	{
		*timer = 111;
	}
	(*timer)--;
}


void Animation::coinFlip(sf::Sprite* sprite)
{
	if (coinsTimer > 60)
	{
		sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
	}
	else if (coinsTimer > 40)
	{
		sprite->setTextureRect(sf::IntRect(16, 0, 16, 16));
	}
	else if (coinsTimer > 20)
	{
		sprite->setTextureRect(sf::IntRect(32, 0, 16, 16));
	}
	else if (coinsTimer > 0)
	{
		sprite->setTextureRect(sf::IntRect(48, 0, 16, 16));
	}
	else
		coinsTimer = 81;
	coinsTimer--;
}

void Animation::b_idle(sf::Sprite* sprite, float* timer, bool flipped)
{
	if (*timer > 70)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(300, 200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 0 ,100, 100));
		}
	}
	else if (*timer > 60)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(200, 200,100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 100, 100, 100));
		}
	}
	else if (*timer > 50)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(100, 200 , 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(200, 0 , 100, 100));
		}
	}
	else if (*timer > 40)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, 200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(300, 0, 100, 100));
		}
	}
	else if (*timer > 30)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(300, 300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 100, 100, 100));
		}
	}
	else if (*timer > 20)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(200, 300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(100, 100, 100, 100));
		}
	}
	else if (*timer > 10)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(100, 300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(200, 100, 100, 100));
		}
	}
	else if (*timer > 0)
	{
		if (flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, 300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(300, 100, 100, 100));
		}
	}
	else
	{
		*timer = 81;
	}
	(*timer)--;

}


void Animation::b_attack(sf::Sprite* sprite, float* timer, bool flipped)
{
	if (*timer > 120)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, 400, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(500,700, 100, 100));
		}
	}
	else if (*timer > 110)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(100, 400, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(400, 700, 100, 100));
		}
	}
	else if (*timer > 100)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(200, 400, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(300, 700, 100, 100));
		}
	}
	else if (*timer > 90)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(300, 400, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(200, 700, 100, 100));
		}
	}
	else if (*timer > 80)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(400, 400, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(100, 700, 100, 100));
		}
	}
	else if (*timer > 70)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(500, 400, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 700, 100, 100));
		}
	}
	else if (*timer > 60)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0 , 500, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(500, 800, 100, 100));
		}
	}
	else if (*timer > 50)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(100, 500 , 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(400, 800, 100, 100));
		}
	}
	else if (*timer > 40)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(200, 500, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(300, 800, 100, 100));
		}
	}
	else if (*timer > 30)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(300, 500, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(200, 800, 100, 100));
		}
	}
	else if (*timer > 20)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(400, 500, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(100, 800, 100, 100));
		}
	}
	else if (*timer > 10)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(500, 500, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 800, 100, 100));
		}
	}
	else if (*timer > 0)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, 600, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(500, 900, 100, 100));
		}
	}
	else
	{
		*timer = 131;
	}
	(*timer)--;

}

void Animation::b_death(sf::Sprite* sprite, float* timer)
{
	if (*timer > 340)
	{
		sprite->setTextureRect(sf::IntRect(0,1000,100,100));
	}
	else if (*timer > 320)
	{
		sprite->setTextureRect(sf::IntRect(100, 1000, 100, 100));
	}
	else if (*timer > 300)
	{
		sprite->setTextureRect(sf::IntRect(200, 1000, 100, 100));
	}
	else if (*timer > 280)
	{
		sprite->setTextureRect(sf::IntRect(300, 1000, 100, 100));
	}
	else if (*timer > 260)
	{
		sprite->setTextureRect(sf::IntRect(400, 1000, 100, 100));
	}
	else if (*timer > 240)
	{
		sprite->setTextureRect(sf::IntRect(500, 1000, 100, 100));
	}
	else if (*timer > 220)
	{
		sprite->setTextureRect(sf::IntRect(600, 1000, 100, 100));
	}
	else if (*timer > 200)
	{
		sprite->setTextureRect(sf::IntRect(700, 1000, 100, 100));
	}
	else if (*timer > 180)
	{
		sprite->setTextureRect(sf::IntRect(800, 1000, 100, 100));
	}
	else if (*timer > 160)
	{
		sprite->setTextureRect(sf::IntRect(900, 1000, 100, 100));
	}
	else if (*timer > 140)
	{
		sprite->setTextureRect(sf::IntRect(0, 1100, 100, 100));
	}
	else if (*timer > 120)
	{
		sprite->setTextureRect(sf::IntRect(100, 1100, 100, 100));
	}
	else if (*timer > 100)
	{
		sprite->setTextureRect(sf::IntRect(200, 1100, 100, 100));
	}
	else if (*timer > 80)
	{
		sprite->setTextureRect(sf::IntRect(300, 1100, 100, 100));
	}
	else if (*timer > 60)
	{
		sprite->setTextureRect(sf::IntRect(400, 1100, 100, 100));
	}
	else if (*timer > 40)
	{
		sprite->setTextureRect(sf::IntRect(500, 1100, 100, 100));
	}
	else if (*timer > 20)
	{
		sprite->setTextureRect(sf::IntRect(600, 1100, 100, 100));
	}
	else if (*timer > 0)
	{
		sprite->setTextureRect(sf::IntRect(700, 1100, 100, 100));
	}
	else
	{
		*timer = 361;
	}
	(*timer)--;

}

void Animation::b_skill(sf::Sprite* sprite, float* timer, bool flipped)
{

    if (*timer > 110)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, 1200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(500, 1400, 100, 100));
		}
	}
	else if (*timer > 100)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(100, 1200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(400, 1400, 100, 100));
		}
	}
	else if (*timer > 90)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(200, 1200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(300, 1400, 100, 100));
		}
	}
	else if (*timer > 80)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(300, 1200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(200, 1400, 100, 100));
		}
	}
	else if (*timer > 70)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(400, 1200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(100, 1400, 100, 100));
		}
	}
	else if (*timer > 60)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(500, 1200, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 1400, 100, 100));
		}
	}
	else if (*timer > 50)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(0, 1300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(500, 1500, 100, 100));
		}
	}
	else if (*timer > 40)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(100, 1300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(400, 1500, 100, 100));
		}
	}
	else if (*timer > 30)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(200, 1300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(300, 1500, 100, 100));
		}
	}
	else if (*timer > 20)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(300, 1300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(200, 1500, 100, 100));
		}
	}
	else if (*timer > 10)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(400, 1300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(100, 1500, 100, 100));
		}
	}
	else if (*timer > 0)
	{
		if (!flipped)
		{
			sprite->setTextureRect(sf::IntRect(500, 1300, 100, 100));
		}
		else
		{
			sprite->setTextureRect(sf::IntRect(0, 1500, 100, 100));
		}
	}
	else
	{
		*timer = 121;
	}
	(*timer)--;
}
