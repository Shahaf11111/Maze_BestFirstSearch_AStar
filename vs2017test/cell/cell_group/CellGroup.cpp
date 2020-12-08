#include "CellGroup.h"

CellGroup::CellGroup(int source, int target, int gray, int black, int path) :
	CellContainer::CellContainer(source, target, gray, black, path) {

}

bool CellGroup::doesBelongToTarget(int color) {
	return color != this->sourceColor && color != this->targetColor && color != this->grayColor &&
		color != this->blackColor && color != this->pathColor && color != WALL;
}

void CellGroup::clear() {
	this->cells.clear();
}

void CellGroup::add(Cell* cell) {
	this->cells.push_back(cell);
}

void CellGroup::add(int row, int col, Cell* parent) {
	this->cells.push_back(new Cell(row, col, parent));
}

void CellGroup::addFirst(int row, int col, Cell* parent) {
	this->cells.insert(this->cells.begin(),  new Cell(row, col, parent));
}

void CellGroup::removeFirst() {
	this->cells.erase(this->cells.begin()); // remove the front element
}

void CellGroup::removeLast() {
	this->cells.pop_back(); // remove the front element
}

Cell* CellGroup::get(int index) {
	return this->cells.at(index);
}

int CellGroup::size() {
	return this->cells.size();
}

Cell* CellGroup::getFirst() {
	return this->cells.front();
}

Cell* CellGroup::getLast()
{
	return this->cells.back();
}

bool CellGroup::empty() {
	return this->cells.empty();
}