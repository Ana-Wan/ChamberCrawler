#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"
#include "merchantgold.h"
class Grid;
class Player;
class Human : public Enemy{
public:
	Human(Grid * g):Enemy(g,140,20,20, 'H', "human"){}
	virtual void kill(Player *p) override;
};
#endif
