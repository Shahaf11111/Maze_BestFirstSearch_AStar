
#include "CellContainer.h"
#include <iostream>

CellContainer::CellContainer(int source, int target, int gray, int black, int path) {
	this->sourceColor = source;
	this->targetColor = target;
	this->grayColor = gray;
	this->blackColor = black;
	this->pathColor = path;
}

int CellContainer::getSourceColor()
{
	return this->sourceColor;
}

int CellContainer::getGrayColor()
{
	return this->grayColor;
}

int CellContainer::getBlackColor()
{
	return this->blackColor;
}

int CellContainer::getTargetColor()
{
	return this->targetColor;
}

int CellContainer::getPathColor()
{
	return this->pathColor;
}

void CellContainer::addFirst(int row, int col, Cell* parent)
{
	std::cout << "Yet implemented";
}

void CellContainer::removeLast()
{
	std::cout << "Yet implemented";
}

Cell* CellContainer::get(int index)
{
	std::cout << "Yet implemented";
	return nullptr;
}

Cell* CellContainer::getLast()
{
	std::cout << "Yet implemented";
	return nullptr;
}
