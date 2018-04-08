#include <string>
#include "vampire.h"
using namespace std;

Vampire::Vampire(Grid *g): Player(g, 50, 25, 25, "vampire"){}

void Vampire::attack(Character* attackThis){
	Player::attack(attackThis);
	if (attackThis->getRace() == "dwarf"){
		this->changeHP(-5);
	} else {
		this->changeHP(5);
	}
}
