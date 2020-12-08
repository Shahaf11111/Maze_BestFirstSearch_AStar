#pragma once
#include <vector>
#include "../SearchingMethod.h"
#include "../../cell/Cell.h"
#include "../../cell/cell_container/CellContainer.h"
#include "../../cell/cell_group/CellGroup.h"

class BFS : public SearchingMethod {

public:
	BFS(Maze* maze);
	void visit(CellContainer* cellContainer) override; // BFS iteration
	virtual void checkNeighborsOf(CellContainer* cellContainer, Cell* current); // Visits all cell neighbors
			// and paints them if necessary (gray = visited)

};