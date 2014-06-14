#include "Human.h"

Human::Human() : Player(pl) { }

void Human::print() {
	cout << played_ << endl;
	vector<Card> currHand = getHand();
	cout << "Your hand:";
	for (int i = 0; i < currHand.size() ; i++) {
		cout << " " << currHand[i];
	}
	cout "\n";
	cout << "Legal plays:";
	for (int i = 0; i < currHand.size() ; i++) {
		if (isLegal(currhand[i])) {
			cout << " " << currhand[i];
		}
	}
	cout "\n";
}

void Human::playTurn(bool printinfo) {
	if (printinfo) {
		print();
	}
    Command command;
    cin >> command;
    
    switch (command.type) {
        //play a card
        case PLAY: {
            if (!(inHand(command.card)) || !(isLegal(command.card))) {
            	throw "This is not a legal play.";
            } 
            else {
            	vector<Card> hand = getHand();
            	cout << "Player " << plnumber_ << " plays " << command.card << "." << endl;
            	playcard(command.card);
            	std::vector<Card>::iterator position = find(hand.begin(), hand.end(), card);
    			hand.erase(position); // Need to create vector of hand
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



