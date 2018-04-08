#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "player.h"

class Vampire: public Player{
	public:
	Vampire(Grid *g);
	void attack(Character *attackThis);
};
#endif

