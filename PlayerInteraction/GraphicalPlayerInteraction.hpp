#ifndef GRAPHICALPLAYERINTERACTION_HPP
#define GRAPHICALPLAYERINTERACTION_HPP

#include <string>

#include "TextRenderer.hpp"
#include "LevelManager.hpp"
#include "GameResult.hpp"

class GraphicalPlayerInteraction
{
    private:

        const int _screenWidth = 800;
        const int _screenHeight = 600;
        const SDL_Color _textColor = { 255, 255, 255, 255};
        std::shared_ptr<TextRenderer> _textRenderer;
        std::shared_ptr<LevelManager> _levelManager;

        void DisplayTextWithEventHandling(SDL_Renderer *&renderer, const std::string &message, int durationMs) const;

    public:

        GraphicalPlayerInteraction(std::shared_ptr<TextRenderer> textRenderer,
                                   std::shared_ptr<LevelManager> levelManager);

        ~GraphicalPlayerInteraction() = default;

        void ShowGameResult(SDL_Renderer *&renderer, const GameResult &result) const;
        void ShowCurrentLevel(SDL_Renderer *&renderer) const;
        void ShowCountdown(SDL_Renderer *&renderer) const;
        void ShowMessage(SDL_Renderer *&renderer, const std::string &message) const;
};



#endif //GRAPHICALPLAYERINTERACTION_HPP
