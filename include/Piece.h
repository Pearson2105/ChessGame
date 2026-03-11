#pragma once
#include <SFML/Graphics.hpp>

class Piece
{

public:

    bool white;
    sf::Vector2i boardPos;

    sf::Texture texture;
    sf::Sprite sprite;

    Piece(bool white, std::string texturePath, int x, int y);

    void draw(sf::RenderWindow& window);
};