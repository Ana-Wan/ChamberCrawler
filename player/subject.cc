#include "subject.h"
#include "grid.h"

Subject::Subject(Grid *g): curGrid{g}{}
Grid * Subject::getGrid(){
	return curGrid;
}
