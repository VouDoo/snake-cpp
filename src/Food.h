#include "CellPosition.h"
#include "Cell.h"

#pragma once

namespace GameComponent
{
	class Food
	{
	public:
		Food(Grid::CellPosition position);
		Grid::CellPosition getPosition();
		void setPosition(Grid::CellPosition position);
		Grid::CellType getCellType();
	private:
		Grid::CellPosition position;
		Grid::CellType const cellType = Grid::CellType::FOOD;
	};
}
