#include "GameLogic.h"

void run()
{
	// Game configuration
	int tickMs = 100;
	int rowCount = 50;
	int colCount = 25;

	// Initialize random engine
	Utility::initRand();

	// Initialize variables, grid and game components
	boolean gameOver = false;
	int score = 0;
	Grid::Grid grid(rowCount, colCount);
	Grid::Direction direction = Grid::Direction::WEST;
	Grid::CellPosition nextPosition;
	GameComponent::Serpentine serpentine(grid.getCenterPosition());
	GameComponent::Food food(grid.getRandEmptyPosition());

	// Game loop
	while (!gameOver)
	{
		// Keyboard input
		switch (Controller::keyboardInput())
		{
		case Controller::IDLE:
			break;
		case Controller::UP:
			if (direction != Grid::Direction::SOUTH)
				direction = Grid::Direction::NORTH;
			break;
		case Controller::DOWN:
			if (direction != Grid::Direction::NORTH)
				direction = Grid::Direction::SOUTH;
			break;
		case Controller::LEFT:
			if (direction != Grid::Direction::EAST)
				direction = Grid::Direction::WEST;
			break;
		case Controller::RIGHT:
			if (direction != Grid::Direction::WEST)
				direction = Grid::Direction::EAST;
			break;
		}

		// Update grid and game components
		grid.updateTypeList(serpentine.getPositions(), Grid::CellType::EMPTY);
		nextPosition = grid.getAdjacentPosition(serpentine.getHeadPosition(), direction);
		if (nextPosition == food.getPosition())
		{
			serpentine.moveAndGrow(nextPosition);
			food.setPosition(grid.getRandEmptyPosition());
			score += 1;
		}
		else if (!serpentine.hitItself(nextPosition))
			serpentine.move(nextPosition);
		else
			gameOver = true;
		grid.updateTypeList(serpentine.getPositions(), serpentine.getCellType());
		grid.updateTypeSingle(food.getPosition(), food.getCellType());

		// Draw and wait
		GUI::WinConsole::draw(grid);
		GUI::WinConsole::wait(tickMs);
	}

	// Print Game Over
	GUI::WinConsole::gameoverScreen(score);
}
