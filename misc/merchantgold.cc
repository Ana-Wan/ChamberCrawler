#include "merchantgold.h"
#include <iostream>

using namespace std;

MerchantGold::MerchantGold(string kind, bool status): Gold{kind, status}{}

void MerchantGold::useItem(Player *p){
	p->changeGold(4);
}
