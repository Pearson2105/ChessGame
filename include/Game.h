#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "TurnManager.h"
#include "HighlightSystem.h"
#include "Timer.h"

class Game {
    Board           board;
    TurnManager     turn;
    HighlightSystem highlight;
    Timer           timer;

    Piece* selectedPiece = nullptr;
    bool    dragging = false;

public:
    Game();
    void handleInput(sf::RenderWindow& window, sf::Event& event);
    void update(float dt);
    void render(sf::RenderWindow& window);
};