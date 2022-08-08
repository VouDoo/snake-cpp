#include "Food.h"

namespace GameComponent
{
    Food::Food(Grid::CellPosition position)
    {
        this->position = position;
    }
    Grid::CellPosition Food::getPosition()
    {
        return position;
    }
    void Food::setPosition(Grid::CellPosition position)
    {
        this->position = position;
    }
    Grid::CellType Food::getCellType()
    {
        return cellType;
    }
}
