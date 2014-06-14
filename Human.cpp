#include "Human.h"
#include <vector>


Human::Human(int playernum) : Player(playernum) { }

void Human::print() {
	std::cout << played_ << std::endl;
	std::vector<Card> currHand = getHand();
	std::cout << "Your hand:";
	for (int i = 0; i < currHand.size() ; i++) {
		std::cout << " " << currHand[i];
	}
	std::cout "\n";
	std::cout << "Legal plays:";
	for (int i = 0; i < currHand.size() ; i++) {
		if (isLegal(currhand[i])) {
			std::cout << " " << currhand[i];
		}
	}
	std::cout "\n";
}

void Human::playTurn(bool printinfo) {
	if (printinfo) {
		print();
	}
    Command command;
    std::cin >> command;
    
    switch (command.type) {
        //play a card
        case PLAY: {
            if (!(inHand(command.card)) || !(isLegal(command.card))) {
            	throw "This is not a legal play.";
            } 
            else {
            	std::vector<Card> hand = getHand();
            	std::cout << "Player " << plnumber_ << " plays " << command.card << "." << std::endl;
            	playcard(command.card);
            	std::vector<Card>::iterator position = find(hand.begin(), hand.end(), card);
    			hand.erase(position); 
            }
            break;
        }
        //discard a card
        case DISCARD: {
            if (legalPlays.size() != 0) {
            	throw "You have a legal play. You may not discard.";
            } 
            else {
            	std::cout << "Player " << plnumber_ << " discards " << command.card << "." << std::endl;
            	discardCard(command.card);
            }
            break;
        }
            
        //print the deck
        case DECK: {
            throw "print deck";
            break;
        }
            
        //exit program
        case QUIT: {
            throw "quit";
            break;
        }

        //replace current human player with a computer
        case RAGEQUIT: {
            throw "rage quit";
            break;
        }
            
        default:
            break;
    } // switch
}



