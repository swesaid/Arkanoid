#include "BricksRepository.hpp"

BricksRepository::BricksRepository() {};
BricksRepository::~BricksRepository() {};

void BricksRepository::CreateBricks()
{
    const int BrickWidth = 60;
    const int BrickHeight = 20;  
    const int NumberOfRows = 5;
    const int NumberOfColumns = 10;
    const float StartX = 50;
    const float StartY = 50;

    for (int row = 0; row < NumberOfRows; ++row)
        for (int col = 0; col < NumberOfColumns; ++col) 
        {
            Brick brick = {StartX + col * (BrickWidth + 10), StartY + row * (BrickHeight + 10), true};
            _bricks.push_back(brick);
        }
}   

std::vector<Brick> BricksRepository::getBricks() const
{
    return _bricks;
}

