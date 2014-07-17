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

Straights::Straights (){
	//fill deck with values
	played_ = new Played();
	//build player array
    for (int i = 0; i < NUM_PLAYERS; i++) {
        std::cout << "Is player " << i + 1 << " a human(h) or a computer(c)?" << std::endl << ">";
        char type;
        std::cin >> type;
        assert (type == 'h' || type == 'c');
        if (type == 'h') players_[i] = new Human(i, played_);
        else players_[i] = new Computer(i, played_);
    }
}

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
	std::cout << "A new round begins. It's player " << getFirstPlayer()+1 << "'s turn to play." << std::endl;
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

		std::cout << "Player " << i + 1 << "'s discards:";
		if (players_[i]->getDiscarded().size() == 0) std::cout << " ";
		for (uint j = 0; j < players_[i]->getDiscarded().size(); j++) { //why uint? odd warning
			std::cout << " " << *(players_[i]->getDiscarded()[j]);
		}
		std::cout << std::endl << "Player " << i + 1 << "'s score: " << players_[i]->getScore();
		std::cout << " + " << players_[i]->incrementScore();
		std::cout << " = " << players_[i]->getScore() << std::endl;
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
	std::cout << "Player " << playerposition + 1 << " ragequits. A computer will now take over." << std::endl;
	Player* newComp = new Computer(players_[playerposition]);
	delete players_[playerposition];
	players_[playerposition] = newComp;
}
/*
bool Straights::checkRoundEnd() const {
	for (int i = 0; i < NUM_PLAYERS; i++) {
		if (players_[i]->getHand().size() > 0) return false;
	}
	return true;
}
*/
