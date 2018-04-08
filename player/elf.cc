#include "elf.h"

void Elf::attackPlayer(Player *p){
	if(p->getRace() == "drow"){
		Enemy::attackPlayer(p);
	}
	else{
		Enemy::attackPlayer(p);
		Enemy::attackPlayer(p);
	}
}
