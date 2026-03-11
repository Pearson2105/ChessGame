#include "../include/HighlightSystem.h"
#include "../include/MoveValidator.h"

constexpr float TILE_SIZE = 100.f;
constexpr float BOARD_OFFSET_X = 100.f;
constexpr float BOARD_OFFSET_Y = 0.f;

void HighlightSystem::clear()
{
    highlights.clear();
}

void HighlightSystem::addLegalMoves(Piece* piece, const std::vector<Piece*>& allPieces)
{
    clear();
    if (!piece) return;

    sf::Color semiGreen(50, 205, 50, 140);

    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (MoveValidator::isValidMove(piece, x, y, allPieces))
            {
                sf::RectangleShape r;

                r.setSize({ TILE_SIZE, TILE_SIZE });

                r.setPosition(
                    BOARD_OFFSET_X + x * TILE_SIZE,
                    BOARD_OFFSET_Y + y * TILE_SIZE
                );

                r.setFillColor(semiGreen);

                highlights.push_back(r);
            }
        }
    }
}

void HighlightSystem::draw(sf::RenderWindow& window)
{
    for (auto& h : highlights)
        window.draw(h);
}