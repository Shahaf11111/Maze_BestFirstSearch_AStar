#pragma once
#include "../SearchingMethod.h"
#include "../../cell/cell_container/CellContainer.h"

class DFS :
    public SearchingMethod {

public:
    DFS(Maze* maze);
    void visit(CellContainer* cellContainer);
    void checkNeighborsOf(CellContainer* cellContainer, Cell* current); // Visits all cell neighbors
            // and paints them if necessary (gray = visited)

};

