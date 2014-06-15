#include "Computer.h"
#include <vector>

Computer::Computer(int playernum) : Player(playernum) {
}

void Computer::playTurn(bool ignore) {
	std::vector<Card*> hand = getHand();
	std::vector<Card*> plays = legalPlays(hand);
	if (plays.size() > 0) {
		std::cout << "Player " << plnumber_ << " plays " << *plays[0] << "." << std::endl;
		//playCard(*plays[0]);
    	hand.erase(hand.begin());
        setHand(hand);
	} else {
		std::cout << "Player " << plnumber_ << " discards " << *hand[0] << "." << std::endl;
		//discardCard(*hand[0]);
	} 
}
