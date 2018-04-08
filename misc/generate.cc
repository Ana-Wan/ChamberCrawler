#include <iostream>
#include "generate.h"
#include "enemy.h"
#include <random>
#include "stairway.h"
#include "tile.h"
#include "wall.h"
#include "passageway.h"
#include "door.h"
#include "elf.h"
#include "halfing.h"
#include "human.h"
#include "dwarf.h"
#include "orc.h"
#include "merchant.h"
using namespace std;

Generate::Generate(){}

int Generate::randChamber(){
        return rand() % 5;
}

void Generate::enemiesTurn(Player *p){
	for (int k = 0; k < enemyVector.size(); k++){
	bool attacked = false;
	if (enemyVector[k] == nullptr){
		continue;
	}
	if (enemyVector[k]->getHP() == 0){
		delete enemyVector[k];
		enemyVector[k] = nullptr;
		break;
	}
	for (int i = -1; i < 2; i++){
                for (int j = -1; j < 2 ; j++){
                        int newX = enemyVector[k]->getPosition()->getX();
                        newX += j;
                        int newY = enemyVector[k]->getPosition()->getY();
                        newY+=i;
                        if (enemyVector[k]->getGrid()->theGrid[newY][newX]
			->getSymb() == '@'){
				enemyVector[k]->attackPlayer(p);
				attacked = true;
			}
		}
	}
	if (!attacked){
		enemyVector[k]->move();
	}
	
}
}	
void Generate::enemyHit(Player *p){
	for (int i = 0; i < enemyVector.size(); i++){
		enemyVector[i]->attackPlayer(p);
	}
}
void Generate::enemyMove(){
	for (int i = 0; i < enemyVector.size(); i++){
		enemyVector[i]->move();
	}
}
void Generate::generatePot(Grid *g){
	int num = 0; // number potions spawn
	
	// adds 10 random potion
	while(num < 10){
		Potion *p;
		int randomNum = rand() % 6 + 1;
		if (randomNum == 1){
			p = new Offence("BA", false);
		} else if (randomNum == 2){
			p = new Offence("WA", true);
		} else if (randomNum == 3){
			p = new Defense("BD", false);
		} else if (randomNum == 4){
			p = new Defense("WD", true);
		} else if (randomNum == 5){
			p = new Hp("RH", false);
		} else {
			p = new Hp("PH", true);
		}
		int n = randChamber();
		int x = 0;
		int y = 0;
		int z = getDot((g->chamber)[n], x, y);
		((g->chamber[n])->theCells[z]->setObj(p));
		(g->theGrid[y][x])->setObj(p);
		++num;
		}
}

void Generate::generateEnemy(Grid *g){
	int num = 0; 
	// spawns 20 enemy
	while(num < 20){
		Enemy *e;
		int randomEnemy = rand() % 18 + 1;
		// spawns Human
		if(randomEnemy <= 4){
			e = new Human{g};

		// spawns Dwarf
		} else if((randomEnemy > 4) && (randomEnemy <= 7)){
			e = new Dwarf{g};

		// spawns Elf
		} else if((randomEnemy > 7) && (randomEnemy <= 9)){
			e = new Elf{g};

		// spawns Orc
		} else if((randomEnemy > 9) && (randomEnemy <= 11)){
			e = new Orc{g};

		// spawns Merchant
		} else if((randomEnemy > 11) && (randomEnemy <= 13)){
			e = new Merchant{g};

		// spawns Halfling
		} else if(randomEnemy > 13){
			e = new Halfling{g};

		}
		int n = randChamber();
                int x = 0;
        	int y = 0;
                int z = getDot((g->chamber)[n], x, y);
                ((g->chamber[n])->theCells[z]->setObj(e));
                (g->theGrid[y][x])->setObj(e);
		enemyVector.push_back(e);
                ++num;	
	}
}

void Generate::generateStair(Grid *g){
	Stairway *s;	
	int n = randChamber();
	int x = 0;
	int y = 0;
	s = new Stairway(x, y, '\\');

	// get random position in chamber where there is a dot
	// sets the coordinate of the cell
	int z = getDot((g->chamber)[n], x, y);
	// put stair in chamber
	((g->chamber[n])->theCells[z])->setObj(s);
	//put stair in grid
	(g->theGrid[y][x])->setObj(s);
	// set hasStair to true
	(g->chamber[n])->setStair();
	
}

// kind of same as generateStair. will probably need a helper fn
void Generate::generatePlayer(Grid *g, Player *p){
	int n = randChamber();
	int x = 0;
	int y = 0;
	//finds a chamber that doesn't have a stair
	while((g->chamber[n])->getHasStair()){
		n = randChamber();
	}
	// get random position in chamber where there is a dot
	// sets the coordinate of the cell
	int z = getDot((g->chamber)[n], x, y);

	// put player in chamber
	((g->chamber[n])->theCells[z])->setObj(p);
	//put player in grid
	(g->theGrid[y][x])->setObj(p);
	g->setPlayer(p);

}

// return chamber num from 1 to 4

// return random position where to put item in chamber
int Generate::randPos(int size){
	return rand() % size;
}

int Generate::getDot(Chamber *c , int &x, int &y){
	int z = randPos(c->getSize());

	while((c->theCells[z])->getSymb() != '.')  {
		z = randPos(c->getSize());
	}

	x = (c->theCells[z])->getX();
	y = (c->theCells[z])->getY();

	return z;

}

Generate::~Generate(){
/*	for (int i = 0 ; i < enemyVector.size(); i++){
		delete enemyVector[i];
		enemyVector[i] = nullptr;
	}*/
}
