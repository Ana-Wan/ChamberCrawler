#ifndef WALL_H
#define WALL_H
#include "cell.h"
class Subject;

class Wall: public Cell{
	int x;
	int y;
	public:
	Wall(int y, int x, char symb);
};
#endif
