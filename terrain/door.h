#ifndef DOOR_H
#define DOOR_H
#include "cell.h"
class Subject;

class Door: public Cell{
        int x;
        int y;
        public:
        Door(int y, int x, char symb);
};
#endif
