#pragma once

class TurnManager
{

private:

    bool whiteTurn;

public:

    TurnManager();

    void switchTurn();

    bool isWhiteTurn();
};