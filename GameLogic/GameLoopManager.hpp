#ifndef GAMELOOPMANAGER_HPP
#define GAMELOOPMANAGER_HPP

#include <memory>

#include "Ball.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"
#include "GraphicsRenderer.hpp"
#include "BricksRepository.hpp"
#include "CollisionHandler.hpp"
#include "TextRenderer.hpp"

class GameLoopManager {
private:
    Ball _ball;
    Brick _brick;
    Paddle _paddle;
    GraphicsRenderer _graphicsRenderer;
    std::shared_ptr<BricksRepository> _bricksRepository;
    std::unique_ptr<CollisionHandler> _collisionHandler;
    std::unique_ptr<TextRenderer>_textRenderer;

public:
    GameLoopManager(const Ball& ball,
                    const Brick& brick,
                    const Paddle& paddle,
                    const GraphicsRenderer& graphicsRenderer,
                    std::shared_ptr<BricksRepository> bricksRepository,
                    std::unique_ptr<CollisionHandler> collisionHandler,
                    std::unique_ptr<TextRenderer>textRenderer);

    ~GameLoopManager() = default;
    void Start(SDL_Renderer *& renderer, int screenWidth, int screenHeight);
};

#endif
