#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <cmath>

#include "ShapesDrawer.hpp"

const std::unordered_map<std::string, SDL_Color> ShapesDrawer::_colors =
{
    {"red", {255, 0, 0, 255}},
    {"green", {0, 255, 0, 255}},
    {"blue", {0, 76, 255, 255}},
    {"yellow", {255, 255, 0, 255}},
    {"black", {0, 0, 0, 255}},
    {"white", {255, 255, 255, 255}},
    {"gray", {128, 128, 128, 255}}
};


void ShapesDrawer::DrawRectangle(SDL_Renderer*& renderer, int x, int y, int width, int height, const std::string &colorName)
{
    auto it = _colors.find(colorName);
    if (it == _colors.end())
        throw std::invalid_argument("Invalid color");

    SDL_Color color = it->second;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);

}

void ShapesDrawer::DrawBricks(SDL_Renderer*& renderer, const std::vector <Brick> &bricks)
{
    const int BrickWidth = 60;
    const int BrickHeight = 20;

    for (const auto& brick : bricks)
    {
        if (brick.getState())
            DrawRectangle(renderer, static_cast<int>(brick.getX()), static_cast<int>(brick.getY()), BrickWidth, BrickHeight, "red");

    }
    
}

void ShapesDrawer::DrawCircle(SDL_Renderer*& renderer, int centerX, int centerY, int radius, const std::string &colorName)
{   
    auto it = _colors.find(colorName);
    if (it == _colors.end())
        throw std::invalid_argument("Invalid color");

    SDL_Color color = it->second;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // Horizontal offset
            int dy = radius - h; // Vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}


