#include <iostream>
#include "offence.h"

using namespace std;

Offence::Offence(string kind, bool status): Potion{kind, status}{}

void Offence::useItem(Player *p){
        //if potion is negative
        if(this->neg){
                p->changeAtt(-5);
		cout<<"Player loses 5 attack"<<endl;
		if (p->getRace() == "drow"){
			p->changeAtt(-3);
			cout<<"Player is drow: loses 3 additional attack"<<endl;
		}
        } else {
                p->changeAtt(5);
		cout<<"Player gains 5 attack"<<endl;
		if (p->getRace() == "drow"){
			p->changeAtt(3);
			cout<<"Player is drow: gains 3 additional attack"<<endl;
		}
		
        }
}
