#pragma once
#include "../best_first_search/BestFirstSearch.h"

class AStar : public BestFirstSearch {

public:
	AStar(Maze* maze);
	void setCost(Cell* c1);
	Cell* getSourceCell() override;
};

