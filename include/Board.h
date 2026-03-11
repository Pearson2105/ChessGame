#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"

class Board
{

private:

    sf::Texture boardTexture;
    sf::Sprite boardSprite;

public:

    std::vector<Piece*> pieces;

    Board();

    void draw(sf::RenderWindow& window);

    void setupPieces();
};