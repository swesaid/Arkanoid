#include "TextRenderer.hpp"

TextRenderer::TextRenderer() :
     _font(nullptr, TTF_CloseFont)
{}

bool TextRenderer::Initialize()
{

    std::string FontPath = "../Fonts/PressStart2P-Regular.ttf";
    int FontSize = 12;

    _font.reset(TTF_OpenFont(FontPath.c_str(), FontSize));

    if(_font == nullptr)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}