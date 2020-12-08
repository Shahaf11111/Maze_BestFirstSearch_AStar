#pragma once

class Cell {

private:
	int row;
	int col;
	Cell* parent;
	int cost;

public:
	Cell(int r, int c, Cell* pc);
	int getRow();
	int getCol();
	Cell* getParent();
	int getCost();
	void setCost(int cost);

};