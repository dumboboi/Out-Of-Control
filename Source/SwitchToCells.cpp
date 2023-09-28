#include "SwitchToCells.h"


//this funtion switch a int map to the cell map

void SwitchVectToCells(std::vector<std::vector<unsigned short>>Level, Map* currentMap)
{
	for (unsigned short row = 0; row < Level.size(); row++)
	{
		for (unsigned short coll = 0; coll < Level[0].size(); coll++)
		{
			switch (Level[row][coll])
			{
				case 0:
				{
					(*currentMap)[row][coll] = Cell::Empty;
					break;
				}
				case 1:
				{
					(*currentMap)[row][coll] = Cell::Ground;
					break;
				}
				case 2:
				{
					(*currentMap)[row][coll] = Cell::Edge;
					break;
				}
				case 3:
				{
					(*currentMap)[row][coll] = Cell::Wall;
					break;
				}
				case 4:
				{
					(*currentMap)[row][coll] = Cell::EdgeReversed;
					break;
				}
				case 5:
				{
					(*currentMap)[row][coll] = Cell::Door;
					break;
				}
				case 6:
				{
					(*currentMap)[row][coll] = Cell::Box;
					break;
				}

				default:
					break;

			}
		}
	}
}