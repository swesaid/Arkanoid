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
        void CreateBricks(const Brick &brick);
        std::vector<Brick> getBricks() const;
};

#endif