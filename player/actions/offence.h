#ifndef OFFENCE_H
#define OFFENCE_H
#include <iostream>
#include <sstream>
#include <utility>
#include "player.h"
#include "potion.h"
class Offence: public Potion{
	public:
	Offence(std::string kind, bool status);
	void useItem(Player *p);
};

#endif
