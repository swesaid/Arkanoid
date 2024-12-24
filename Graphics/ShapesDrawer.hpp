#ifndef SHAPES_DRAWER_HPP
#define SHAPES_DRAWER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Brick.hpp"

class ShapesDrawer
{
    private:
        static const std::unordered_map<std::string, SDL_Color> _colors;

    public:
        ShapesDrawer() = delete;

        static void DrawRectangle(SDL_Renderer*& renderer, int x, int y, int width, int height, const std::string &colorName);
        static void DrawCircle(SDL_Renderer*& renderer, int centerX, int centerY, int radius, const std::string &colorName);
        static void DrawBricks(SDL_Renderer*& renderer, const std::vector <Brick> &bricks);

};


#endif