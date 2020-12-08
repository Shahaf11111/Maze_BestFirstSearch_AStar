#pragma once

#include "../cell_container/CellContainer.h"
#include "../cell_comparator/CellComparator.h"
#include <vector>
#include <queue>

using namespace std;

class CellPriorityQueue : public CellContainer {

private:
	priority_queue<Cell*, std::vector<Cell*>, CellComparator> pq;

public:
	CellPriorityQueue(int source, int target, int gray, int black, int path);
	bool doesBelongToTarget(int color) override;
	void clear() override;
	void add(Cell* cell) override;
	void add(int row, int col, Cell* parent) override;
	Cell* getFirst() override;
	void removeFirst() override;
	bool empty() override;
	int size() override;

};

