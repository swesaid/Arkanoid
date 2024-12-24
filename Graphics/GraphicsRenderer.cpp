#include "GraphicsRenderer.hpp"

GraphicsRenderer::GraphicsRenderer() {}
GraphicsRenderer::~GraphicsRenderer() {}

void GraphicsRenderer::Render(SDL_Renderer *&renderer, Paddle &paddle, Ball &ball, const std::vector <Brick> &bricks)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);

    ShapesDrawer::DrawRectangle(renderer, static_cast<int>(paddle.getX()), static_cast<int>(paddle.getY()), paddle.getWidth(), paddle.getHeight(), "blue");

    ShapesDrawer::DrawCircle(renderer, static_cast<int>(ball.getX() + ball.getSize() / 2), static_cast<int>(ball.getY() + ball.getSize() / 2), ball.getSize() / 2, "yellow");

    ShapesDrawer::DrawBricks(renderer, bricks);

    SDL_RenderPresent(renderer);
}