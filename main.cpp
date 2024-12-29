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
    auto textRenderer = std::make_shared<TextRenderer>();
    auto gameResultManager = std::make_shared<GameResultManager>();
    auto levelManager = std::make_shared<LevelManager>();
    auto graphicalPlayerInteraction = std::make_shared<GraphicalPlayerInteraction>(textRenderer, levelManager);

    auto gameLoopManager = std::make_unique<GameLoopManager>(ball, brick, paddle,
                                                             graphicsRenderer,
                                                             std::move(collisionHandler),
                                                             std::move(bricksRepository),
                                                             std::move(gameResultManager),
                                                             std::move(textRenderer),
                                                             std::move(levelManager),
                                                             std::move(graphicalPlayerInteraction));

    Game game = Game(gameConfigurator,
                     configurationsCleaner,
                     std::move(gameLoopManager));

    game.Run();
}