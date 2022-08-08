#include "Serpentine.h"

namespace GameComponent
{
	Serpentine::Serpentine(Grid::CellPosition initialPosition)
	{
		positions.push_back(initialPosition);
	}
	std::list<Grid::CellPosition> Serpentine::getPositions()
	{
		return positions;
	}
	Grid::CellPosition Serpentine::getHeadPosition()
	{
		return positions.back();
	}
	Grid::CellType Serpentine::getCellType()
	{
		return cellType;
	}
	void Serpentine::move(Grid::CellPosition nextPosition)
	{
		positions.pop_front();
		positions.push_back(nextPosition);
	}
	void Serpentine::moveAndGrow(Grid::CellPosition nextPosition)
	{
		positions.push_back(nextPosition);
	}
	bool Serpentine::hitItself(Grid::CellPosition nextPosition)
	{
		for (Grid::CellPosition const& position : positions)
			if (nextPosition == position)
				return true;
		return false;
	}
}
