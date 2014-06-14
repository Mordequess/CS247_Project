#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
public:
	//Deck();
	Deck(int seed);
	~Deck();

	void shuffle();

private:
	void newDeck();
	Card*[52] cards_;
	int seed_;
};

std::ostream &operator<<(std::ostream &, const Deck &);

#endif
