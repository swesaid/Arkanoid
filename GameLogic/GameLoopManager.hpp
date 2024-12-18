#ifndef GAMELOOPMANAGER_HPP
#define GAMELOOPMANAGER_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Objects/Ball.hpp"
#include "Objects/Brick.hpp"
#include "Objects/Paddle.hpp"
#include "Graphics/GraphicsRenderer.hpp"
#include "Data/BricksRepository.hpp"

class GameLoopManager
{
    private:
        
        Ball _ball;
        Brick _brick;
        Paddle _paddle;
        GraphicsRenderer _graphicsRenderer;
        BricksRepository _bricksRepository;
    
    public:
        
        GameLoopManager(Ball ball,
                        Brick brick,
                        Paddle paddle,
                        GraphicsRenderer graphicsRenderer,
                        BricksRepository bricksRepository);
        
        ~GameLoopManager();
        void Start(int screenWidth);
};


#endif