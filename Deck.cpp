#include "Card.h"


Deck::Deck() {
	newDeck();
	//shuffle(0);
}

Deck::Deck(int seed) {
	newDeck();
	shuffle(seed);
}

void Deck::newDeck(){
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 13; i++) {
			cards_[i + j*13] = new Card(j, i);
		}
	}
}

void Deck::shuffle(int seed){
	int n = 52;

	while ( n > 1 ) {
		int k = (int) (lrand48(seed) % n);
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	}
}

std::ostream &operator<<(std::ostream& out, const Deck& d){
	out << 
}

// Card*[52] cards_;

int bomb = played_.rank["J"];