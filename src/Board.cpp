#include "../include/Board.h"
#include <iostream>

constexpr int TILE_SIZE = 100;
constexpr int BOARD_SIZE = TILE_SIZE * 8;

Board::Board()
{
    if (!whiteSquareTexture.loadFromFile("resources/white_square.png"))
        std::cout << "Failed to load white square\n";

    if (!greenSquareTexture.loadFromFile("resources/green_square.png"))
        std::cout << "Failed to load green square\n";

    whiteSquare.setTexture(whiteSquareTexture);
    greenSquare.setTexture(greenSquareTexture);

    loadPieces();
}

Board::~Board()
{
    for (auto p : pieces)
        delete p;
}

void Board::loadPieces()
{
    for (int i = 0; i < 8; i++)
        pieces.push_back(new Piece(true, PAWN, i, 6));

    pieces.push_back(new Piece(true, ROOK, 0, 7));
    pieces.push_back(new Piece(true, ROOK, 7, 7));

    pieces.push_back(new Piece(true, KNIGHT, 1, 7));
    pieces.push_back(new Piece(true, KNIGHT, 6, 7));

    pieces.push_back(new Piece(true, BISHOP, 2, 7));
    pieces.push_back(new Piece(true, BISHOP, 5, 7));

    pieces.push_back(new Piece(true, QUEEN, 3, 7));
    pieces.push_back(new Piece(true, KING, 4, 7));

    for (int i = 0; i < 8; i++)
        pieces.push_back(new Piece(false, PAWN, i, 1));

    pieces.push_back(new Piece(false, ROOK, 0, 0));
    pieces.push_back(new Piece(false, ROOK, 7, 0));

    pieces.push_back(new Piece(false, KNIGHT, 1, 0));
    pieces.push_back(new Piece(false, KNIGHT, 6, 0));

    pieces.push_back(new Piece(false, BISHOP, 2, 0));
    pieces.push_back(new Piece(false, BISHOP, 5, 0));

    pieces.push_back(new Piece(false, QUEEN, 3, 0));
    pieces.push_back(new Piece(false, KING, 4, 0));
}

Piece* Board::getPieceAt(int x, int y)
{
    for (auto p : pieces)
        if (p->boardPos.x == x && p->boardPos.y == y)
            return p;

    return nullptr;
}

void Board::draw(sf::RenderWindow& window)
{
    int offsetX = (window.getSize().x - BOARD_SIZE) / 2;
    int offsetY = (window.getSize().y - BOARD_SIZE) / 2;

    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            sf::Sprite& square = ((x + y) % 2 == 0) ? whiteSquare : greenSquare;

            square.setPosition(
                offsetX + x * TILE_SIZE,
                offsetY + y * TILE_SIZE
            );

            window.draw(square);
        }
    }

    for (auto p : pieces)
        p->draw(window);
}