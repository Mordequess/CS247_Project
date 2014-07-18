#include <iostream>
#include <vector>
#include <cassert>

#include "Card.h"
#include "Human.h"
#include "Computer.h"
#include "Straights.h"

Straights::~Straights(){
	delete played_;
}

Straights::Straights (){}

Straights::Straights (bool playerType[]){
	//fill deck with values
	played_ = new Played();
	//build player array
    for (int i = 0; i < NUM_PLAYERS; i++) {
	    if (playerType[i]) players_[i] = new Computer(i, played_);
	    else players_[i] = new Human(i, played_);
	}
}

void Straights::nextRound(){
	deck_.shuffle();
	//Deal hands (should be empty after each round)
	for (int i = 0; i < NUM_PLAYERS; i++) {
		//clear hand
		players_[i]->setDiscard(std::vector<Card*>());
		
		std::vector<Card*> hand;
		for (int j = 0; j < NUM_CARDS/4; j++) {
			hand.push_back(deck_.getCard(j+i*NUM_CARDS/4));
		}
		players_[i]->setHand(hand);
	}	
	//reset board
	played_->resetBoard();
}

bool Straights::checkEnd() const {
	//check if any player past score limit
	for (int i = 0; i < NUM_PLAYERS; i++) {
		if (players_[i]->getScore() >= 80 ) return true;
	}
	return false;
}

int Straights::getScore(int playerposition) const {
	return players_[playerposition]->getScore();
}

int Straights::getMinScore() const {
	//get lowest score of all players
	int min = players_[0]->getScore();
	for (int i = 1; i < NUM_PLAYERS; i++){
		if (players_[i]->getScore() < min) min = players_[i]->getScore();
	}
	return min;
}

Player* Straights::getPlayer(int playernum){
	return players_[playernum];
}

Played* Straights::getPlayedCards(){
	return played_;
}

void Straights::updateScores() {
	//increment scores at end of round
	for (int i = 0; i < NUM_PLAYERS; i++){
		players_[i]->incrementScore();
	}
}

int Straights::getFirstPlayer() const {
	//check each player's hand for 7S
	int first = 0;
	while (!players_[first]->inHand(new Card(static_cast<Suit>(3), static_cast<Rank>(6))) ) {
		first++;
	}
	return first;
}

void Straights::playerTurn(int playerposition) {
	//keep track of "first" command call
	bool first = true;

	//loop until valid input
	while (true) {
		try	{
			players_[playerposition]->playTurn(first);
			break;
		}
		catch (char const* e) { 
			//invalid, new command
			std::cout << e << std::endl; 
		}
		catch (deckError e) {
			//print deck, new command
			std::cout << deck_;
		}
		catch (rquitError e) {
			//ragequit
			rageQuit(playerposition);
		}

		//if looped, will not call human print function
		first = false;
	}
}

void Straights::rageQuit(int playerposition){
	Player* newComp = new Computer(players_[playerposition]);
	delete players_[playerposition];
	players_[playerposition] = newComp;
}


