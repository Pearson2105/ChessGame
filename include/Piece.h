#pragma once
#include <SFML/Graphics.hpp>
#include <map>

enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };

class Piece
{
private:
    static std::map<std::string, sf::Texture> textures;

public:
    bool white;
    PieceType type;
    sf::Vector2i boardPos;
    sf::Sprite sprite;

    static void loadTextures();

    Piece(bool isWhite, PieceType t, int bx, int by);

    void setBoardPosition(int bx, int by);
    void draw(sf::RenderWindow& window);
};