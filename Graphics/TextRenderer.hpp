#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include <SDL2/SDL_ttf.h>
#include <iostream>

class TextRenderer
{
    private:
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> _font;

    public:
        TextRenderer();
        ~TextRenderer() = default;
        bool Initialize();
};

#endif //TEXTRENDERER_HPP
