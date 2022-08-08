#include <iostream>
#include <windows.h>
#include "Grid.h"

#pragma once

namespace GUI
{
	class WinConsole
	{
	public:
		static void draw(Grid::Grid grid);
		static void gameoverScreen(int score);
		static void wait(int milliseconds);
	private:
		static void _clear();
	};
}
