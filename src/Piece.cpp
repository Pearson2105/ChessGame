#include "../include/Piece.h"
#include <iostream>

Piece::Piece(bool w, std::string path, int x, int y)
{
    white = w;
    boardPos = { x, y };

    if (!texture.loadFromFile(path))
    {
        std::cout << "ERROR loading: " << path << std::endl;
    }

    sprite.setTexture(texture);

    sprite.setPosition(x * 100.f, y * 100.f);

    if (texture.getSize().x > 0 && texture.getSize().y > 0)
    {
        sprite.setScale(
            100.f / texture.getSize().x,
            100.f / texture.getSize().y
        );
    }
}

void Piece::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}