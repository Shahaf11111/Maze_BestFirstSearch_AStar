#include <stdlib.h>
#include "SearchingMethod.h"


SearchingMethod::SearchingMethod(Maze* maze) {
	this->maze = maze;
	this->on = true;
}

void SearchingMethod::iteration() {
	this->visit(this->source);
}

void SearchingMethod::checkNeighbor(CellContainer* cellContainer, int row, int col, Cell* current) {
	int cellColor = this->get(row, col);
	if (cellColor == cellContainer->getTargetColor()) {
		this->turnOff();
		this->restorePath(current, cellContainer->getPathColor());
	}
	else if (cellColor == SPACE) { // paint it gray
		this->set(row, col, cellContainer->getGrayColor());
		cellContainer->add(row, col, current);
	}
}

void SearchingMethod::restorePath(Cell* current, int pathColor)
{
	while (current->getParent() != nullptr) {
		this->set(current->getRow(), current->getCol(), pathColor);
		current = current->getParent();
	}
}

void SearchingMethod::clearCells() {
	this->source->clear();
	this->source->add(this->getSourceCell()->getRow(), this->getSourceCell()->getCol(), nullptr);
}

void SearchingMethod::clear() {
	int i, j;
	this->turnOff();
	this->clearCells();
	for (i = 1; i < MSZ - 1; i++) {
		for (j = 1; j < MSZ - 1; j++) {
			if (this->get(i, j) != SPACE && this->get(i, j) != WALL && this->get(i, j) != SOURCE
				&& this->get(i, j) != TARGET) {
				this->set(i, j, SPACE);
			}
		}
	}
}


int SearchingMethod::get(int row, int col) {
	return this->maze->get(row, col);
}

int SearchingMethod::get(Cell* cell) {
	return this->get(cell->getRow(), cell->getCol());
}

void SearchingMethod::set(int row, int col, int value) {
	this->maze->set(row, col, value);
}

void SearchingMethod::set(Cell* cell, int value) {
	this->set(cell->getRow(), cell->getCol(), value);
}

bool SearchingMethod::isOn() {
	return this->on;
}

void SearchingMethod::turnOn() {
	this->on = true;
}

void SearchingMethod::turnOff() {
	this->on = false;
}

Cell* SearchingMethod::getSourceCell() {
	return this->maze->getSourceCell();
}


Cell* SearchingMethod::getTargetCell() {
	return this->maze->getTargetCell();
}