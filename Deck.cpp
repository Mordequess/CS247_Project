#include <sstream>
#include <stdlib.h>
#include <iostream>
#include "Deck.h"

// Default constructor
Deck::Deck(){
	for (int j = 0; j < NUM_SUITS; j++) {
		for (int i = 0; i < NUM_RANKS; i++) {
			cards_[i + j*NUM_RANKS] = (new Card(static_cast<Suit>(j), static_cast<Rank>(i)));
		}
	}
}

// Destructor deletes card pointers
Deck::~Deck(){
	for (int i = 0; i < NUM_CARDS; i++) {
		delete cards_[i];
	}
}


// Returns array of cards
Card* Deck::getCard(int index) const {
	return cards_[index];
}


//shuffle deck using srand seed (default 0)
void Deck::shuffle(){
	int n = NUM_CARDS;
	while ( n > 1 ) {
		int k = (int) (lrand48() % n);
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	}
}

//prints deck in current order
std::ostream &operator<<(std::ostream& out, const Deck& d){
	for (int i = 0; i < NUM_SUITS; i++){
		for (int j = 0; j < NUM_RANKS; j++) {
			out << *d.getCard(j+i*NUM_RANKS) << " ";
		}
		out << std::endl;
		out << std::endl;
	}
	return out;
}
