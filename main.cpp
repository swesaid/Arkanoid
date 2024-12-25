#include "Game/Game.hpp"


int main(int argc, char *argv[])
{
    auto gameConfigurator = std::make_shared<GameConfigurator>();
    auto configurationsCleaner = std::make_shared<GameConfigurationsCleaner>();
    auto bricksRepository = std::make_shared<BricksRepository>();

    auto ball = Ball();
    auto brick = Brick();
    auto paddle = Paddle();
    auto graphicsRenderer = GraphicsRenderer();
    auto collisionHandler = std::make_unique<CollisionHandler>();
    auto textRenderer = std::make_unique<TextRenderer>();
    auto gameResultManager = std::make_shared<GameResultManager>(std::move(textRenderer));
    auto gameLoopManager = std::make_unique<GameLoopManager>(ball, brick, paddle,
                                                             graphicsRenderer,
                                                             bricksRepository,
                                                             std::move(gameResultManager),
                                                             std::move(collisionHandler));

    Game game = Game(gameConfigurator,
                     configurationsCleaner,
                     std::move(gameLoopManager));

    game.Run();
}