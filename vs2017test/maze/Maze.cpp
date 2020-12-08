#include <time.h>
#include <stdlib.h>
#include "Maze.h"

Maze::Maze() {
	this->initPaths();
	this->initSourceAndTargetCells();
}

void Maze::initPaths() {
	int i, j;
	// set margins
	for (i = 0; i < MSZ; i++) {
		this->maze[0][i] = WALL;
		this->maze[MSZ - 1][i] = WALL;
		this->maze[i][0] = WALL;
		this->maze[i][MSZ - 1] = WALL;
	}
	for (i = 1; i < MSZ - 1; i++) {
		for (j = 1; j < MSZ - 1; j++) {
			if (i % 2 == 1) { // this is mostly SPACE
				if (rand() % 100 < 10) { // 10% WALLs
					this->maze[i][j] = WALL;
				}
				else {
					this->maze[i][j] = SPACE;
				}
			}
			// this is mostly WALL
			else if (rand() % 100 < 40) { // 40% SPACEs
				this->maze[i][j] = SPACE;
			}
			else {
				this->maze[i][j] = WALL;
			}
		}
	}
}

void Maze::initSourceAndTargetCells() {
	this->setSourceCell();
	this->setTargetCell();
}

void Maze::setSourceCell() {
	this->set(SOURCE_X, SOURCE_Y, SOURCE);
	this->sourceCell = new Cell(SOURCE_X, SOURCE_Y, nullptr);
}

void Maze::setTargetCell() {
	int targetX = rand() % MSZ;
	int targetY = rand() % MSZ;
	while ((targetX == this->sourceCell->getRow() && targetY == this->sourceCell->getCol()) ||
		((this->targetCell != nullptr) &&
			(targetX == this->targetCell->getRow() && targetY == this->targetCell->getCol())) ||
		this->get(targetX, targetY) == WALL) {
		targetX = rand() % MSZ;
		targetY = rand() % MSZ;
	}
	if (this->targetCell != nullptr) {
		this->set(this->targetCell->getRow(), this->targetCell->getCol(), SPACE);
	}
	this->set(targetX, targetY, TARGET);
	this->targetCell = new Cell(targetX, targetY, nullptr);
}

int Maze::get(int row, int col) {
	return this->maze[row][col];
}

void Maze::set(int row, int col, int value) {
	this->maze[row][col] = value;
}

Cell* Maze::getSourceCell()
{
	return this->sourceCell;
}

Cell* Maze::getTargetCell()
{
	return this->targetCell;
}
