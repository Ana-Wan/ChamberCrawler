#ifndef HP_H
#define HP_H
#include <iostream>
#include <sstream>
#include <utility>
#include "potion.h"
#include "player.h"
class Hp: public Potion{
	public:
	Hp(std::string kind, bool status);
	void useItem(Player *p);
};

#endif

