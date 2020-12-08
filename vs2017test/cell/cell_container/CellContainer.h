#pragma once
#include "../Cell.h"

class CellContainer
{
protected:
	int sourceColor;
	int grayColor;
	int blackColor;
	int targetColor;
	int pathColor;

public:
	CellContainer(int source, int target, int gray, int black, int path);
	virtual bool doesBelongToTarget(int color) = 0;
	virtual void clear() = 0;
	virtual void add(Cell* cell) = 0;
	virtual void add(int row, int col, Cell* parent) = 0;
	virtual void addFirst(int row, int col, Cell* parent);
	virtual void removeFirst() = 0;
	virtual void removeLast();
	virtual Cell* get(int index);
	virtual Cell* getFirst() = 0;
	virtual Cell* getLast();
	virtual bool empty() = 0;
	virtual int size() = 0;
	int getSourceColor();
	int getGrayColor();
	int getBlackColor();
	int getTargetColor();
	int getPathColor();


};