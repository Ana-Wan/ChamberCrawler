#include <iostream>
#include "item.h"
#include "player.h"

using namespace std;

Item::Item(string kind, bool status): whatKind{kind}, neg{status} {}

string Item::getType(){
	return this->whatKind;
}

bool Item::getStatus(){
	return this->neg;
}

Item::~Item(){
}

void Item::setCell (Cell *destCell){
	curCell = destCell;
}

Cell * Item::getCell(){
	return curCell;
}
