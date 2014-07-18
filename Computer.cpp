#include "Computer.h"
#include <vector>


// Computer player constructor, calls Player constructor
Computer::Computer(int playernum, Played* played) : Player(playernum, played) {}
Computer::Computer(Player* player) : Player(player) {}

void Computer::playTurn(bool ignore) {
	//computer AI: if no legal plays, discard first card. else play first legal card
	std::vector<Card*> hand = getHand();
	std::vector<Card*> plays = legalPlays(hand);
	if (plays.size() > 0) {

		//play highest card
		int highest = 0;
		for (unsigned int i = 0; i < plays.size(); i++){
			if (plays[highest]->getRank() < plays[i]->getRank()) highest = i;
		}

		playCard(plays[highest]);
	} else {

		//discard lowest card
		int lowest = 0;
		for (unsigned int i = 0; i < hand.size(); i++){
			if (hand[lowest]->getRank() > hand[i]->getRank()) lowest = i;
		}
		discardCard(hand[lowest]);
	} 
}
