#include "Computer.h"
#include <vector>


// Computer player constructor, calls Player constructor
Computer::Computer(int playernum, Played* played) : Player(playernum, played) { }
Computer::Computer(Player* player) : Player(player) {
}

void Computer::playTurn(bool ignore) {
	//computer AI: if no legal plays, discard first card. else play first legal card
	std::vector<Card*> hand = getHand();
	std::vector<Card*> plays = legalPlays(hand);
	if (plays.size() > 0) {

		//play highest card
		int highest = 0;
		for (int i = 0; i < plays.size(); i++){
			if (plays[highest]->rank < plays[i]->rank) highest = i;
		}

		std::cout << "Player " << getPlayerNum() << " plays " << *plays[highest] << "." << std::endl;
		playCard(plays[highest]);
	} else {

		//discard lowest card
		int lowest = 0;
		for (int i = 0; i < hand.size(); i++){
			if (hand[lowest]->rank > hand[i]->rank) lowest = i;
		}

		std::cout << "Player " << getPlayerNum() << " discards " << *hand[lowest] << "." << std::endl;
		discardCard(hand[lowest]);
	} 
}
