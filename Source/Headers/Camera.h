#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera();

	static void updateView(sf::View *view, sf::Vector2f playerPos, unsigned short Level,bool paused);
};
