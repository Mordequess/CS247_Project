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
	//shuffle deck
	deck_.shuffle();
	//fill hands (should be empty after each round)
	for (int i = 0; i < 4; i++) {
		std::vector<Card*> hand;
		for (int j = 0; j < 13; j++) {
			hand.push_back(deck_[j+i*13]);
		}
		players_[i].setHand(hand);
	}
	//reset board
	played_ = new Played();
	cout << "A new round begins. It’s player " << getFirstPlayer()+1 << "’s turn to play." << endl;
}

bool Straights::checkEnd() {
	for (int i = 0; i < 4; i++) {
		if (players_[i].getScore() >= 80 ) return true;
	}
	return false;
}

int Straights::getScore(int position) {
	return players_[position].getScore();
}

int Straights::getMinScore() {
	int min = players_[0].getScore();
	for (int i = 1; i < 4; i++){
		if (players_[i].getScore() < min) min = players_[i].getScore();
	}
	return min;
}

void Straights::updateScores() {
	for (int i = 0; i < 4; i++){
		cout << "Player " << i << "'s discards: ";
		for (int j = 0; j < players_[i].getDiscard().size(); j++) {
			cout << players_[i].getDiscard()[j];
		}
		cout << endl << "Player " << i << "'s score: " << players_[i].getScore();
		cout << " + " << players_[i].incrementScore();
		cout << " = " << players_[i].getScore() << endl;
	}
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
	//keep track of "first" command call
	bool first = true;

	//loop until valid input
	while (true) {
		try	{
			players_[position].playTurn(first);
			break;
		}
		catch () {
			//invalid, new command
		}
		catch () {
			//print deck, new command
			cout << deck_;
		}
		catch () {
			//ragequit
			cout << "Player " << position << " ragequits. A computer will now take over." << endl;

			std::vector<Card> hand = players_[position].getHand();
			std::vector<Card> discard = players_[position].getDiscard();
			int score = players_[position].getScore();
			players_[position] = new Computer();
			players_[position].setHand(hand);
			players_[position].setDiscard(discard);
			players_[position].incrementScore(score);
			players_[position].playTurn();
		}
		catch () {
			//quit
			throw("quit");
		}

		//if looped, will not call human print function
		first = false;
	}//while
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
