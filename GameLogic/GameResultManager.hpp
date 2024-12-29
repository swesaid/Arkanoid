#ifndef GAMERESULTMANAGER_HPP
#define GAMERESULTMANAGER_HPP

#include "GameResult.hpp"

class GameResultManager
{
    private:

        const int _screenHeight = 600;

    public:

        GameResultManager();
        ~GameResultManager() = default;
        GameResult GetResult(int bricksCount, float ballY) const;
};


#endif