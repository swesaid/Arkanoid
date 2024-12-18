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
    if (!_gameConfigurator.InitializeSDL(window, context, SCREEN_WIDTH, SCREEN_HEIGHT)) 
    {
        std::cerr << "Failed to initialize SDL" << std::endl;
        return;
    }

    if (!_gameConfigurator.IntializeOpenGL(SCREEN_WIDTH, SCREEN_HEIGHT)) 
    {
        std::cerr << "Failed to initialize OpenGL" << std::endl;
        _configurationsCleaner.CleanUp(window, context);
        return;
    }
    _gameLoopManager.Start(SCREEN_WIDTH);
}