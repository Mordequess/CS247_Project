#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
public:
	Deck();
	void shuffle();
	
private:
	Card*[] cards_;
};

#endif
