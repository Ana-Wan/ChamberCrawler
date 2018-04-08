#include "gold.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

Gold::Gold(string kind, bool status): Item(kind, status){}

char Gold::getSymb(){
	return 'G';
}

void Gold::useItem(Player *p){}
