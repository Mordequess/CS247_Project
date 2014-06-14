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

int Straights::checkWinner() {
	int winner = -1;
	bool end = false;
	for (int i = 0; i < 4; i++) {
		if (players_[i].getScore() >= 80 ) end = true;
	}
	if (end) {
		winner = 0;
		for (int i = 1; i < 3; i++) {

		}
	}
	return winner;
}

int Straights::getFirstPlayer(){
	int first = 0;
	//check for 7S
	while (!players_[first].inHand(Card(3, 6))) {
		first++;
	}
	return first;
}

void Straights::playerTurn(int position){
	try	{
		players_[position].playTurn();
	}
	catch () {
		//invalid, new command
		players_[position].playTurn();
	}
	catch () {
		//print deck, new command
		cout << deck_;
		players_[position].playTurn();
	}
	catch () {
		//ragequit
		cout << "Player " << position << " ragequits. A computer will now take over." << endl;

		std::vector<Card> hand = players_[position].getHand();
		std::vector<Card> discard = players_[position].getDiscard();
		int score = players_[position].getScore();
		players_[position] = new Computer(***);
		players_[position].setHand(hand);
		players_[position].setDiscard(discard);
		players_[position].incrementScore(score);
		players_[position].playTurn();
	}
	catch () {
		//quit
		throw("quit");
	}
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

// Player[4] players;
// Deck deck_;
// Played played_
