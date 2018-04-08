
#include "halfing.h"
using namespace std;
Halfling::~Halfling(){}
Halfling::Halfling(Grid *g):Enemy(g,100, 20,15, 'L', "halfling"){}
