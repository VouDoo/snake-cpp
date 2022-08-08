#include <iostream>
#include <list>

namespace Grid
{
	Grid::Grid(unsigned short h, unsigned short w) { height = h; width = w; };
	unsigned short Grid::getHeight() { return height; }
	unsigned short Grid::getWidth() { return width; }
	void Grid::draw(std::list<GridItem> items)
	{
		// Initialize mapping
		int lenght = height * width;
		int* mapping = new int[lenght];
		for (size_t i = 0; i < lenght; i++)
			mapping[i] = ItemType::EMPTY;
		for (GridItem item : items)
		{
			int i = item.position.x + width * item.position.y;
			mapping[i] = item.type;
		}
		// Print to the console
		system("cls");
		for (size_t i = 0; i < lenght; i++)
		{
			switch (mapping[i])
			{
			case ItemType::EMPTY:
				std::cout << " ";
				break;
			case ItemType::SNAKE:
				std::cout << "#";
				break;
			case ItemType::FOOD:
				std::cout << "*";
				break;
			default:
				std::cout << "X";
				break;
			}
			if ((i + 1) % width == 0)
				std::cout << std::endl;
		}
	}
	Position Grid::adjacentPosition(Position bp, Direction d)
	{
		Position ap = bp; // Adjacent position
		switch (d)
		{
		case Direction::UP:
			if (bp.y != 0)
				ap.y -= 1;
			else
				ap.y = height - 1;
			break;
		case Direction::DOWN:
			if (bp.y != height - 1)
				ap.y += 1;
			else
				ap.y = 0;
			break;
		case Direction::LEFT:
			if (bp.x != 0)
				ap.x -= 1;
			else
				ap.x = width - 1;
			break;
		case Direction::RIGHT:
			if (bp.x != width - 1)
				ap.x += 1;
			else
				ap.x = 0;
			break;
		}
		return ap;
	}
}

