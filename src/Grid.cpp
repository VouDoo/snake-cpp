#include <list>
#include "Grid.h"
#include "Utility.h"

namespace Grid
{
	Grid::Grid(int width, int height)
	{
		this->width = width;
		this->height = height;
		for (int col = 0; col < height; col++)
			for (int row = 0; row < width; row++)
				cells.push_back(*new Cell(*new CellPosition(row, col)));
	}
	int Grid::getWidth()
	{
		return width;
	}
	int Grid::getHeight()
	{
		return height;
	}
	std::vector<Cell> Grid::getCells()
	{
		return cells;
	}
	CellPosition Grid::getCenterPosition()
	{
		return CellPosition{ abs(width / 2), abs(height / 2) };
	}
	CellPosition Grid::getRandEmptyPosition()
	{
		Cell* cell;
		int max = (int) cells.size() - 1;
		do
		{
			int rand = Utility::randInt(0, max);
			cell = &cells[rand];
		} while (cell->getType() != CellType::EMPTY);
		return cell->getPosition();
	}
	CellPosition Grid::getAdjacentPosition(CellPosition basePosition, Direction direction)
	{
		CellPosition adjacentPosition = basePosition;
		switch (direction)
		{
		case Direction::NORTH:
			if (basePosition.col != 0)
				adjacentPosition.col -= 1;
			else
				adjacentPosition.col = height - 1;
			break;
		case Direction::SOUTH:
			if (basePosition.col != height - 1)
				adjacentPosition.col += 1;
			else
				adjacentPosition.col = 0;
			break;
		case Direction::WEST:
			if (basePosition.row != 0)
				adjacentPosition.row -= 1;
			else
				adjacentPosition.row = width - 1;
			break;
		case Direction::EAST:
			if (basePosition.row != width - 1)
				adjacentPosition.row += 1;
			else
				adjacentPosition.row = 0;
			break;
		}
		return adjacentPosition;
	}
	void Grid::_updateType(CellPosition position, CellType type)
	{
		for (Cell& _cell : this->cells)
			if (_cell.getPosition() == position)
			{
				_cell.setType(type);
				break;
			}
	}
	void Grid::updateTypeSingle(CellPosition position, CellType type)
	{
		_updateType(position, type);
	}
	void Grid::updateTypeList(std::list<CellPosition> positions, CellType type)
	{
		for (CellPosition position : positions)
			_updateType(position, type);
	}
}
