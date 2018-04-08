#include <iostream>
#include "defense.h"
#include <string>

using namespace std;

Defense::Defense(string kind, bool status): Potion{kind, status}{}

void Defense::useItem(Player *p){
	//if potion is negative
	if(this->neg){
		p->changeDef(-5);
		cout<<"Player loses 5 defense"<<endl;
		if (p->getRace() == "drow"){
			p->changeDef(-3);
			cout<<"PLayer is drow: Loses 3 additional defense"<<endl;
		} 
	} else {
		p->changeDef(5);
		cout<<"Player gains 5 defense"<<endl;
		if (p->getRace() == "drow"){
			p->changeDef(3);
			cout<<"Player is drow: Gains 3 additional defense"<<endl;
		}
	}
}
