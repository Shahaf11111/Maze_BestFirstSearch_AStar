#include <vector>
#include <iostream>
#include "BFS.h"

BFS::BFS(Maze* maze) : SearchingMethod::SearchingMethod(maze) {
	this->source = new CellGroup(SOURCE, TARGET, SOURCE_GRAY, SOURCE_BLACK, SOURCE_PATH);
	this->source->add(this->getSourceCell());
}

void BFS::visit(CellContainer* cellGroup) {
	Cell* current;
	if (cellGroup->empty()) { // no more cells.... no solution
		std::cout << "No solution was found.\n";
		this->turnOff();
	}
	else {
		// take the first element, paint it black and add to visited cells the white neighbors
		current = cellGroup->getFirst();
		cellGroup->removeFirst(); // remove the front element
		// paint it black
		if (this->get(current) != cellGroup->getSourceColor()) {
			this->set(current, cellGroup->getBlackColor());
		}
		this->checkNeighborsOf(cellGroup, current);
	}
}

void BFS::checkNeighborsOf(CellContainer* cellGroup, Cell* current) {
	int currRow = current->getRow();
	int currCol = current->getCol();
	// look for white neighbors
	this->checkNeighbor(cellGroup, currRow + 1, currCol, current); // up
	if (this->isOn()) {
		this->checkNeighbor(cellGroup, currRow - 1, currCol, current); // down
	}
	if (this->isOn()) {
		this->checkNeighbor(cellGroup, currRow, currCol - 1, current); // left
	}
	if (this->isOn()) {
		this->checkNeighbor(cellGroup, currRow, currCol + 1, current); // right
	}
}