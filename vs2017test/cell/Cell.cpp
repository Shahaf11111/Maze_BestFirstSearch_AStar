#include "Cell.h"

Cell::Cell(int r, int c, Cell* pc) {
	this->row = r;
	this->col = c;
	this->parent = pc;
}

int Cell::getRow()
{
	return this->row;
}

int Cell::getCol()
{
	return this->col;
}

Cell* Cell::getParent()
{
	return this->parent;
}

int Cell::getCost() {
	return this->cost;
}

void Cell::setCost(int cost) {
	this->cost = cost;
}