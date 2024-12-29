#ifndef GAMELOOPMANAGER_HPP
#define GAMELOOPMANAGER_HPP

#include <memory>
#include <vector>

#include "Ball.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"
#include "GraphicsRenderer.hpp"
#include "BricksRepository.hpp"
#include "CollisionHandler.hpp"
#include "TextRenderer.hpp"
#include "GameResultManager.hpp"
#include "LevelManager.hpp"
#include "GraphicalPlayerInteraction.hpp"
#include "GameLoopManager.hpp"

class GameLoopManager {

    private:

        bool _shouldMoveToNextLevel = true;
        Ball _ball;
        Brick _brick;
        Paddle _paddle;
        GraphicsRenderer _graphicsRenderer;
        std::unique_ptr<CollisionHandler> _collisionHandler;
        std::shared_ptr<BricksRepository> _bricksRepository;
        std::shared_ptr<GameResultManager> _gameResultManager;
        std::shared_ptr<TextRenderer> _textRenderer;
        std::shared_ptr<LevelManager> _levelManager;
        std::shared_ptr<GraphicalPlayerInteraction> _graphicalPlayerInteraction;

    public:

    GameLoopManager(const Ball &ball,
                    const Brick &brick,
                    const Paddle &paddle,
                    const GraphicsRenderer &graphicsRenderer,
                    std::unique_ptr<CollisionHandler> collisionHandler,
                    std::shared_ptr<BricksRepository> bricksRepository,
                    std::shared_ptr<GameResultManager> gameResultManager,
                    std::shared_ptr<TextRenderer> textRenderer,
                    std::shared_ptr<LevelManager> levelManager,
                    std::shared_ptr<GraphicalPlayerInteraction> graphicalPlayerInteraction);

        ~GameLoopManager() = default;
        void Start(SDL_Renderer *& renderer, int screenWidth, int screenHeight);
        void RunLevel(SDL_Renderer *& renderer, int screenWidth, int screenHeight);

};

#endif
