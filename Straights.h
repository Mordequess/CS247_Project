#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include "Deck.h"
#include "Player.h"
#include "Played.h"

class Straights {
public:
	Straights();						// Straights Constructor
	~Straights();						// Default Destructor

	void nextRound();					// Function to create new round
	bool checkEnd();
	int getScore(int playerposition);
	int getMinScore();
	void updateScores();
	int getFirstPlayer();

	void playerTurn(int);

private:
	Player* players_[NUM_PLAYERS];
	Deck deck_;
	Played* played_;
};

#endif
