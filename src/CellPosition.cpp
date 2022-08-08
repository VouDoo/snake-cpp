#include "CellPosition.h"

namespace Grid
{
	CellPosition::CellPosition()
	{
		row = 0;
		col = 0;
	}
	CellPosition::CellPosition(int row, int col)
	{
		this->row = row;
		this->col = col;
	}
	bool CellPosition::operator==(const CellPosition& other)
	{
		if (this->row == other.row &&
			this->col == other.col)
			return true;
		return false;
	}
}
