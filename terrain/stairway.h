#ifndef STAIRWAY_H
#define STAIRWAY_H
#include "cell.h"
class Subject;

class Stairway: public Cell{
	int x;
	int y;
	public:
	Stairway(int y, int x, char symb);
};
#endif
