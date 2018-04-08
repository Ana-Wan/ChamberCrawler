#include "merchant.h"


Merchant::Merchant(Grid *g): Enemy(g,30,5,70, 'M', "merchant"){}
Merchant::~Merchant(){}
void Merchant::kill(Player *p){
	getGrid()->emptyCell(this->getPosition()->getX(), this->getPosition()->getY());
	Gold *gold = new MerchantGold("gold", false);
	getGrid()->getCell(this->getPosition())->setObj(gold);
}
