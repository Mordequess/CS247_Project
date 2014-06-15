#ifndef PLAYED_H
#define PLAYED_H

#include <istream>
#include "Card.h"

struct Played{
	Played();
	void resetBoard();
	void setCard(Card card);
	bool isLegal(Card card);

	bool playedCards[4][13];
};





std::ostream &operator<<(std::ostream &, Played const &);

#endif
