#include "../include/MoveValidator.h"
#include <cmath>

bool MoveValidator::squareOccupied(int x, int y, const std::vector<Piece*>& pieces) {
    return getPieceAt(x, y, pieces) != nullptr;
}

Piece* MoveValidator::getPieceAt(int x, int y, const std::vector<Piece*>& pieces) {
    for (auto p : pieces)
        if (p->boardPos.x == x && p->boardPos.y == y)
            return p;
    return nullptr;
}

bool MoveValidator::isPathClear(int x1, int y1, int x2, int y2, const std::vector<Piece*>& pieces) {
    int dx = (x2 > x1) ? 1 : (x2 < x1) ? -1 : 0;
    int dy = (y2 > y1) ? 1 : (y2 < y1) ? -1 : 0;

    int x = x1 + dx;
    int y = y1 + dy;

    while (x != x2 || y != y2) {
        if (squareOccupied(x, y, pieces))
            return false;
        x += dx;
        y += dy;
    }
    return true;
}

bool MoveValidator::isValidMove(Piece* p, int tx, int ty, const std::vector<Piece*>& pieces) {
    if (tx < 0 || tx > 7 || ty < 0 || ty > 7) return false;

    int dx = tx - p->boardPos.x;
    int dy = ty - p->boardPos.y;

    Piece* target = getPieceAt(tx, ty, pieces);
    bool capture = target != nullptr;

    if (capture && target->white == p->white) return false; 

    switch (p->type) {
    case PAWN: {
        int dir = p->white ? -1 : 1;
        int startRow = p->white ? 6 : 1;

        if (dx == 0 && dy == dir && !squareOccupied(tx, ty, pieces))
            return true;

        if (dx == 0 && dy == 2 * dir && p->boardPos.y == startRow &&
            !squareOccupied(tx, ty, pieces) &&
            !squareOccupied(tx, p->boardPos.y + dir, pieces))
            return true;

        if (std::abs(dx) == 1 && dy == dir && capture)
            return true;

        return false;
    }

    case KNIGHT:
        return (std::abs(dx) == 2 && std::abs(dy) == 1) ||
            (std::abs(dx) == 1 && std::abs(dy) == 2);

    case KING:
        return std::max(std::abs(dx), std::abs(dy)) <= 1;

    case ROOK:
        if ((dx != 0 && dy != 0) || (dx == 0 && dy == 0)) return false;
        return isPathClear(p->boardPos.x, p->boardPos.y, tx, ty, pieces);

    case BISHOP:
        if (std::abs(dx) != std::abs(dy) || (dx == 0)) return false;
        return isPathClear(p->boardPos.x, p->boardPos.y, tx, ty, pieces);

    case QUEEN:
        if (dx == 0 || dy == 0 || std::abs(dx) == std::abs(dy))
            return isPathClear(p->boardPos.x, p->boardPos.y, tx, ty, pieces);
        return false;

    default:
        return false;
    }
}

bool MoveValidator::isKingInCheck(bool white, const std::vector<Piece*>& pieces) {
    Piece* king = nullptr;
    for (auto p : pieces)
        if (p->type == KING && p->white == white)
            king = p;

    if (!king) return false;

    for (auto p : pieces) {
        if (p->white != white) {
            if (isValidMove(p, king->boardPos.x, king->boardPos.y, pieces))
                return true;
        }
    }
    return false;
}