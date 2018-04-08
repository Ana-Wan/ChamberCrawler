#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "grid.h"
#include <vector>
using namespace std;

Grid::Grid(){
	gen = new Generate();
}


Cell* Grid::getCell(Cell *dest){
	int x = dest->getX();
	int y = dest->getY();
	return theGrid[y][x];
}

void Grid::move(Cell *dest){
	p->setCell(dest);
}

void Grid::setPlayer (Player *p){
	this->p = p;
}

char Grid::getSymb(int x, int y){
	return theGrid[y][x]->getSymb();
}

void Grid::moveEnemies(){
	gen->enemyMove();
}

Cell * Grid::getCell(int x, int y){
	return theGrid[y][x];
}

void Grid::enemyTurn(Player *p){
	gen->enemiesTurn(p);
}
void Grid::emptyCell(int x, int y){
	emptyCell(theGrid[y][x]);
}
void Grid::canEnemyHit(Player *p){
	gen->enemyHit(p);
}
void Grid::gridInit(ifstream &filename){
	for(int i = 0; i < 5; ++i) {
		chamber.emplace_back(new Chamber());
	}
	string col;
	int r = 0; // current row we are in
	theGrid.resize(25);
	while (getline(filename, col)){
		vector <Cell *> rowCell;
		int columns = col.length(); // number of columns in grid
		Cell *cell; // to add cell to grid
		for(int c = 0; c < columns; ++c){
			if(col[c] == '|'){
				cell = new Wall{r,c, '|'};
			} else if (col[c] == '-') {
				cell = new Wall{r,c, '-'};
			} else if (col[c] == '#') {
				cell = new PassageWay{r,c, '#'};
			} else if (col[c] == '\\') {
				cell = new Stairway{r,c, '\\'};
			} else if (col[c] == '+') {
				cell = new Door{r,c,'+'};
			} else if (col[c] == '.'){
				cell = new Tile{r,c,'.'};

				if(r < 8){
					if(c < 30){
						chamber[0]->putCell(cell);
					} else {
						chamber[1]->putCell(cell); 
					}
				} else if (r < 14){
					if (c < 52){
						chamber[2]->putCell(cell);
					} else {
						chamber[1]->putCell(cell);
					}

				} else {
					if(c < 27){
						chamber[3]->putCell(cell);
					} else {
						chamber[4]->putCell(cell);
					}
				}
			} else {
				cell = new Cell{r,c, ' '}; // empty cell
				cell->setEmpty();
			}
		theGrid[r].emplace_back(cell);
		}
		++r;
		if(r == 25) break; // stops reading lines
	}
	
	generateGrid(); 

}

void Grid::resetGrid(){
	for(int r = 0; r < gridHeight; ++r){
		for(int c = 0; c < gridWidth; ++c){
			if(theGrid[r][c]->getSymb() == '@'){
				p->reset();  //reset player's attack and defense
			} else if( (theGrid[r][c]->getSymb() != '-') && (theGrid[r][c]->getSymb() != '|') &&
				(theGrid[r][c]->getSymb() != '+') && (theGrid[r][c]->getSymb() != '#') && 
				(theGrid[r][c]->getSymb() != ' ') && (theGrid[r][c]->getSymb() != '.')){
					theGrid[r][c] = nullptr; //deletes enemy cell
					theGrid[r][c] = new Tile{r,c, '.'}; // replace ennemy cell to a Dot cell
			}
		}
	}
	
	++level;
	generateGrid();
}

// generates the whole map except for the player
void Grid::generateGrid(){
	gen->generateStair(this);
	gen->generateEnemy(this);
	gen->generatePot(this);
}

Grid::~Grid(){
	delete gen;
	// delete chambers
	for(int i = 0; i < 5; ++i){
		delete chamber[i];
	}
	// delete cells in theGrid
	for(int r = 0; r < gridHeight; ++r){
		for(int c = 0; c < gridWidth; ++c){
			delete theGrid[r][c];
		}
	}
}

int Grid::getLevel(){
	return level;
}

ostream &operator<<(ostream &out, Grid &g){
	for(int r = 0; r < g.gridHeight; ++r){
		for(int c = 0; c < g.gridWidth; ++c){
			if((g.theGrid[r][c])->isEmpty()){
				out << " ";
			} else {
				out << g.theGrid[r][c]->getSymb();
			}
		}
		out<<endl;
	}
	return out;
}

void Grid::emptyCell(Cell *pos){
	pos->emptyCell(pos);
}
