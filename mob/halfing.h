#ifndef HALFING_H
#define HALFING_H
#include "enemy.h"
class Grid;
class Halfling : public Enemy{
public:
	Halfling(Grid *g);
	~Halfling();
};
#endif
