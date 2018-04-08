#include "human.h"

void Human::kill(Player *p){
	getGrid()->emptyCell(this->getPosition());
	getGrid()->getCell(this->getPosition())->setObj(new MerchantGold("gold", false));
}
