#pragma once

class TurnManager
{

	bool whiteTurn;

public:

	TurnManager();

	void switchTurn();

	bool isWhiteTurn();
};