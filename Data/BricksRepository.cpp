#include "Data/BricksRepository.hpp"

BricksRepository::BricksRepository() {};
BricksRepository::~BricksRepository() {};

void BricksRepository::CreateBricks(const Brick &input)
{
    float startX = 50;
    float startY = 50;

    for (int row = 0; row < input.getRowsCount(); ++row) 
        for (int col = 0; col < input.getColsCount(); ++col) 
        {
            Brick brick = {startX + col * (input.getWidth() + 10), startY + row * (input.getHeight() + 10), true};
            _bricks.push_back(brick);
        }
}

std::vector<Brick> BricksRepository::getBricks() const
{
    return _bricks;
}

