#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include "Deck.h"
#include "Player.h"
#include "Played.h"

static const int NUM_PLAYERS = 4;


class Straights {
public:
	Straights(bool[] playerType);				// Straights Constructor
	~Straights();								// Default Destructor

	void nextRound();							// Function to create new round
	bool checkEnd() const;						// Check if game is over
	int getScore(int playerposition) const;		// get player score
	int getMinScore() const;					// get lowest player score
	void updateScores();						// update player scores
	int getFirstPlayer() const;					// Find player with 7S

	void playerTurn(int);						// call a players turn

	bool[][] getPlayedCards() const;			// return played_ array


private:
	Straights();
	Player* players_[NUM_PLAYERS]; 
	Deck deck_;
	Played* played_;
};

#endif
