#include "../include/TurnManager.h"

TurnManager::TurnManager()
{
    whiteTurn = true;
}

void TurnManager::switchTurn()
{
    whiteTurn = !whiteTurn;
}

bool TurnManager::isWhiteTurn()
{
    return whiteTurn;
}