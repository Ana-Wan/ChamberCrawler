#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H
#include "player.h"
#include "gold.h"
#include <utility>

class DragonGold: public Gold{
	public:
	DragonGold(std::string, bool status);
	void useItem(Player *p);
};
#endif

