#include "CellComparator.h"
#include <stdlib.h>

int CellComparator::cost(Cell* cell) {
	return cell->getCost();
}

bool CellComparator::operator() (Cell* c1, Cell* c2) {
	return this->cost(c1) > this->cost(c2);
}
