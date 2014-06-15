#ifndef DECK_H
#define DECK_H

#include <sstream>
#include "Card.h"

class Deck {
public:
	//Deck();
	Deck(int seed);
	~Deck();

	Card* getArray(int) const;
	void setArray(int, Card*);

	void shuffle();

private:
	void newDeck();
	Card* cards_[52];
	int seed_;
};

std::ostream &operator<<(std::ostream &, const Deck &);

#endif
