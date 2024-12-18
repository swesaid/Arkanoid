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
    _configurationsCleaner.CleanUp(_window, _context);
}

void Game::Run()
 {
    if (!_gameConfigurator.IsConfigured(_window, _context, _screenWidth, _screenHeight)) 
    {
        std::cerr << "Failed to configure." << std::endl;
        _configurationsCleaner.CleanUp(_window, _context);
        return;
    }
    
    _gameLoopManager.Start(_screenWidth);
}