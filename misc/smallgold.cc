#include "smallgold.h"
#include <iostream>

using namespace std;

SmallGold::SmallGold(string kind, bool status): Gold{kind, status}{}

void SmallGold::useItem(Player *p){
	p->changeGold(1);
}
