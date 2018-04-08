#include <iostream>
#include "hp.h"
#include <string>

using namespace std;

Hp::Hp(string kind, bool status): Potion{kind, status}{}

void Hp::useItem(Player *p){
	//if potion is negative
	if(this->neg){
		p->changeHP(-10);
		cout<< "Player loses 10 HP"<<endl;
		if (p->getRace() == "drow"){
			p->changeHP(-5);
			cout<<"Player is drow: Loses 5 additional HP"<<endl;
		}
		cout<<p->getHP()<<endl;
	if (p->getHP() < 0){ p->changeHP(p->getHP() * -1);}
	} else {
		p->changeHP(10);
		cout<<"Player gains 10 HP"<<endl;
		if (p->getRace() == "drow"){
			p->changeHP(5);
			cout<<"Player is drow: Gains 5 addtional HP"<<endl;
		}
		if(p->getHP() > p->getMaxHP()){ p->setHP(p->getMaxHP());}
	}
}
