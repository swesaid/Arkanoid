#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include "Ball.hpp"
#include "Paddle.hpp"

class LevelManager
{
    private:

        int _level;

    public:

        LevelManager();
        ~LevelManager() = default;

        void ResetLevel(Ball &ball, Paddle &paddle);
        void IncreaseDifficulty(Ball &ball, Paddle &paddle);
        int getLevel() const;
        void NextLevel();
};



#endif //LEVELMANAGER_HPP
