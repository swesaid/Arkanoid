#include "Data/BricksRepository.hpp"

BricksRepository::BricksRepository() {};
BricksRepository::~BricksRepository() {};

void BricksRepository::CreateBricks(int numberOfRows, int numberOfColumns, int brickWidth, int brickHeight)
{
    float startX = 50;
    float startY = 50;

    for (int row = 0; row < numberOfRows; ++row) 
        for (int col = 0; col < numberOfColumns; ++col) 
        {
            Brick brick = {startX + col * (brickWidth + 10), startY + row * (brickHeight + 10), true};
            bricks.push_back(brick);
        }
}

std::vector<Brick> BricksRepository::getBricks() const
{
    return bricks;
}

