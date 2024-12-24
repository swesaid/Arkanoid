#ifndef GRAPHICSRENDERER_HPP
#define GRAPHICSRENDERER_HPP

#include <Brick.hpp>

#include "GraphicsRenderer.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "ShapesDrawer.hpp"
#include <SDL2/SDL.h>
#include <GL/glew.h>

class GraphicsRenderer
{
    public:
        GraphicsRenderer();
        ~GraphicsRenderer();
        void Render(SDL_Renderer *&renderer, Paddle &paddle, Ball &ball, const std::vector <Brick> &bricks);

};


#endif