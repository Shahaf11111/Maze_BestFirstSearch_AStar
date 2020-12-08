#pragma once

#include <vector>
#include "../Cell.h"
#include "../../Constants.h"
#include "../cell_container/CellContainer.h"

/*A group of cells, all have unique coloring for graph searching algorithms:
source and target colors, gray for 'visited' mark, black for 'done' and path coloring for visualization.
This class wraps 'vector' class in order to simplify and make the API more abstract (to work with other types
of collections).*/

class CellGroup : public CellContainer {

private:
	std::vector <Cell*> cells;

public:
	CellGroup(int source, int target, int gray, int black, int path);
	bool doesBelongToTarget(int color);
	void clear() override;
	void add(Cell* cell) override;
	void add(int row, int col, Cell* parent) override;
	void addFirst(int row, int col, Cell* parent) override;
	void removeFirst() override;
	void removeLast() override;
	Cell* getFirst() override;
	Cell* getLast() override;
	bool empty() override;
	Cell* get(int index) override;
	int size() override;

};

