#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP


#include <Ball.hpp>

#include "BricksRepository.hpp"
#include <memory>
#include <Paddle.hpp>

class LevelManager
{
    private:

        int _level;
        std::shared_ptr<BricksRepository> _bricksRepository;

    public:

        LevelManager(std::shared_ptr<BricksRepository> bricksRepository);
        ~LevelManager() = default;

        void ResetLevel(Ball &ball, Paddle &paddle);
        void IncreaseDifficulty(Ball &ball, Paddle &paddle);
        int getLevel() const;
        void NextLevel();
};



#endif //LEVELMANAGER_HPP
