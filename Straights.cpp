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
	}
	played_ = new Played();
	cout << "A new round begins. It’s player " << getFirstPlayer()+1 << "’s turn to play." << endl;
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

void Straights::playTurn(int position){
	try	{
		players_[position].playTurn();
	}
	catch () {
		//invalid, new command
	}
	catch () {
		//print deck, new command
	}
	catch () {
		//ragequit
	}
	catch () {
		//quit
	}
}

// Player[4] players;
// Deck deck_;
// Played played_
