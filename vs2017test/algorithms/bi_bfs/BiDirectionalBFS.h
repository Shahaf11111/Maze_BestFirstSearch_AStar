#pragma once
#include "../bfs/BFS.h"

/*Responsible for bi-directional BFS*/

class BiDirectionalBFS : public BFS {
private:
	CellContainer* target;

public:
	BiDirectionalBFS(Maze* maze); // Initiates the search method
	void clearCells() override; // Clears painted cells
	void iteration() override; // Bi-BFS iteration (each BFS holds their latest visited cells, until they meet)
	void checkNeighbor(CellContainer* cellContainer, int row, int col, Cell* current) override; // Overrides BFS check 
			// neighbor to keep searching even if one BFS has made it to the end
	void checkIntersection(); // Finds 2 neighbor visited cells between source BFS and target BFS
	bool areCellsNeighbors(Cell* c1, Cell* c2); // Checks if 2 cells are neighbors
};

