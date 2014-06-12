#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include "Card.h"
#include "Deck.h"
#include "Round.h"
#include "Player.h"

class Straights {
public:
	Straights();
	Straights(int seed);
	~Straights();

	newRound();
	void invitePlayers();
	void updateScores();
	void playedCards();
	void 

private:
	Player[4] players_;
	Deck deck_;
};

#endif
