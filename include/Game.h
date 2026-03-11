#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "TurnManager.h"

class Game
{
private:

    Board board;
    TurnManager turn;

public:

    Game();

    void handleInput(sf::Event& event);
    void update();
    void render(sf::RenderWindow& window);
};