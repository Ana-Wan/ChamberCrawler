#ifndef TILE_H
#define TILE_H
#include "cell.h"
class Subject;

class Tile:public Cell{
	int x;
	int y;
	public:
	Tile(int y, int x, char symb);
};
#endif
