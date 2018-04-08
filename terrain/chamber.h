#ifndef CHAMBER_H
#define CHAMBER_H
#include <iostream>
#include "cell.h"

class Chamber{
	int size; // size of theCells vector;
	bool hasStair;
	public:
	std::vector<Cell *> theCells;
	Chamber();
	int getSize();
	void setStair();
	bool getHasStair();
	void putCell(Cell *cell);
	~Chamber();

};
#endif

