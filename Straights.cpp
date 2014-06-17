#include <iostream>
#include <vector>
#include <cassert>

#include "Card.h"
#include "Human.h"
#include "Computer.h"
#include "Straights.h"

Straights::~Straights(){
}

Straights::Straights (int seed){
	//fill deck with values
	//deck_ = Deck(seed);
	played_ = new Played();
	//build player array
    for (int i = 0; i < 4; i++) {
        std::cout << "Is player " << i + 1 << " a human(h) or a computer(c)?" << std::endl << ">";
        char type;
        std::cin >> type;
        assert (type == 'h' || type == 'c');
        if (type == 'h') players_[i] = new Human(i, played_);
        else players_[i] = new Computer(i, played_);
    }
}

void Straights::nextRound(){
	//shuffle deck
	deck_.shuffle();
	//fill hands (should be empty after each round)
	for (int i = 0; i < 4; i++) {
		std::vector<Card*> hand;
		for (int j = 0; j < 13; j++) {
			hand.push_back(deck_.getArray(j+i*13));
		}
		players_[i]->setHand(hand);
	}	
	//reset board
	played_->resetBoard();
	std::cout << "A new round begins. It's player " << getFirstPlayer()+1 << "'s turn to play." << std::endl;
}

bool Straights::checkEnd() {
	//check if any player past score limit
	for (int i = 0; i < 4; i++) {
		if (players_[i]->getScore() >= 80 ) return true;
	}
	return false;
}

int Straights::getScore(int position) {
	return players_[position]->getScore();
}

int Straights::getMinScore() {
	//get lowest score of all players
	int min = players_[0]->getScore();
	for (int i = 1; i < 4; i++){
		if (players_[i]->getScore() < min) min = players_[i]->getScore();
	}
	return min;
}

void Straights::updateScores() {
	//increment scores at end of round
	for (int i = 0; i < 4; i++){
		//*** make a computer constructor that takes in a human?
		std::cout << "Player " << i + 1 << "'s discards:";
		if (players_[i]->getDiscarded().size() == 0) std::cout << " ";
		for (int j = 0; j < players_[i]->getDiscarded().size(); j++) {
			std::cout << " " << *players_[i]->getDiscarded()[j];
		}
		std::cout << std::endl << "Player " << i + 1 << "'s score: " << players_[i]->getScore();
		std::cout << " + " << players_[i]->incrementScore();
		std::cout << " = " << players_[i]->getScore() << std::endl;
		//clear hand
		players_[i]->setDiscard(std::vector<Card*>());
	}
}

int Straights::getFirstPlayer(){
	//check each player's hand for 7S
	int first = 0;
	while (!players_[first]->inHand(new Card(static_cast<Suit>(3), static_cast<Rank>(6))) ) {
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
			players_[position]->playTurn(first);
			break;
		}
		catch (std::string e) {
			//invalid, new command
			std::cout << e << std::endl; 
		}
		catch (deckError e) {
			//print deck, new command
			std::cout << deck_;
		}
		catch (rquitError e) {
			//ragequit
			std::cout << "Player " << position + 1 << " ragequits. A computer will now take over." << std::endl;

			std::vector<Card*> hand = players_[position]->getHand();
			std::vector<Card*> discard = players_[position]->getDiscarded();
			//int score = players_[position]->getScore();
			players_[position] = new Computer(position, played_);
			players_[position]->setHand(hand);
			players_[position]->setDiscard(discard);
			players_[position]->incrementScore();
		}
		catch (quitError e) {
			//quit
			throw("quit");
		}

		//if looped, will not call human print function
		first = false;
	}//while
}
