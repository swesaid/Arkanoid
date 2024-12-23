#include "Game.hpp"

Game::Game(std::shared_ptr<GameConfigurator> gameConfigurator,
         std::shared_ptr<GameConfigurationsCleaner> configurationsCleaner,
         std::unique_ptr<GameLoopManager> gameLoopManager)
           
    :   _gameConfigurator(gameConfigurator),
        _configurationsCleaner(configurationsCleaner),
        _gameLoopManager(std::move(gameLoopManager))
{

}

Game::~Game() 
{
    _gameLoopManager.reset();
    _configurationsCleaner->CleanUp(_window, _context);
}

void Game::Run() const
 {
    if (!_gameConfigurator->IsConfigured(_window, _context, _screenWidth, _screenHeight))
    {
        std::cerr << "Failed to configure." << std::endl;
        _configurationsCleaner->CleanUp(_window, _context);
        return;
    }
    
    _gameLoopManager->Start(_screenWidth, _screenHeight);
}