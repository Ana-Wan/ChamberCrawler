#include "dragonhoard.h"
#include <iostream>
using namespace std;

DragonGold::DragonGold(string kind, bool status): Gold{kind, status}{}

void DragonGold::useItem(Player *p){
	p->changeGold(6);
}
