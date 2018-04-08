#include "grid.h"
#include "enemy.h"
#include "character.h"
#include "shade.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "drow.h"
#include "generate.h"
#include "item.h"
#include "cell.h"
#include <string>
#include "player.h"

using namespace std;
int main(int argc, char *argv[]){
	start:
	Grid *g = new Grid();
	Generate *gen = new Generate();
	Player *player;
	if(argc ==2){
		ifstream filename {argv[1]};
		g->gridInit(filename);
		cout<<*g;
	 } else {
		string filename("map.txt");
		ifstream somefile(filename.c_str());
		g->gridInit(somefile);
		cout<<*g;
	} 
	
	char chosenRace;
	cout << "Please choose one of the following races:"<< endl;
	cout << "(S)hade" <<endl << "(D)row" << endl << "(V)ampire" << endl << "(G)oblin" << endl << "(T)roll" << endl;
	cout << "Press q to quit" <<endl;
 	while(cin >> chosenRace){
		if(chosenRace == 'q'){
			return 0;
		}
		else if(chosenRace == 's'){
			player = new Shade(g);
			break;
		}
		else if(chosenRace == 'd'){
			player = new Drow(g);
			break;
		}
		else if(chosenRace == 'v'){
			player = new Vampire(g);
			break;
		}
		else if(chosenRace == 'g'){
			player = new Goblin(g);
			break;
		}
		else if(chosenRace == 't'){
			player = new Troll(g);
			break;
		}
		else{
			cout << "Invalid input, please try again!"<<endl;
		}
	}
	cout << "Instructions" << endl;
	cout << "Move North = no" << endl;
	cout << "Move South = so" << endl;
	cout << "Move East = ea" << endl;
	cout << "Move West = we" << endl;
	cout << "Move North East = ne" << endl;
	cout << "Move North West = nw" << endl;
	cout << "Move South East = se" << endl;
	cout << "Move South West = sw" << endl;
	cout << "Attack = a" << endl;
	cout << "Use = u" << endl;
	cout << "Reset = r" << endl;
	cout << "Quit = q" << endl;
	gen->generatePlayer(g,player);
	cout << *g;
	cout << "Race: " << player->getRace() << " Gold: " << player->getGold()
	 << "            					 " << "floor "<< g->getLevel() << endl;
	cout<< "HP: " <<player->getHP() << endl;
	cout << "Atk:" << player->getAtt() << endl;
	cout << "Def:" << player->getDef() << endl;
	cout << "Action: Player character has spawned." << endl;

	bool use = false;
	bool attack = false;
	bool frozen = false;
	string command;
	while(cin >> command && player->isAlive){
		if(command == "f"){
			frozen = !frozen;
			continue;
		}
		else if(command == "q"){
			player->kill(player);
			cout<< "Quit! Your final score was: " << player->getGold() << endl;
			delete g;
			delete gen;
			return 0;
		}
		else if(command == "r"){
			delete g;
			delete gen;
			goto start;
		}
		else if(command == "u"){
			use = true;
			continue;
		}
		else if(command == "a"){
			attack = true;
			continue;
		}
		else if(command == "no" || command == "so" || command == "ea" || command == "we" || command == "ne" || command == "nw" || command == "se" || command == "sw"){
			if(attack){
				Cell * dest = player->getPosition();
				int newX = 0;
				int newY = 0;
				if(command ==" no"){
                                        newY-=1;
                                }
                                else if(command == "so"){
                                        newY+=1;
                                }
                                else if(command == "ea"){
                                        newY+=1;
                                }
                                else if(command == "we"){
                                        newX-=1;
                                }
                                else if(command == "ne"){
                                        newX+=1;
                                        newY-=1;
                                }
                                else if(command == "nw"){
                                        newY-=1;
                                        newX-=1;
                                }
                                else if(command == "se"){
                                        newY+=1;
                                        newX+=1;
                                }
                                else if(command == "sw"){
                                        newY+=1;
                                        newX-=1;
                                }
				int newX2 = dest->getX()+newX;
				int newY2 = dest->getY()+newY;
                                player->attack(g->theGrid[newY2][newX2]->getChar());
				g->enemyTurn(player);
                               	attack  = false;
			}
			else if(use){
				Cell *dest = player->getPosition();
				int xoffset = 0;
				int yoffset = 0;
				if(command =="no"){
					yoffset = -1;
				}
				else if(command == "so"){
					yoffset = 1;
				}
				else if(command == "ea"){
					xoffset = 1;
				}
				else if(command == "we"){
					xoffset = -1;
				}
				else if(command == "ne"){
					yoffset = -1;
					xoffset = 1;
				}
				else if(command == "nw"){
					yoffset = -1;
					xoffset = -1;
				}
				else if(command == "se"){
					yoffset = 1;
					xoffset = 1;
				}
				else if(command == "sw"){
					yoffset = 1;
					xoffset = -1;
				}
				int newY = dest->getY() + yoffset;
				int newX = dest->getX() + xoffset;
				Item *pickup = g->theGrid[newY][newX]->getItem();
				if (pickup->getType() == "gold"){
					player->pickUpGold(pickup, g->theGrid[newY][newX]);
					g->enemyTurn(player);
				} else{
					player->pickUpPotion(pickup,g->theGrid[newY][newX]);
					g->enemyTurn(player);
				}
				use = false;
			} else{
				player->move(command);
				g->enemyTurn(player);
			}
		cout<<*g;
		cout << "Race: " << player->getRace() << " Gold: " << player->getGold()
         << "                                                   " << "floor "<< g->getLevel() << endl;
        cout<< "HP: " <<player->getHP() << endl;
        cout << "Atk:" << player->getAtt() << endl;
        cout << "Def:" << player->getDef() << endl;
		}
		else if(!frozen){
			g->resetGrid();
		}
		else{
			cout << "Invalid input try again!" << endl;
			continue;
		}

	}
	cout << "Game over! Final Score: " << player->getGold() << endl;
	player->kill(player);
	string restart;
	cout << "Press p to play again or q to quit";
	while(cin >> restart){
		if(restart == "p"){
			delete g;
			delete gen;
			goto start;
		}
		else if(restart == "q"){
			delete g;
			delete gen;
			return 0;
		}
		else{
			cout << "Invalid input, try again!";
		}
	}
}
