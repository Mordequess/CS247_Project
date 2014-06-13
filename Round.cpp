#include <iostream>
#include <vector.h>

#include "Deck.h"
#include "Card.h"
#include "Players.h"

	Round::Round(Player[]& p, Deck& d) : players_(p), deck_(d) {
		deck_.shuffle();
		for (int i = 0; i < 4; i++) {
			std::vector<Card> hand;
			for (int j = 0; j < 13; j++) {
				hand.push_back(deck_[j+i*13]);
			}
			players_[i].setHand(hand);
		played_ = new Played();
	}

	// Player[4] players_;
	// Deck deck_;
	// Played played_;
