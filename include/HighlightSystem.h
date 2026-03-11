#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Piece;

class HighlightSystem {
public:
    std::vector<sf::RectangleShape> highlights;

    void clear();
    void addLegalMoves(Piece* piece, const std::vector<Piece*>& allPieces);
    void draw(sf::RenderWindow& window);
};