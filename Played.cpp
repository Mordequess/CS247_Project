#include "Played.h"
#include <iostream>


Played::Played() { }



bool Played::isLegal(Card card) {
	//7, A, K
	if (!(card.getRank() == 6 && card.getSuit() == 3) && !playedCards[3][6]) return false;
	if (card.getRank() == 6) return true;
	if (card.getRank() == 0) return playedCards[card.getSuit()][1];
	if (card.getRank() == 12) return playedCards[card.getSuit()][11];
	return (playedCards[card.getSuit()][card.getRank()-1] || playedCards[card.getSuit()][card.getRank()+1]);
}

void Played::setCard(Card card) {
	playedCards[card.getSuit()][card.getRank()] = true;
}

//Reset all boolean values to false
void Played::resetBoard() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			playedCards[j][i] = false;
		}
	}
}

std::ostream &operator<<(std::ostream &out, const Played &p){
	//output the played cards with correct formatting
	out << "Cards on the table:" << std::endl << "Clubs:";
	for (int i = 0; i < 13; i++) {
		if (p.playedCards[0][i]) out << " " << static_cast<Rank>(i+1);
	}
	out << std::endl << "Diamonds:";
	for (int i = 0; i < 13; i++){
		if (p.playedCards[1][i]) out << " " << static_cast<Rank>(i+1);
	}
	out << std::endl << "Hearts:";
	for (int i = 0; i < 13; i++) {
		if (p.playedCards[2][i]) out << " " << static_cast<Rank>(i+1);
	}
	out << std::endl << "Spades:";
	for (int i = 0; i < 13; i++) {
		if (p.playedCards[3][i]) out << " " << static_cast<Rank>(i+1);
	}

	return out;
}
