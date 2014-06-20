#include "Human.h"
#include <vector>


// Human constructor, calls player constructor
Human::Human(int playernum, Played* played) : Player(playernum, played) { }


// Print played cards, hand and legal cards
void Human::print() const {
	std::cout << *getPlayed() << std::endl; 
	std::vector<Card*> currHand = getHand();
	std::cout << "Your hand:";
	for (int i = 0; i < currHand.size() ; i++) {
		std::cout << " " << *currHand[i];
	}
	std::cout << "\n";
	std::cout << "Legal plays:";
	for (int i = 0; i < currHand.size() ; i++) {
		if (getPlayed()->isLegal(*currHand[i])) {
			std::cout << " " << *currHand[i];
		}
	}
	std::cout << "\n";
}


void Human::playTurn(bool printinfo) {
	//print player info only if first playerTurn call
    if (printinfo) {
		print();
	}
    // Wait for a command
    Command command;
    std::cout << ">";
    std::cin >> command;
    
    // Execute command type
    switch (command.type) {
        case PLAY: {
            if (!(inHand(&command.card)) || !(getPlayed()->isLegal(command.card))) {
            	throw "This is not a legal play.";
            } 
            else {
            	std::vector<Card*> hand = getHand();
            	std::cout << "Player " << getPlayerNum() << " plays " << command.card << "." << std::endl;
            	playCard(&command.card);
            }
            break;
        }
        case DISCARD: {
            if (!(inHand(&command.card)) || legalPlays(getHand()).size() != 0) {
            	throw "You have a legal play. You may not discard."; 
            } 
            else {
            	std::cout << "Player " << getPlayerNum() << " discards " << command.card << "." << std::endl;
            	discardCard(&command.card);
            }
            break;
        }
        case DECK: {
            throw (deckError("print deck"));    // Throw to Straights to print deck
            break;
        }
        case QUIT: {
            exit(0);
            break;
        }
        case RAGEQUIT: {
            throw (rquitError ("rage quit"));   // Throw to Straights to remove human player
            break;
        }     
        default:
            break;
    }
}



