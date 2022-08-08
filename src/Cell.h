#include "CellPosition.h"

#pragma once

namespace Grid
{
	enum CellType
	{
		EMPTY,
		SNAKE,
		FOOD,
	};
	class Cell
	{
	public:
		Cell(CellPosition position);
		Cell(CellPosition position, CellType type);
		CellPosition getPosition();
		int getRow();
		int getCol();
		CellType getType();
		void setType(CellType type);
	private:
		CellPosition position;
		CellType type;
	};
}
