#include <iostream>
#include "potion.h"
#include "player.h"
#include <string>
using namespace std;

Potion::Potion(string kind, bool status): Item(kind, status){}

char Potion::getSymb(){
	return 'P';
}

void Potion::useItem(Player *p){}
