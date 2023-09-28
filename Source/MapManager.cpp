#include "MapManager.h"
#include <SwitchToCells.h>
#include "Animation.h"
#include <Global.h>

Animation mapAnim;

MapManager::MapManager()
{

	mapsheet.loadFromFile("../assets/maptiles.png");
	coinsTexture.loadFromFile("../assets/spr_coin_strip4.png");
	coins.setTexture(coinsTexture);
	coins.setTextureRect(sf::IntRect(0, 0, 16, 16));
	cellspr.setTexture(mapsheet);
	
}

void MapManager::init(unsigned short Level)
{
	reset(Level);
	switch (Level)
	{
	case 1:
	{
		SwitchVectToCells(Level1, &currentLevel);
		break;
	}
	case 2:
	{
		SwitchVectToCells(Level2, &currentLevel);
		break;
	}
	case 3:
	{
		SwitchVectToCells(Level3, &currentLevel);
		break;
	}
	case 4:
	{
		SwitchVectToCells(Level4, &currentLevel);
		break;
	}
	default:
		break;
	}
	isUpdated = 0;
}

void MapManager::init_coins(unsigned short Level, float YLevel)
{

	switch (Level)
	{
		case 1:
		{
			break;
		}
		case 2: case 3:
		{
			for (unsigned short c = 0; c < 4; c++)
			{
				coinsVect.push_back(coins);
				sf::Vector2f tempPos;
				tempPos.x = (float)(rand() % SCREEN_WIDTH);
				tempPos.y = YLevel;
				coinsVect[coinsVect.size() - 1].setPosition(tempPos);
			}
			break;
		}
		default:
			break;

	}
}


void MapManager::draw(sf::RenderWindow *window)
{
	for (unsigned short row = 0; row < currentLevel.size(); row++)
	{
		for (unsigned short coll = 0; coll < currentLevel[0].size(); coll++)
		{
			cellspr.setPosition(coll * CELL_WIDTH, row * CELL_HEIGHT);
			coins.setPosition(coll * CELL_WIDTH, row * CELL_HEIGHT);
			switch (currentLevel[row][coll])
			{
				case Cell::Empty:
				{
					break;
				}
				case Cell::Ground:
				{
					cellspr.setTextureRect(sf::IntRect(CELL_WIDTH,0, CELL_WIDTH,CELL_HEIGHT));
					window->draw(cellspr);
					break;
				}
				case Cell::Edge:
				{
					cellspr.setTextureRect(sf::IntRect(0, 0, CELL_WIDTH, CELL_HEIGHT ));
					window->draw(cellspr);
					break;
				}
				case Cell::EdgeReversed:
				{
					cellspr.setTextureRect(sf::IntRect(CELL_WIDTH*3, 0, CELL_WIDTH , CELL_HEIGHT ));
					window->draw(cellspr);
					break;
				}
				case Cell::Wall:
				{
					cellspr.setTextureRect(sf::IntRect(CELL_WIDTH*2, 0, CELL_WIDTH, CELL_HEIGHT ));
					window->draw(cellspr);
					break;
				}
				case Cell::Door:
				{
					cellspr.setTextureRect(sf::IntRect(0, CELL_HEIGHT , CELL_WIDTH, CELL_HEIGHT * 2));
					window->draw(cellspr);
					break;
				}
				case Cell::Box:
				{
					cellspr.setTextureRect(sf::IntRect(CELL_WIDTH*4, 0, CELL_WIDTH, CELL_HEIGHT*2));
					window->draw(cellspr);
					break;
				}
				case Cell::Coin:
				{
					mapAnim.coinFlip(&coins);
					window->draw(coins);
					break;
				}
			}
		}

	}
	for (auto& c : coinsVect)
	{
		mapAnim.coinFlip(&c);
		window->draw(c);
	}


}

void MapManager::update(unsigned short Level)
{
	switch (Level)
	{
		case 1:
		{
			currentLevel[12][13] = Cell::Ground;
			isUpdated = 1;
			for (unsigned short c = 0; c < 5; c++)
			{
				coinsVect.push_back(coins);
			}
			coinsVect[0].setPosition(CELL_WIDTH * 10, CELL_HEIGHT * 11);
			coinsVect[1].setPosition(CELL_WIDTH * 10 - 32, CELL_HEIGHT * 10);
			coinsVect[2].setPosition(CELL_WIDTH * 5 - 60, CELL_HEIGHT * 11 + 24);
			coinsVect[3].setPosition(CELL_WIDTH * 5 - 40, CELL_HEIGHT * 11 + 24);
			coinsVect[4].setPosition((CELL_WIDTH * 5) - 20, CELL_HEIGHT * 11 + 24);
			break;
		}
		case 2:
		{
			currentLevel[9][16] = Cell::Door;
			init_coins(Level, 550);
			isUpdated = 1;
			break;
		}
		case 3:
		{
			currentLevel[11][17] = Cell::Door;
			init_coins(Level, CELL_HEIGHT * 3);
			init_coins(Level, CELL_HEIGHT * 6);
			init_coins(Level, CELL_HEIGHT * 9);
			init_coins(Level, CELL_HEIGHT * 12);
			isUpdated = 1;
			break;
			//CELL_WIDTH * 4, CELL_HEIGHT * 12
		}
		default:
			break;
	}


}

void MapManager::reset(unsigned short Level)
{
	for (unsigned short row = 0; row < Level1.size(); row++)
	{
		std::vector<Cell> tempvect;
		for (unsigned short coll = 0; coll < Level3[0].size(); coll++)
		{
			tempvect.push_back(Cell::Empty);
		}
		currentLevel.push_back(tempvect);
	}
	isUpdated = 0;
	switch (Level)
	{
	case 1:
	{
		currentLevel[12][13] = Cell::Empty;

		break;
	}
	case 2:
	{
		currentLevel[9][16] = Cell::Empty;
		isUpdated = 1;

		break;
	}
	default:
		break;
	}
	coinsVect.clear();
}
Map* MapManager::getMap()
{
	return &currentLevel;
}

bool MapManager::updated()
{
	return isUpdated;
}