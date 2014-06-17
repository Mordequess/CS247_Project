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
	for (int i = 0; i < NUM_RANKS; i++) {
		for (int j = 0; j < NUM_SUITS; j++) {
			playedCards[j][i] = false;
		}
	}
}

std::ostream &operator<<(std::ostream &out, const Played &p){
	std::string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "J", "Q", "K"};
	//output the played cards with correct formatting
	out << "Cards on the table:" << std::endl << "Clubs:";
	for (int i = 0; i < NUM_RANKS; i++) {
		if (p.playedCards[0][i]) out << " " << ranks[i];
	}
	out << std::endl << "Diamonds:";
	for (int i = 0; i < NUM_RANKS; i++){
		if (p.playedCards[1][i]) out << " " << ranks[i];
	}
	out << std::endl << "Hearts:";
	for (int i = 0; i < NUM_RANKS; i++) {
		if (p.playedCards[2][i]) out << " " << ranks[i];
	}
	out << std::endl << "Spades:";
	for (int i = 0; i < NUM_RANKS; i++) {
		if (p.playedCards[3][i]) out << " " << ranks[i];
	}

	return out;
}
