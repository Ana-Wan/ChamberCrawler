#ifndef NORMALGOLD_H
#define NORMALGOLD_H
#include "player.h"
#include "gold.h"
#include <utility>

class NormalGold: public Gold{
	public:
	NormalGold(std::string kind, bool status);
	void useItem(Player *p);
};
#endif

