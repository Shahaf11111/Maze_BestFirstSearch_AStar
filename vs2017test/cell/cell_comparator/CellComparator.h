#pragma once
#include "../Cell.h"

class CellComparator {

public:
	int cost(Cell* cell);
	bool operator() (Cell* c1, Cell* c2);

};

