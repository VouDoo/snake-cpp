#include <vector>
#include <list>
#include "Cell.h"

#pragma once

namespace Grid
{
	enum Direction { NORTH, SOUTH, WEST, EAST };
	class Grid
	{
	public:
		Grid(int width, int height);
		int getWidth();
		int getHeight();
		std::vector<Cell> getCells();
		CellPosition getCenterPosition();
		CellPosition getRandEmptyPosition();
		CellPosition getAdjacentPosition(CellPosition basePosition, Direction direction);
		void updateTypeSingle(CellPosition position, CellType type);
		void updateTypeList(std::list<CellPosition> positions, CellType type);
	private:
		int width, height;
		std::vector<Cell> cells;
		void _updateType(CellPosition position, CellType type);
	};
}
