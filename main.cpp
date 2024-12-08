#include "Game/Game.hpp"

int main(int argc, char *argv[]) 
{
    GameConfigurator gameConfigurator = GameConfigurator();
    GameConfigurationsCleaner configurationsCleaner = GameConfigurationsCleaner();
    BricksRepository bricksRepository = BricksRepository();

    Game game = Game(gameConfigurator, 
                     configurationsCleaner, 
                     bricksRepository);
    
    game.Run();
}