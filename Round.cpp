#include <iostream>

#include "Deck.h"
#include "Players.h"

	Round::Round(Player[]& p, Deck& d) : players_(p), deck_(d) {
		deck_.shuffle();
		for (int i = 0; i < 4; i++) players_[i].***setHand(deck_ from i*13 to 13+i*13)
		played_ = new Played();
	}


	// Player[4] players_;
	// Deck deck_;
	// Played played_;
