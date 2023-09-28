#pragma once
#include <SFML/Graphics.hpp>

class HUD
{
public:
	HUD();

	void drawDPS(sf::RenderWindow* window, short dps, sf::Vector2f playerPos,unsigned short Level);


private:
	sf::Texture dpsTexture;
	sf::Sprite dpsSpr;
	sf::Font font;
	sf::Text dps;

};

