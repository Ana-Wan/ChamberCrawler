#include "wall.h"
#include "subject.h"

Wall::Wall(int y, int x, char symb): Cell{y, x, symb}, x{x}, y{y}{}
