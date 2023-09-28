#pragma once
#include <Global.h>
#include <SFML/Graphics.hpp>
bool map_collision(float p_x,float p_y,Map *currenLevel,std::vector<Cell> cellsToCheck);
bool walls_collision(float p_x,float p_y,Map *currenLevel,std::vector<Cell> cellsToCheck,bool flipped);
double distance(sf::Vector2f  a, sf::Vector2f b);

bool coinCollision(sf::FloatRect playerBounds, sf::FloatRect coinBounds);
