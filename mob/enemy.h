#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "grid.h"
#include "cell.h"
#include "item.h"
class Grid;

class Enemy : public Character{
public:
	Enemy(Grid *g, int hp, int def, int atk, char symb, std::string race);
	virtual void move();
	virtual void attackPlayer(Player *p);
	void kill(Player *p) override;
	virtual ~Enemy();
	void move(std::string dir) override;
	std::string getRace() override;
};

#endif
