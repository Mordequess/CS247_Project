#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
public:
	Deck();
	Deck(int seed);
	~Deck();
	
	void newDeck();
	void shuffle();

private:
	Card*[52] cards_;
};

#endif
