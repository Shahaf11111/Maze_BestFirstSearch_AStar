#include "AStar.h"

AStar::AStar(Maze* maze) : BestFirstSearch::BestFirstSearch(maze) {
}

void AStar::setCost(Cell* cell) {
	Cell* sourceCell = this->maze->getSourceCell();
	Cell* targetCell = this->maze->getTargetCell();
	int sourceRow = sourceCell->getRow();
	int sourceCol = sourceCell->getCol();
	int targetRow = targetCell->getRow();
	int targetCol = targetCell->getCol();
	cell->setCost(abs(sourceRow - cell->getRow()) + abs(sourceCol - cell->getCol()) +
		abs(targetRow - cell->getRow()) + abs(targetCol - cell->getCol()));
}

Cell* AStar::getSourceCell() {
	Cell* cell = this->maze->getSourceCell();
	this->setCost(cell);
	return cell;
}