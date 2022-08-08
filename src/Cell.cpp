#include "Cell.h"

namespace Grid
{
	Cell::Cell(CellPosition position)
	{
		this->position = position;
		this->type = CellType::EMPTY;
	}
	Cell::Cell(CellPosition position, CellType type)
	{
		this->position = position;
		this->type = type;
	}
	CellPosition Cell::getPosition()
	{
		return position;
	}
	int Cell::getRow()
	{
		return position.row;
	}
	int Cell::getCol()
	{
		return position.col;
	}
	CellType Cell::getType()
	{
		return type;
	}
	void Cell::setType(CellType type)
	{
		this->type = type;
	}
}
