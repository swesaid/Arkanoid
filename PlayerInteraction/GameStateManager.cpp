#include "GameStateManager.hpp"

GameStateManager::GameStateManager() :
    _currentState(GameState::Running)
{}


GameState &GameStateManager::GetCurrentState()
{
    return _currentState;
}

void GameStateManager::HandleEvent(SDL_Keycode key)
{
    if (key == SDLK_p)
        _currentState = _currentState == GameState::Running ? GameState::Paused :
                                         GameState::Running;
}

