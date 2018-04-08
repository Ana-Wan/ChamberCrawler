#include "player.h"
#include <iostream>
using namespace std;

Player::Player(Grid *g,int hp, int def, int attack, std::string race): Character(g,hp, def, attack, '@', race){
	this->race = race;
	this->gold = 0;
	baseAtk = attack;
	baseDef = def;
}

Player::~Player() {}

int Player::getGold(){
	return this->gold;
}

void Player::changeGold(int change){
	this->gold += change;
}

void Player::kill(Player *p){
	p->isAlive = false;
	cout << "Game over" << endl;
}

void Player::setBaseAtk(int baseAtk){
	this->baseAtk = baseAtk;
}
void Player::reset(){
	this->att = baseAtk;
	this->def = baseDef;
}

int Player::getBaseAtk(){
	return this->baseAtk;
}

void Player::setBaseDef(int baseDef){
	this->baseDef = baseDef;
}

int Player::getBaseDef(){
	return this->baseDef;
}

string Player::getRace(){
	return this->race;
}

void Player::attack(Character* c){
	if(c==nullptr){
		cout<<c->getPosition()->getX()<<" "<<c->getPosition()->getY()<<endl;
		throw("Invalid move. No enemy exists to attack in specified direction");
	}
	else if(c->getSymb() == 'L' && (rand() % 2)){
		cout << "Player misses attack on Halfling" << endl;
		return;
	}
	else{
		if(c->getSymb() == 'M'){
			if(!this->hostile()){
				this->setHostile();
				cout << "Player attacked merchant. Merchant is now hostile" << endl;
			}
		}
		int damage = ceil((100.0/(100+ c->getDef())) * this->getAtt());
		c->changeHP(damage * -1);
		if(c->getHP() == 0 ){
			c->kill(this);
			cout << this->getRace() << " killed " << c->getRace() << endl;
			if(this->getRace() == "Goblin"){
				this->changeGold(5);
			}
		}
		cout << this->getRace() << " attacked " << c->getRace() << " leaving it with " << c->getHP() << " HP" << endl;
	}
}


void Player::move(std::string dir){
	int oldx = this->getPosition()->getX();
	int oldy = this->getPosition()->getY();
	int xoffset = 0;
	int yoffset = 0;
	if(dir == "no"){
		yoffset = -1;
	} else if (dir == "we"){
		xoffset = -1;
	} else if( dir == "so"){
		yoffset = 1;
	} else if (dir == "ea"){
		xoffset = 1;
	} else if (dir == "sw"){
		yoffset = 1;
		xoffset = -1;
	} else if (dir == "se"){
		yoffset = 1;
		xoffset = 1;
	} else if (dir == "nw"){
		yoffset = -1;
		xoffset = -1;
	} else if (dir == "ne"){
		yoffset = -1;
		xoffset = 1;
	}
	int newX = oldx + xoffset;
	int newY = oldy + yoffset;
	if((getGrid()->getSymb(newX, newY) == '.') || (getGrid()->getSymb(newX, newY) == '+') || (getGrid()->getSymb(newX, newY) == '#') ||
	   (getGrid()->getSymb(newX, newY) == '\\')){
		if (getGrid()->getSymb(newX, newY) == '\\'){
			getGrid()->resetGrid();
		} else {
			if(this->getRace() =="troll"){
				this->changeHP(5);
			}
			getGrid()->getCell(newX, newY)->setObj(this);
			getGrid()->emptyCell(oldx, oldy);
                }
	} 
	
}


void Player::pickUpPotion(Item *it, Cell * pos){
	if (it && ((it->getType() == "BA")) || (it->getType() == "WA") ||
		(it->getType() == "BD") || (it->getType() == "WD") ||
		(it->getType() == "RH") || (it->getType() == "PH")){
		it->useItem(this);
		getGrid()->emptyCell(it->getCell()->getX(), it->getCell()->getY());
	}
}
void Player::pickUpGold(Item *it, Cell *pos){
	it->useItem(this);
	getGrid()->emptyCell(it->getCell()->getX(), it->getCell()->getY());
}

