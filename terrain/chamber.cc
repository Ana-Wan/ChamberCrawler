#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "chamber.h"

using namespace std;

Chamber::Chamber(){
	size = 0;
	hasStair = false;
}

void Chamber::setStair(){
	hasStair = true;
}

bool Chamber::getHasStair(){
	return hasStair;
}

void Chamber::putCell(Cell *cell){
	theCells.emplace_back(cell);
	++size;
}

int Chamber::getSize(){
	return size;
}

Chamber::~Chamber(){
	/*for(int i = 0; i < size; ++i){
		delete theCells[i]; // might cause double free(need to check)
		theCells[i] = nullptr;
	}*/
}
