#include "BiDirectionalBFS.h"
#include <iostream>

BiDirectionalBFS::BiDirectionalBFS(Maze* maze) : BFS::BFS(maze) {
	this->target = new CellGroup(TARGET, SOURCE, TARGET_BLACK, TARGET_GRAY, TARGET_PATH);
	this->target->add(this->getTargetCell()->getRow(), this->getTargetCell()->getCol(), nullptr);
}

void BiDirectionalBFS::clearCells() {
	SearchingMethod::clearCells();
	this->target->clear();
	this->target->add(this->getTargetCell()->getRow(), this->getTargetCell()->getCol(), nullptr);
}

void BiDirectionalBFS::iteration() {
	this->visit(this->source);
	this->visit(this->target);
	this->checkIntersection();
}

void BiDirectionalBFS::checkIntersection() {
	int i, j;
	for (i = 0; i < this->source->size(); i++) {
		for (j = 0; j < this->target->size(); j++) {
			Cell* c1 = this->source->get(i);
			Cell* c2 = this->target->get(j);
			if (this->areCellsNeighbors(c1, c2)) {
				this->turnOff();
				this->restorePath(c1, this->source->getPathColor());
				this->restorePath(c2, this->target->getPathColor());
				return; // Done looking for an intersection between source BFS and target BFS
			}
		}
	}
	/*
	for (Cell* c1 : this->source->getCells()) {
		for (Cell* c2 : this->target->getCells()) {
			if (this->areCellsNeighbors(c1, c2)) {
				this->turnOff();
				this->restorePath(c1, this->source->getPathColor());
				this->restorePath(c2, this->target->getPathColor());
				return; // Done looking for an intersection between source BFS and target BFS
			}
		}
	}
	*/
}

bool BiDirectionalBFS::areCellsNeighbors(Cell* cell1, Cell* cell2) {
	int r1 = cell1->getRow();
	int r2 = cell2->getRow();
	int c1 = cell1->getCol();
	int c2 = cell2->getCol();
	return (r1 == r2 && abs(c1 - c2) == 1) || (c1 == c2 && abs(r1 - r2) == 1);
}

void BiDirectionalBFS::checkNeighbor(CellContainer* cellGroup, int row, int col, Cell* current) {
	int cellColor = this->get(row, col);
	if (cellColor == cellGroup->getTargetColor()) {
		return;
	}
	if (cellGroup->doesBelongToTarget(cellColor)) { // paint it gray
		this->set(row, col, cellGroup->getGrayColor());
		cellGroup->add(row, col, current);
	}
}