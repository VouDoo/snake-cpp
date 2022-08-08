#include "WinConsole.h"

namespace GUI
{
	void WinConsole::draw(Grid::Grid grid)
	{
		int width = grid.getWidth();
		int i = 0;
		_clear();
		std::cout << '+' << std::string(width, '-') << '+' << std::endl;
		for (Grid::Cell cell : grid.getCells())
		{
			if (i % width == 0)
				std::cout << '|';
			switch (cell.getType())
			{
			case Grid::CellType::EMPTY:
				std::cout << ' ';
				break;
			case Grid::CellType::SNAKE:
				std::cout << '#';
				break;
			case Grid::CellType::FOOD:
				std::cout << '@';
				break;
			}
			if ((i + 1) % width == 0)
				std::cout << '|' << std::endl;
			i++;
		}
		std::cout << '+' << std::string(width, '-') << '+' << std::endl;
	}
	void WinConsole::gameoverScreen(int score)
	{
		_clear();
		std::cout << "### GAME OVER ###" << std::endl;
		std::cout << " Score: " << score << std::endl;
	}
	void WinConsole::wait(int ms)
	{
		Sleep(ms);
	}
	void WinConsole::_clear()
	{
		std::cout << "\033[2J\033[1;1H";
	}
}
