#pragma once

#include "../Constants.h"
#include "../cell/Cell.h"

/*Represents the maze, made of paths and walls. It holds the source and target cells, to be passed to the 
searching method class.*/
class Maze {

private:
	int maze[MSZ][MSZ];
	Cell* sourceCell;
	Cell* targetCell;

public:
	Maze();
	void initPaths(); // Initiates the structure of the maze.
	void initSourceAndTargetCells(); // Initiates the source and target cells (target is chosen randomly).
	void setSourceCell();
	void setTargetCell();
	int get(int row, int col); // Gets the color of a single maze-cell.
	void set(int row, int col, int value); // Sets the color of a single maze-cell.
	Cell* getSourceCell();
	Cell* getTargetCell();


};