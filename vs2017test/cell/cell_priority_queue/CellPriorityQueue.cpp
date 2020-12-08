#include "CellPriorityQueue.h"
#include "../../Constants.h"


CellPriorityQueue::CellPriorityQueue(int source, int target, int gray, int black, int path)
	: CellContainer(source, target, gray, black, path)
{
}

bool CellPriorityQueue::doesBelongToTarget(int color) {
	return color == this->targetColor || color == SPACE;
	//return color != this->sourceColor && color != this->targetColor && color != this->grayColor &&
	//	color != this->blackColor && color != this->pathColor && color != WALL;
}

void CellPriorityQueue::clear() {
	while (!pq.empty()) {
		pq.pop();
	}
}

void CellPriorityQueue::add(Cell* cell)
{
	this->pq.push(cell);
}

void CellPriorityQueue::add(int row, int col, Cell* parent)
{
	Cell* cell = new Cell(row, col, parent);
	this->pq.push(cell);
}

Cell* CellPriorityQueue::getFirst()
{
	return this->pq.top();
}

void CellPriorityQueue::removeFirst()
{
	this->pq.pop();
}

bool CellPriorityQueue::empty()
{
	return this->pq.empty();
}

int CellPriorityQueue::size()
{
	return this->pq.size();
}


