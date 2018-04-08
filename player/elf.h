#ifndef ELF_H
#define ELF_H

#include "enemy.h"
class Grid;
class Player;
class Elf: public Enemy{
public:
	Elf(Grid *g):Enemy(g,140,10,30, 'E', "elf"){}
	void attackPlayer(Player *p) override;
};
#endif
