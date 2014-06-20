#ifndef PLAYED_H
#define PLAYED_H

#include <istream>
#include "Card.h"

struct Played{
	Played();
	void resetBoard();
	void setCard(Card card);
	bool isLegal(Card card) const;
	bool playedCards[NUM_SUITS][NUM_RANKS];
};

std::ostream &operator<<(std::ostream &, const Played &);

#endif
