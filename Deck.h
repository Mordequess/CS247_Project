#ifndef DECK_H
#define DECK_H

#include <sstream>
#include "Card.h"

class Deck {
public:
	Deck();
	~Deck();

	Card* getArray(int) const;
	void setArray(int, Card*);

	void shuffle();

private:
	void newDeck();
	Card* cards_[52];
};

std::ostream &operator<<(std::ostream &, const Deck &);

#endif
