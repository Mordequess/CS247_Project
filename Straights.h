#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include "Deck.h"
#include "Player.h"
#include "Played.h"

static const int NUM_PLAYERS = 4;


class Straights {
public:
	Straights();								// Straights Constructor
	Straights(bool[]);								// Straights Constructor
	~Straights();								// Default Destructor

	void nextRound();							// Function to create new round
	bool checkEnd() const;						// Check if game is over
	int getScore(int playerposition) const;		// get player score
	int getMinScore() const;					// get lowest player score
	void updateScores();						// update player scores
	void rageQuit(int playerposition);						// update player scores
	int getFirstPlayer() const;					// Find player with 7S

	void playerTurn(int);						// call a players turn

	Player* getPlayer(int playernum);
	Played* getPlayedCards();
	//bool checkRoundEnd() const;					// check if all hands are empty

private:
	//Straights();								// Straights Constructor
	Player* players_[NUM_PLAYERS]; 
	Deck deck_;
	Played* played_;
};

#endif
