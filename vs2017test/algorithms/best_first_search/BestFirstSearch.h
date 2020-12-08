#pragma once
#include "../../algorithms/SearchingMethod.h"
#include <queue>
#include "../../cell/cell_comparator/CellComparator.h"
#include "../../cell/cell_priority_queue/CellPriorityQueue.h"
#include "../../cell/cell_group/CellGroup.h"

using namespace std;

class BestFirstSearch : public SearchingMethod {

public:
	BestFirstSearch(Maze* maze);
	void visit(CellContainer* cellContainer) override;
	void checkNeighborsOf(CellContainer* cellContainer, Cell* current);
	void checkNeighbor(CellContainer* cellContainer, int row, int col, Cell* current) override;
	int calcCost(int row, int col);
	void setCost(Cell* c1);
	Cell* getSourceCell() override;
};