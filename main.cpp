#include "Game/Game.hpp"

int main(int argc, char *argv[]) 
{
    GameConfigurator gameConfigurator = GameConfigurator();
    GameConfigurationsCleaner configurationsCleaner = GameConfigurationsCleaner();
    BricksRepository bricksRepository = BricksRepository();
    Ball ball = Ball();
    Brick brick = Brick();

    Game game = Game(gameConfigurator, 
                     configurationsCleaner, 
                     bricksRepository,
                     ball,
                     brick);
    
    game.Run();
}