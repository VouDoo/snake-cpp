#pragma once

namespace Grid
{
	class CellPosition
	{
	public:
		CellPosition();
		CellPosition(int row, int col);
		int row, col;
		bool operator==(const CellPosition& position);
	};
}
