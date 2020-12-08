#include "BestFirstSearch.h"
#include "../SearchingMethod.h"
#include "../../cell/cell_priority_queue/CellPriorityQueue.h"
#include <iostream>

BestFirstSearch::BestFirstSearch(Maze* maze) : SearchingMethod::SearchingMethod(maze) {
	this->source = new CellPriorityQueue(SOURCE, TARGET, SOURCE_GRAY, SOURCE_BLACK, SOURCE_PATH);
	this->source->add(this->getSourceCell());
}

int BestFirstSearch::calcCost(int row, int col) {
	Cell* targetCell = this->maze->getTargetCell();
	int targetRow = targetCell->getRow();
	int targetCol = targetCell->getCol();
	return abs(targetRow - row) + abs(targetCol - col);
}

void BestFirstSearch::setCost(Cell* cell) {
	Cell* targetCell = this->maze->getTargetCell();
	int targetRow = targetCell->getRow();
	int targetCol = targetCell->getCol();
	cell->setCost(abs(targetRow - cell->getRow()) + abs(targetCol- cell->getCol()));
}

Cell* BestFirstSearch::getSourceCell() {
	Cell* cell = this->maze->getSourceCell();
	this->setCost(cell);
	return cell;
}

void BestFirstSearch::visit(CellContainer* pq) {
	Cell* current;
	if (pq->empty()) { // there is no solution
		this->turnOff();
		std::cout << "There is no solution\n";
	}
	else {
		current = pq->getFirst();
		pq->removeFirst();
		if (this->get(current) == pq->getTargetColor()) // we have found the solution
		{
			this->turnOff();
			cout << "The solution has been found\n";
			//this->restorePath(current, pq->getPathColor());
		}
		else { // it is not target
			this->set(current, pq->getBlackColor());
			// look for the WHITE or GRAY or TARGET neighbors of current
			this->checkNeighborsOf(pq, current);
		}
	}
}

void BestFirstSearch::checkNeighborsOf(CellContainer* pq, Cell* current) {
	int currRow = current->getRow();
	int currCol = current->getCol();
	this->checkNeighbor(pq, currRow + 1, currCol, current);
	this->checkNeighbor(pq, currRow - 1, currCol, current);
	this->checkNeighbor(pq, currRow, currCol + 1, current);
	this->checkNeighbor(pq, currRow, currCol - 1, current);
}

void BestFirstSearch::checkNeighbor(CellContainer* cellContainer, int row, int col, Cell* current) {
	int cellColor = this->get(row, col);
	if (cellColor == cellContainer->getTargetColor()) {
		this->turnOff();
		this->restorePath(current, cellContainer->getPathColor());
	}
	else if (cellColor == SPACE) { // paint it gray
		Cell* neighborCell = new Cell(row, col, current);
		this->setCost(neighborCell);
		cellContainer->add(neighborCell);
		this->set(neighborCell, cellContainer->getGrayColor());

	}
}