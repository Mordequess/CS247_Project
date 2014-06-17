#include <sstream>
#include <stdlib.h>
#include <iostream>
#include "Deck.h"


// Default constructor calls newDeck()
Deck::Deck(){
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 13; i++) {
			cards_[i + j*13] = (new Card(static_cast<Suit>(j), static_cast<Rank>(i)));
		}
	}
}

Deck::~Deck(){
	for (int i = 0; i < cards_.size(); i_++) {
		delete cards_[i];
	}
}


Card* Deck::getArray(int index) const{
	return cards_[index];
}

void Deck::setArray(int index, Card* newCard){
	cards_[index] = newCard;
}


//shuffle deck using srand seed (default 0)
void Deck::shuffle(){
	int n = 52;
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
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++) {
			out << *d.getArray(j+i*13) << " ";
		}
		out << std::endl;
	}
	return out;
}
