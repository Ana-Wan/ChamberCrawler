#ifndef PASSAGEWAY_H
#define PASSAGEWAY_H
#include "cell.h"
class Subject;

class PassageWay: public Cell{
	int x;
	int y;
	public:
	PassageWay(int y, int x, char symb);
};
#endif
