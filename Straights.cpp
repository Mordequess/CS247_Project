#include <iostream>
#include <vector>

#include "Deck.h"
#include "Card.h"
#include "Players.h"
#include "Human.h"
#include "Computer.h"
#include "Round.h"

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
}

void Straights::invitePlayers () {
	for (int i = 0; i < 4; i++) {
        cout << "Is player " + i + " a human(h) or a computer(c)?" << endl;
        char type;
        cin >> type;
        assert (type == 'h' || type == 'c');
        if (type == h) players[i] = new Human();
        else players[i] = new Computer();
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
}


// Player[4] players;
// Deck deck_;
// Played Played_
