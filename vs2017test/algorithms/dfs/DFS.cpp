#include "DFS.h"
#include "../../cell/cell_group/CellGroup.h"
#include <iostream>


DFS::DFS(Maze* maze) : SearchingMethod::SearchingMethod(maze) {
	this->source = new CellGroup(SOURCE, TARGET, SOURCE_GRAY, SOURCE_BLACK, SOURCE_PATH);
	this->source->add(this->getSourceCell()->getRow(), this->getSourceCell()->getCol(), nullptr);
}

void DFS::visit(CellContainer* cellGroup) {
	Cell* current;
	if (cellGroup->empty()) { // no more source.... no solution
		std::cout << "No solution was found.\n";
		this->turnOff();
	}
	else {
		// take the first element, paint it black and add to visited source the white neighbors
		current = cellGroup->getLast();
		cellGroup->removeLast(); // remove the last element
		// paint it black
		if (this->get(current) != cellGroup->getSourceColor()) {
			this->set(current, cellGroup->getBlackColor());
		}
		this->checkNeighborsOf(cellGroup, current);
	}
}

void DFS::checkNeighborsOf(CellContainer* cellGroup, Cell* current) {
	// check neighbors with random direction
	int choices[4] = { 0 };
	int direction;
	int count = 0;
	int currRow = current->getRow();
	int currCol = current->getCol();
	while (count < 4 && this->isOn()) {
		direction = rand() % 4;
		if (choices[direction] == 0) // only if we didn't check this direction before
		{
			count++;
			choices[direction] = 1;
			switch (direction)
			{
			case 0:	// up
				this->checkNeighbor(cellGroup, currRow + 1, currCol, current);
				break;
			case 1: // down
				this->checkNeighbor(cellGroup, currRow - 1, currCol, current);
				break;
			case 2: // left
				this->checkNeighbor(cellGroup, currRow, currCol - 1, current);
				break;
			case 3: // right
				this->checkNeighbor(cellGroup, currRow, currCol + 1, current);
				break;
			}
		}
	}
}