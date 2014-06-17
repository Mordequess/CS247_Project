#include "Computer.h"
#include <vector>


// Computer player constructor, calls Player constructor
Computer::Computer(int playernum, Played* played) : Player(playernum, played) { }

void Computer::playTurn(bool ignore) {
	//computer AI: if no legal plays, discard first card. else play first legal card
	std::vector<Card*> hand = getHand();
	std::vector<Card*> plays = legalPlays(hand);
	if (plays.size() > 0) {
		std::cout << "Player " << getPlayerNum() << " plays " << *plays[0] << "." << std::endl;
		playCard(plays[0]);
	} else {
		std::cout << "Player " << getPlayerNum() << " discards " << *hand[0] << "." << std::endl;
		discardCard(hand[0]);
	} 
}
