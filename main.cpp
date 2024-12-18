#include "Game/Game.hpp"

int main(int argc, char *argv[]) 
{
    GameConfigurator gameConfigurator = GameConfigurator();
    GameConfigurationsCleaner configurationsCleaner = GameConfigurationsCleaner();
    GraphicsRenderer graphicsRenderer = GraphicsRenderer();
    BricksRepository bricksRepository = BricksRepository();
    Ball ball = Ball();
    Brick brick = Brick();
    Paddle paddle = Paddle();
    CollisionHandler collisionHandler = CollisionHandler();
    GameLoopManager gameLoopManager = GameLoopManager(ball, brick, paddle, graphicsRenderer, bricksRepository, collisionHandler);

    Game game = Game(gameConfigurator, 
                     configurationsCleaner,
                     gameLoopManager);
    
    game.Run();
}