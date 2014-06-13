#ifndef ROUND_H
#define ROUND_H

#include "Deck.h"
#include "Played.h"
#include "Players.h"

class Round {
public:
	Round(Player[]& players_, Deck& deck_);

	void printDeck();
	void printPlayedCards();
	void printPlayerHand();
	void printValidPlays();

	bool validPlay(Card);

private:
	Player[4] players_;
	Deck deck_;
	Played played_;
};

#endif	
