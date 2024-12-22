#ifndef SHAPES_DRAWER_HPP
#define SHAPES_DRAWER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Brick.hpp"

class ShapesDrawer
{
    public:
        ShapesDrawer() = delete;

        static void DrawRectangle(float x, float y, float width, float height);
        static void DrawCircle(float centerX, float centerY, float radius, int segments);
        static void DrawBricks(const std::vector <Brick> &bricks);

};


#endif