#pragma once
#include <vector>
constexpr unsigned short	SCREEN_WIDTH = 1280;
constexpr unsigned short	SCREEN_HEIGHT = 720;
constexpr unsigned short	CELL_WIDTH = 69;
constexpr unsigned short	CELL_HEIGHT = 44;


//map cells
enum Cell {
	Empty,
	Wall,
	Edge,
	EdgeReversed,
	Ground,
	Door,
	Box,
	Coin
};
 
//enemy types
enum EnemyType {
	Mummy,
	SoulReaper
};

//defining a better looking data-structure for manipulating the map/level.
typedef std::vector<std::vector<Cell>>Map;

