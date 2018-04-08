#include "cell.h"
#include "stairway.h"
Cell::Cell(int y, int x, char symb): y{y}, x{x}, symbol{symb} {
	this->c = nullptr;
	this->it = nullptr;
	this->s = nullptr;
	empty = false;
	original = symb;
}

Cell::~Cell(){
	delete c;
	delete it;
	delete s;
}
void Cell::setObj(Character *c){
	this->c = c;
	this->setSymb(c->getSymb());
	c->setCell(this);
	empty = false;
}

void Cell::setEmpty(){
	this->empty = true;
}

void Cell::setObj(Item *it){
	this->it = it;
	this->setSymb(it->getSymb());
	it->setCell(this);
	empty = false;
}


void Cell::setObj(Stairway *s){
	this->s = s;
	this->setSymb(s->getSymb());
	empty = false;
}

bool Cell::isEmpty(){
	return this->empty;
}

int Cell::getY(){
	return this->y;
}

int Cell::getX(){
	return this->x;
}

void Cell::setSymb(char ch){
	this->symbol = ch;
}

void Cell::setX(int offset){
	this->x+=offset;
}

void Cell::setY(int offset){
	this->y+=offset;
}

char Cell::getSymb(){
	return this->symbol;
}

void Cell::emptyCell(Cell *pos){
	this->empty = false;
	c = nullptr;
	it = nullptr;
	s = nullptr;
	this->setSymb(original);
}

Character * Cell::getChar(){
	if (c){
		return c;
	} else {
		return nullptr;
	}
}

Item * Cell::getItem(){
	if (it){
		return it;
	} else {
		return nullptr;
	}
}

Stairway * Cell::getStairway(){
	if (s){
		return s;
	} else {
		return nullptr;
	}
}
