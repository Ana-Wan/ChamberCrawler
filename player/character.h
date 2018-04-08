#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include <utility>
#include "subject.h"

class Grid;
class Cell;
class Player;
class Character: public Subject{
	int hP;
	int maxHP;
	char symb;
	std::string race;
	Cell *currCell;
public:
	int att;
	int def;
	bool hitMerchant;
	virtual void setHostile();
	virtual bool hostile();
	Character(Grid *g, int hp, int def, int att, char symb, std::string race); 
	virtual void kill(Player *p) = 0;
	virtual int getMaxHP();
	virtual int getAtt();
	virtual int getDef();
	virtual void move(std::string dir) = 0;
	virtual void changeHP(int HP);
	virtual void changeAtt(int attackboost);
	virtual void changeDef(int defboost);
	virtual int getHP();
	virtual void setHP(int HP);
	virtual std::string getRace() =0;
	virtual ~Character();
	void setCell(Cell * newCell);
	Cell * getPosition();
	char getSymb();
	
};
#endif
