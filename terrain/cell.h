#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include "character.h"
#include "item.h"

class Stairway;
class Item;
class Character;
class Cell{
	int x;
	int y;
	char symbol;
	Character *c;
	Item *it;
	Stairway *s; 
	bool empty;
	public:
		char original;
		Cell(int y, int x, char symb);
		void setEmpty();
		void setObj(Character *c);
		void setObj(Item *it);
		void setObj(Stairway *s);
		bool isEmpty();
		void emptyCell(Cell *pos); 
		char getSymb();
		void setSymb(char ch);
		~Cell();
		virtual int getX();
		virtual int getY();
		void setX(int offset);
		void setY(int offset);
		Character *getChar();
		Item *getItem();		
		Stairway *getStairway();
};
#endif
