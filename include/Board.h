#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"

class Board
{
public:
    std::vector<Piece*> pieces;

    Board();
    ~Board();

    Piece* getPieceAt(int x, int y);

    void draw(sf::RenderWindow& window);

private:
    sf::Texture whiteSquareTexture;
    sf::Texture greenSquareTexture;

    sf::Sprite whiteSquare;
    sf::Sprite greenSquare;

    void loadPieces();
};