#include "Game.hpp"

Game::Game(GameConfigurator gameConfigurator, 
           GameConfigurationsCleaner configurationsCleaner,
           GameLoopManager gameLoopManager)
           
    :   _gameConfigurator(gameConfigurator),
        _configurationsCleaner(configurationsCleaner),
        _gameLoopManager(std::move(gameLoopManager))
{

}

Game::~Game() 
{
    _configurationsCleaner.CleanUp(window, context);
}

void Game::Run()
 {
    if (!_gameConfigurator.IsConfigured(window, context, SCREEN_WIDTH, SCREEN_HEIGHT)) 
    {
        std::cerr << "Failed to configure." << std::endl;
        _configurationsCleaner.CleanUp(window, context);
        return;
    }
    
    _gameLoopManager.Start(SCREEN_WIDTH);
}