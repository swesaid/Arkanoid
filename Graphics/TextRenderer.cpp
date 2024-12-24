#include "TextRenderer.hpp"

TextRenderer::TextRenderer() :
    _font(nullptr, TTF_CloseFont)
{}

bool TextRenderer::Initialize()
{
    std::string FontPath = "../Fonts/PressStart2P-Regular.ttf";
    int FontSize = 24;

    _font.reset(TTF_OpenFont(FontPath.c_str(), FontSize));
    if (_font == nullptr)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}




void TextRenderer::RenderTextCentered(SDL_Renderer *& renderer,
                                      const std::string &text,
                                      int screenWidth, int screenHeight,
                                      SDL_Color textColor) const
{
    if (_font == nullptr)
        return;

    SDL_Surface *surface = TTF_RenderText_Blended(_font.get(), text.c_str(), textColor);

    if (surface == nullptr)
    {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
    {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    int textWidth = surface->w;
    int textHeight = surface->h;
    SDL_FreeSurface(surface);

    SDL_Rect destRect;
    destRect.x = (screenWidth - textWidth) / 2;
    destRect.y = (screenHeight - textHeight) / 2;
    destRect.w = textWidth;
    destRect.h = textHeight;

    SDL_RenderCopy(renderer, texture, nullptr, &destRect);

    SDL_DestroyTexture(texture);
}
