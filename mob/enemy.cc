#include "enemy.h"
#include <iostream>
#include <cmath>
using namespace std;

Enemy::Enemy(Grid *g, int hp, int def, int atk, char symb, string race):Character(g,hp, def, atk, symb, race){}

Enemy::~Enemy(){}
void Enemy::attackPlayer(Player *p){
	if (this->getSymb() == 'M' && p->hostile() || this->getSymb() != 'M'){
	if(p && (rand() % 2)){
		int damage = ceil((100.0/(100+ p->getDef())) * this->getAtt());
                p->changeHP(damage*-1);
                cout << this->getSymb() << " attacked " << p->getRace() << " leaving it with " << p->getHP() << " HP" << endl;
         } else{
                cout<< this->getSymb() << " missed their attack" << endl;
         }
	if (p->getHP() == 0){
                p->isAlive = false;
        }
	}
}

void Enemy::kill(Player *p){
	getGrid()->emptyCell(this->getPosition());
	if(rand() % 2){
		p->changeGold(1);
	}
	else{
		p->changeGold(2);
	}
}

void Enemy::move(){
	int oldx;
	int oldy;
	int newX = this->getPosition()->getX();
	int newY = this->getPosition()->getY();
	oldx=newX;
	oldy=newY;
	while (getGrid()->getCell(newX, newY)->getSymb() != '.'){
		int xoffset = rand() % 3 - 1;
		int yoffset = rand() % 3 - 1;
		newX = oldx + xoffset;
		newY = oldy + yoffset;
	}
	getGrid()->emptyCell(oldx, oldy);
	getGrid()->theGrid[newY][newX]->setObj(this);	
	/*
	Cell *curr = this->getPosition();
	Cell *destCell = curr;
		while(getGrid()->getCell(destCell)->getSymb() != '.'){
			int xOffset = (rand() % 3) - 1;
			int yOffset = (rand() % 3) - 1;
			destCell->setX(xOffset);
			destCell->setY(yOffset);
		}
		getGrid()->getCell(destCell)->setObj(this);
		getGrid()->emptyCell(curr);*/
}

string Enemy::getRace(){
	return Character::getRace();
}

void Enemy::move(string dir){}


