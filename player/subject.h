#ifndef SUBJECT_H
#define SUBJECT_H

class Cell;
class Grid;
class Character;


class Subject{
	Grid * curGrid;
	public:
		Subject(Grid *g);
		Grid *getGrid();
};
#endif
