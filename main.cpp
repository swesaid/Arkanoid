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

    Game game = Game(gameConfigurator, 
                     configurationsCleaner,
                     graphicsRenderer, 
                     bricksRepository,
                     ball,
                     brick, 
                     paddle);
    
    game.Run();
}