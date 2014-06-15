#include <sstream>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"


Deck::Deck() : seed_(0) {
	newDeck();
}

Deck::~Deck(){}

Deck::Deck(int seed) : seed_(seed) {
	newDeck();
}

Card* Deck::getArray(int index) const{
	return cards_[index];
}

void Deck::setArray(int index, Card* newCard){
	cards_[index] = newCard;
}


//shuffle deck using seed (default 0)
void Deck::shuffle(){
	int n = 52;
	while ( n > 1 ) {
		int k = (int) (lrand48() % n); //seed_
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	}
}

//fills an empty deck with all cards in sorted order
void Deck::newDeck(){
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 13; i++) {
			cards_[i + j*13] = (new Card(static_cast<Suit>(j), static_cast<Rank>(i)));
		}
	}
}

//prints deck in current order
std::ostream &operator<<(std::ostream& out, const Deck& d){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++) {
			out << d.getArray(j+i*13) << " ";
		}
		out << std::endl;
	}
	return out;
}
