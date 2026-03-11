#include "../include/Piece.h"
#include <iostream>

constexpr float TILE_SIZE = 100.f;
constexpr float BOARD_OFFSET_X = 100.f;
constexpr float BOARD_OFFSET_Y = 0.f;

std::map<std::string, sf::Texture> Piece::textures;

void Piece::loadTextures()
{
    std::string colors[2] = { "white", "black" };
    std::string types[6] = { "pawn", "rook", "knight", "bishop", "queen", "king" };

    for (auto& c : colors)
    {
        for (auto& t : types)
        {
            std::string key = c + "_" + t;
            std::string path = "resources/pieces/" + key + ".png";

            if (!textures[key].loadFromFile(path))
                std::cout << "Failed to load: " << path << "\n";
        }
    }
}

Piece::Piece(bool isWhite, PieceType t, int bx, int by)
    : white(isWhite), type(t), boardPos{ bx, by }
{
    std::string names[6] =
    {
        "pawn","rook","knight","bishop","queen","king"
    };

    std::string color = white ? "white" : "black";
    std::string key = color + "_" + names[type];

    sprite.setTexture(textures[key]);

    auto size = sprite.getTexture()->getSize();

    sprite.setOrigin(size.x / 2.f, size.y / 2.f);

    float scale = 90.f / size.x;
    sprite.setScale(scale, scale);

    setBoardPosition(bx, by);
}

void Piece::setBoardPosition(int bx, int by)
{
    boardPos = { bx, by };

    sprite.setPosition(
        BOARD_OFFSET_X + bx * TILE_SIZE + TILE_SIZE / 2,
        BOARD_OFFSET_Y + by * TILE_SIZE + TILE_SIZE / 2
    );
}

void Piece::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}