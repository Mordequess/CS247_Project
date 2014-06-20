#ifndef DECK_H
#define DECK_H

#include <sstream>
#include "Card.h"

static const int NUM_CARDS = 52;

class Deck {
public:
	Deck();  											// Default constructor
	~Deck();											// Default Destructor
	Card* getCard(int) const;
	void shuffle();
private:
	Card* cards_[NUM_CARDS];							// Array of pointers to cards in the deck
};

std::ostream &operator<<(std::ostream &, const Deck &); // Custom stream operator to print deck

#endif
