#include <list>
#include "CellPosition.h"
#include "Cell.h"

#pragma once

namespace GameComponent
{
	class Serpentine
	{
	public:
		Serpentine(Grid::CellPosition initialPosition);
		std::list<Grid::CellPosition> getPositions();
		Grid::CellPosition getHeadPosition();
		Grid::CellType getCellType();
		void move(Grid::CellPosition nextPosition);
		void moveAndGrow(Grid::CellPosition nextPosition);
		bool hitItself(Grid::CellPosition nextPosition);
	private:
		std::list<Grid::CellPosition> positions;
		Grid::CellType const cellType = Grid::CellType::SNAKE;
	};
}
