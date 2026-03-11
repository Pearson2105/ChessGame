#pragma once
#include <vector>
#include "Piece.h"

class MoveValidator {
public:
    static bool isValidMove(Piece* piece, int targetX, int targetY,
        const std::vector<Piece*>& allPieces);

    static bool squareOccupied(int x, int y, const std::vector<Piece*>& pieces);
    static Piece* getPieceAt(int x, int y, const std::vector<Piece*>& pieces);

    static bool isKingInCheck(bool whiteKing, const std::vector<Piece*>& pieces);

private:
    static bool isPathClear(int x1, int y1, int x2, int y2, const std::vector<Piece*>& pieces);
};