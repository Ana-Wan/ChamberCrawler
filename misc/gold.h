#ifndef GOLD_H
#define GOLD_H
#include "item.h"
#include <string>

class Gold: public Item{
	public:
		Gold(std::string kind, bool status);
		char getSymb() override;
		void useItem(Player *p);

};
#endif

