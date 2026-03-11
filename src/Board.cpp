#include "../include/Board.h"

Board::Board()
{
    boardTexture.loadFromFile("../resources/board_8x8.png");
    boardSprite.setTexture(boardTexture);

    setupPieces();
}

void Board::setupPieces()
{
    for (int i = 0; i < 8; i++)
        pieces.push_back(new Piece(true, "../resources/w_pawn.png", i, 6));

    pieces.push_back(new Piece(true, "../resources/w_rook.png", 0, 7));
    pieces.push_back(new Piece(true, "../resources/w_rook.png", 7, 7));

    pieces.push_back(new Piece(true, "../resources/w_knight.png", 1, 7));
    pieces.push_back(new Piece(true, "../resources/w_knight.png", 6, 7));

    pieces.push_back(new Piece(true, "../resources/w_bishop.png", 2, 7));
    pieces.push_back(new Piece(true, "../resources/w_bishop.png", 5, 7));

    pieces.push_back(new Piece(true, "../resources/w_queen.png", 3, 7));

    pieces.push_back(new Piece(true, "../resources/w_king.png", 4, 7));


    for (int i = 0; i < 8; i++)
        pieces.push_back(new Piece(false, "../resources/b_pawn.png", i, 1));

    pieces.push_back(new Piece(false, "../resources/b_rook.png", 0, 0));
    pieces.push_back(new Piece(false, "../resources/b_rook.png", 7, 0));

    pieces.push_back(new Piece(false, "../resources/b_knight.png", 1, 0));
    pieces.push_back(new Piece(false, "../resources/b_knight.png", 6, 0));

    pieces.push_back(new Piece(false, "../resources/b_bishop.png", 2, 0));
    pieces.push_back(new Piece(false, "../resources/b_bishop.png", 5, 0));

    pieces.push_back(new Piece(false, "../resources/b_queen.png", 3, 0));

    pieces.push_back(new Piece(false, "../resources/b_king.png", 4, 0));
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(boardSprite);

    for (auto p : pieces)
        p->draw(window);
}