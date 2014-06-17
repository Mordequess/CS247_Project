#ifndef DECK_H
#define DECK_H

#include <sstream>
#include "Card.h"

class Deck {
public:
	Deck();  					// Default constructor
	~Deck();					// Default Destructor

	Card* getArray(int) const;

	void shuffle();

private:
	Card* cards_[NUM_CARDS];
};

std::ostream &operator<<(std::ostream &, const Deck &);

#endif
