#ifndef ORC_H
#define ORC_H

#include "enemy.h"
class Grid;
class Player;
class Orc: public Enemy{
	public:
	~Orc();
	Orc(Grid *g):Enemy(g,180,25, 30, 'O', "orc"){}
	void attackPlayer(Player *p) override;
};
#endif
