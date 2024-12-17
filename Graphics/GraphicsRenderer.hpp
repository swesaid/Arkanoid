#ifndef GRAPHICSRENDERER_HPP
#define GRAPHICSRENDERER_HPP

#include "GraphicsRenderer.hpp"
#include "Objects/Paddle.hpp"
#include "Objects/Ball.hpp"
#include "Graphics/ShapesDrawer.hpp"
#include <SDL2/SDL.h>
#include <GL/glew.h>

class GraphicsRenderer
{
    public:
        GraphicsRenderer();
        ~GraphicsRenderer();
        void Render(Paddle paddle, Ball ball, const std::vector <Brick> &bricks);

};


#endif