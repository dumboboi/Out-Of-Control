#include "Collision.h"
#include <Global.h>
#include <SFML/Graphics.hpp>

bool map_collision(float p_x, float p_y, Map *currenLevel, std::vector<Cell> cellsToCheck)
{
	//this function works this way :
	//checks the cells pek is intersecting with (top left/top right/ bottom left/bottom right) using cmath libary.
	//i store these cells in a temporary vector then checking if one of them cells in the map represents a well(blue cell).
	//if so the functions returns 1 means pek collided with a wall
	std::vector<Cell> temp;
	temp.push_back((*currenLevel)[floor(p_y / static_cast<float>(CELL_HEIGHT))][floor(p_x / static_cast<float>(CELL_WIDTH))]); //top left
	temp.push_back((*currenLevel)[floor(p_y / static_cast<float>(CELL_HEIGHT))][ceil(p_x / static_cast<float>(CELL_WIDTH))]); //top right
	temp.push_back((*currenLevel)[ceil(p_y / static_cast<float>(CELL_HEIGHT))][floor(p_x / static_cast<float>(CELL_WIDTH))]); //bottom left
	temp.push_back((*currenLevel)[ceil(p_y / static_cast<float>(CELL_HEIGHT))][ceil(p_x / static_cast<float>(CELL_WIDTH))]); //bottom right

	for (Cell &t : temp)
	{
		for (Cell &C : cellsToCheck)
		{
			if (t == C)
				return 1;
		}
	}
	return 0;

}

bool walls_collision(float p_x, float p_y, Map* currenLevel, std::vector<Cell> cellsToCheck, bool flipped)
{

	std::vector<Cell> temp;
	if (!flipped)
	{
		temp.push_back((*currenLevel)[floor(p_y / static_cast<float>(CELL_HEIGHT))][floor(p_x / static_cast<float>(CELL_WIDTH + 6))]); //top left
		temp.push_back((*currenLevel)[floor(p_y / static_cast<float>(CELL_HEIGHT))][ceil(p_x / static_cast<float>(CELL_WIDTH + 6))]); //top right
		temp.push_back((*currenLevel)[ceil(p_y / static_cast<float>(CELL_HEIGHT))][floor(p_x / static_cast<float>(CELL_WIDTH + 6))]); //bottom left
		temp.push_back((*currenLevel)[ceil(p_y / static_cast<float>(CELL_HEIGHT))][ceil(p_x / static_cast<float>(CELL_WIDTH + 6))]); //bottom right
	}
	else
	{
		temp.push_back((*currenLevel)[floor(p_y / static_cast<float>(CELL_HEIGHT))][floor(p_x / static_cast<float>(CELL_WIDTH-4))]); //top left
		temp.push_back((*currenLevel)[floor(p_y / static_cast<float>(CELL_HEIGHT))][ceil(p_x / static_cast<float>(CELL_WIDTH -4))]); //top right
		temp.push_back((*currenLevel)[ceil(p_y / static_cast<float>(CELL_HEIGHT))][floor(p_x / static_cast<float>(CELL_WIDTH -4))]); //bottom left
		temp.push_back((*currenLevel)[ceil(p_y / static_cast<float>(CELL_HEIGHT))][ceil(p_x / static_cast<float>(CELL_WIDTH -4))]); //bottom right
	}
	for (Cell& t : temp)
	{
		for (Cell& C : cellsToCheck)
		{
			if (t == C)
				return 1;
		}
	}
	return 0;

}

//calculating distance between 2 points
double distance(sf::Vector2f  a, sf::Vector2f b)
{
	double dx, dy;
	dx = a.x - b.x;
	dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

bool coinCollision(sf::FloatRect playerBounds, sf::FloatRect coinBounds)
{
	return playerBounds.intersects(coinBounds);
}
