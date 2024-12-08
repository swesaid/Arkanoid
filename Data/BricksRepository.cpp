#include "Data/BricksRepository.hpp"

BricksRepository::BricksRepository() {};
BricksRepository::~BricksRepository() {};

void BricksRepository::CreateBricks(const Brick &brick)
{
    float startX = 50;
    float startY = 50;

    for (int row = 0; row < brick.getRowsCount(); ++row) 
        for (int col = 0; col < brick.getColsCount(); ++col) 
        {
            Brick brick = {startX + col * (brick.getWidth() + 10), startY + row * (brick.getHeight() + 10), true};
            bricks.push_back(brick);
        }
}

std::vector<Brick> BricksRepository::getBricks() const
{
    return bricks;
}

