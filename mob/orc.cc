#include "orc.h"

Orc::~Orc(){}
void Orc::attackPlayer(Player *p){
	if(p->getRace() == "goblin"){
		int halfAtk = this->getAtt() / 2;
		this->changeAtt(halfAtk);
		Enemy::attackPlayer(p);
		this->changeAtt(-halfAtk);
	}
	else{
		Enemy::attackPlayer(p);
	}
}
