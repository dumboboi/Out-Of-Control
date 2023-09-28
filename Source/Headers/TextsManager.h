#pragma once
#include <SFML/Graphics.hpp>


class TextsManager
{
public:
	TextsManager();
	void drawText(sf::RenderWindow* window,sf::Text);
	void drawCountDown(sf::RenderWindow* window,std::string Text);


//variables
public:
	sf::Font font;
	sf::Text title;
	sf::Text CountDown;
	sf::Text GameOver;
};

