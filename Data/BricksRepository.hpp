#ifndef BRICKSREPOSITORY_HPP
#define BRICKSREPOSITORY_HPP

#include <vector>
#include "Objects/Brick.hpp"

class BricksRepository
{
    private:
        std::vector<Brick> bricks;
    
    public:
        BricksRepository();
        ~BricksRepository();
        void CreateBricks(int numberOfRows, int numberOfColumns, int brickWidth, int brickHeight);
        std::vector<Brick> getBricks() const;
};

#endif