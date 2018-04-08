#ifndef DEFENSE_H
#define DEFENSE_H
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include "potion.h"
#include "player.h"
class Defense: public Potion{
	public:
	Defense(std::string type, bool status);
	void useItem(Player *p);
};
#endif

