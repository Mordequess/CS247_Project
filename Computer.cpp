#include "Computer.h"
#include <vector>


Computer::Computer(int playernum) : Player(playernum) {
	
}

// Unimplemented
void Computer::print() { }

void Computer::playTurn(bool ignore) {
	std::vector<Card*> hand = getHand();
	std::vector<Card*> plays = legalPlays(hand);
	if (plays.size() > 0) {
		std::cout << "Player " << plnumber_ << " plays " << *plays[0] << "." << std::endl;
		playCard(*plays[0]);
    	hand.erase(hand.begin());
	} else {
		std::cout << "Player " << plnumber_ << " discards " << *hand[0] << "." << std::endl;
		discardCard(*hand[0]);
	} 
}


/*
void Human::playerTurn() {
    Command command;
    std::cin >> command;
    
    switch (command.type) {
        //play a card
        case PLAY: {
            if (!(inHand(command.card)) || !(isLegal(command.card))) {
            	throw "This is not a legal play.";
            } 
            else {
            	std::cout << "Player " << plnumber_ << " plays " << command.card << "." << std::endl;
            	playcard(command.card);
            	std::vector<Card*>::iterator position = find(hand_.begin(), hand_.end(), card);
    			hand_.erase(position);
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

*/