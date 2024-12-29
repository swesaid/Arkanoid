#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP

#include "GameState.hpp"
#include "SDL2/SDL.h"

class GameStateManager
{
     private:
       GameState _currentState;

     public:
       GameStateManager();
       ~GameStateManager() = default;

       GameState &GetCurrentState();
       void HandleEvent(SDL_Keycode key);

};

#endif //GAMESTATEMANAGER_HPP
