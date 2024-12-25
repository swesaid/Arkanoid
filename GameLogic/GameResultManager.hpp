#ifndef GAMERESULTMANAGER_HPP
#define GAMERESULTMANAGER_HPP

#include <string>

#include "TextRenderer.hpp"
#include "GameResult.hpp"

class GameResultManager
{
private:
    const int _screenWidth = 800;
    const int _screenHeight = 600;
    std::shared_ptr<TextRenderer> _textRenderer;

public:
    GameResultManager(std::shared_ptr<TextRenderer> textRenderer);
    ~GameResultManager() = default;
    void PrintResult(SDL_Renderer *&renderer, const std::string &message) const;
    GameResult GetResult(int bricksCount, float ballY) const;

};


#endif