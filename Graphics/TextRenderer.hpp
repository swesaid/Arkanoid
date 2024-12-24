#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include <SDL2/SDL_ttf.h>
#include <GL/glew.h>
#include <memory>
#include <iostream>

class TextRenderer
{
private:
    std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> _font;

public:
    TextRenderer();
    ~TextRenderer() = default;

    bool Initialize();
    void RenderTextCentered(SDL_Renderer *& renderer,
                                      const std::string &text,
                                      int screenWidth, int screenHeight,
                                      SDL_Color textColor) const;
};

#endif // TEXTRENDERER_HPP
