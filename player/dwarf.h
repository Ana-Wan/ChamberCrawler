#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"
class Grid;

class Dwarf : public Enemy{
public:
	Dwarf(Grid *g);
};
#endif
