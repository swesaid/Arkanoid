#include "Game/Game.hpp"

int main(int argc, char *argv[]) 
{
    GameConfigurator gameConfigurator = GameConfigurator();

    Game game = Game(gameConfigurator);
    game.Run();
}