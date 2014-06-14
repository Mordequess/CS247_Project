#include "Computer.h"

Computer::Computer() : Player(pl) {
	
}

// Unimplemented
void Computer::print() { }



void Computer::playTurn(bool ignore) {
	vector<Card> hand = getHand();
	vector<Card> plays = legalPlays(getHand());
	if (plays.size() > 0) {
		cout << "Player " << plnumber_ << " plays " << plays[0] << "." << endl;
		playcard(command.card);
        std::vector<Card>::iterator position = find(hand.begin(), hand.end(), plays[0]);
    	hand.erase(position);
	} 
}


/*
void Human::playerTurn() {
    Command command;
    cin >> command;
    
    switch (command.type) {
        //play a card
        case PLAY: {
            if (!(inHand(command.card)) || !(isLegal(command.card))) {
            	throw "This is not a legal play.";
            } 
            else {
            	cout << "Player " << plnumber_ << " plays " << command.card << "." << endl;
            	playcard(command.card);
            	std::vector<Card>::iterator position = find(hand_.begin(), hand_.end(), card);
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
            	cout << "Player " << plnumber_ << " discards " << command.card << "." << endl;
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