#pragma once

#include "../maze/Maze.h"
#include "../cell/Cell.h"
#include "../cell/cell_container/CellContainer.h"

/*Abstract class that represents the basic features of a maze-searching algorithm. Contains the maze and a 
boolean that stricts weither the algorithm is currently taking action or not.*/
class SearchingMethod {

protected:
	bool on;
	Maze* maze;
	CellContainer* source;

public:
	SearchingMethod(Maze* maze);
	virtual void iteration();
	virtual void visit(CellContainer* cellContainer) = 0; // Single cell visit (checks its neighbors and being 
			// added / removed from source cell-group)
	virtual void checkNeighbor(CellContainer* cellGroup, int row, int col, Cell* current); // Visits single cell
	void restorePath(Cell* current, int pathColor); // Restores the shortest path found during BFS.
	virtual void clearCells(); // Clears the color from the painted cells.
	void clear(); // Clears the maze from the algorithm usage.
	int get(Cell* cell); // Wraps 'maze' class single cell getter.
	int get(int row, int col); // Wraps 'maze' class single cell getter.
	void set(Cell* cell, int value); // Wraps 'maze' class single cell setter.
	void set(int row, int col, int value); // Wraps 'maze' class single cell setter.
	virtual Cell* getSourceCell(); // Wraps 'maze' class source cell getter.
	Cell* getTargetCell(); // Wraps 'maze' class target cell getter.
	bool isOn(); // Returns current algorithm executing status.
	void turnOn(); // Indicates that the algorithm is being executed.
	void turnOff(); // Shuts down the algorithm work.

};