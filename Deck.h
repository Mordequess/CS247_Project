#ifndef DECK_H
#define DECK_H

#import "Card.h"

class Deck {
public:
	void shuffle();
private:
	Card*[] cards_;
};

#endif
