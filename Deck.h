#ifndef DECK_H
#define DECK_H

#include <sstream>
#include "Card.h"

class Deck {
public:
	Deck();  					// Default constructor
	~Deck();					// Default Destructor

	Card* getArray(int) const;	// TODO maybe implement
	void setArray(int, Card*);

	void shuffle();

private:
	Card* cards_[52];
};

std::ostream &operator<<(std::ostream &, const Deck &);

#endif
