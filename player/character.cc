#include "character.h"
#include "coord.h"
#include <utility>
#include "subject.h"
#include <string>
#include <random>
#include "grid.h"
using namespace std;

Character::Character(Grid *g, int hp, int def, int attack, char symb, std::string race):
	Subject{g}, hP{hp}, def{def}, att{attack}, symb{symb}, race{race}{
	this->hitMerchant = false;
	maxHP = hp;
}

bool Character::hostile(){
	return this->hitMerchant;
}

void Character::setHP(int HP){
	this->hP = HP;
}
void Character::setHostile(){
	this->hitMerchant = true;
}
int Character::getAtt(){
	return this->att;
}
int Character::getDef(){
	return this->def;
}
int Character::getHP(){
	return this->hP;
}
void Character::changeHP(int HP){
	if (this->hP+HP > this->maxHP){
		this->hP = maxHP;
	} else if (this->hP +HP <= 0){
		this->hP = 0;
	} else {
	this->hP+=HP;
	}
}

void Character::changeAtt(int attackboost){
	this->att+=attackboost;
}

void Character::changeDef(int defboost){
	this->def+=defboost;
}
string Character::getRace(){
	return this->race;
}

int Character::getMaxHP(){
	return this->maxHP;
}

char Character::getSymb(){
	return this->symb;
}

Cell* Character::getPosition(){
	return currCell;
}

void Character::setCell(Cell * newCell){
	currCell = newCell;
}	

Character::~Character(){}	
