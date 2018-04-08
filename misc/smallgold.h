#ifndef SMALLGOLD_H
#define SMALLGOLD_H
#include "player.h"
#include "gold.h"
#include <utility>

class SmallGold: public Gold{
	public:
	SmallGold(std::string kind, bool status);
	void useItem(Player *p);
};
#endif

