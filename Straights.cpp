#include <iostream>
#include <vector>

#include "Deck.h"
#include "Card.h"
#include "Played.h"
#include "Players.h"
#include "Human.h"
#include "Computer.h"

using namespace std;

Straights::Straights (int seed){
	deck_ = new Deck(seed);
    invitePlayers();
    //round_ = new Round(players_, deck_);
    nextRound();
}

void Straights::nextRound(){
	deck_.shuffle(0);
	for (int i = 0; i < 4; i++) {
		std::vector<Card> hand;
		for (int j = 0; j < 13; j++) {
			hand.push_back(deck_[j+i*13]);
		}
		players_[i].setHand(hand);
	played_ = new Played();
	cout << "A new round begins. It’s player " << getFirstPlayer()+1 << "’s turn to play.";
}

void Straights::invitePlayers () {
	for (int i = 0; i < 4; i++) {
        cout << "Is player " + i + " a human(h) or a computer(c)?" << endl;
        char type;
        cin >> type;
        assert (type == 'h' || type == 'c');
        if (type == h) players[i] = new Human(i);
        else players[i] = new Computer(i);
    }
}

void Straights::printDeck() {
	cout << deck_;
}

void Straights::rageQuit(int position){
	std::vector<Card> hand = players_[position].getHand();
	std::vector<Card> discard = players_[position].getDiscard();
	int score = players_[position].getScore();
	players_[position] = new Computer(***);
	players_[position].setHand(hand);
	players_[position].setDiscard(discard);
	players_[position].incrementScore(score);
}

int Straights::getFirstPlayer(){
	int first = 0;
	//check for 7S
	while (!players_[first].isInHand(Card(3, 6))) {
		first++;
	}
	return first;
}

void Straights::playCard(int position, Card card){

}

void Straights::discardCard(int position, Card card){

}

void Straights::playCompTurn(int position){
	if (players_[position].validPlays = 0?) discardCard(position, players_[position].getHand[0]);
	else playCard(position, players_[position].validPlays[0]);
	//if (players_[position+1])

}


// Player[4] players;
// Deck deck_;
// Played played_

//************************************************************************
//  Test Harness Helper functions
//************************************************************************
void turnIncrement(int& whosTurn){
    whosTurn = (++whosTurn)%4;
}


//******************************************************************
// Harness for Straights
//******************************************************************

int main() {
    cout << "Harness for Straights Game:" << endl << endl;
    Straights game = new Straights(0); //*** retrieve input from string[args]?
    int whosTurn = game.getFirstPlayer();
    //get first command
    Command command;
    cin >> command;
    
    bool quit = false;
    while (!cin.eof()) {
        switch (command.type) {
    
            //play a card
            case PLAY: {
                game.playCard(whosTurn, command.card);
                cout << "Player " << whosTurn << " plays " << command.card << ".";
                turnIncrement(whosTurn);
                break;
            }
            
            //discard a card
            case DISCARD: {
                game.discardCard(whosTurn, command.card);
                cout << "Player " << whosTurn << " discards " << command.card << ".";
                turnIncrement(whosTurn);
                break;
            }
                
            //print the deck
            case DECK: {
                game.printDeck();
                break;
            }
                
            //exit program
            case QUIT: {
                quit = false;
                break;
            }

            //replace current human player with a computer
            case RAGEQUIT: {
                game.rageQuit(whosTurn);
                break;
            }
                
            default:
                break;
        } // switch
					
    //get next command
    if (quit) break;
    cin >> command;
        
    } // while cin OK
    
    //***delete game?
    return 0;
}
