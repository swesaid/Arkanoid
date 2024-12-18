#ifndef BRICKSREPOSITORY_HPP
#define BRICKSREPOSITORY_HPP

#include <vector>
#include "Objects/Brick.hpp"

class BricksRepository
{
    private:
        std::vector<Brick> _bricks;
    
    public:
        BricksRepository();
        ~BricksRepository();
        void CreateBricks();
        std::vector<Brick> getBricks() const;
};

#endif