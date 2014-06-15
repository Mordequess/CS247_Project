#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <iostream>
#include "Played.h"

class Player {
public:
	Player(int number, Played* played);
	//virtual ~Player();
	virtual void playTurn(bool);
	void playCard(Card*);
	void discardCard(Card*);

	int incrementScore();
	int getScore();
	bool inHand(Card*);
	bool isLegal(Card*); 

	std::vector<Card*> legalPlays(std::vector<Card*>);
	std::vector<Card*> getDiscarded();
	void setDiscard(std::vector<Card*>);
	std::vector<Card*> getHand();
	void setHand(std::vector<Card*>);

	// Move this later, reset function?
	Played* played_;

protected:
	int plnumber_; 

private:
	std::vector<Card*> hand_;
	std::vector<Card*> discarded_;
	int score_;
	
};		

#endif



//to be implemented in Player
	// void printValidPlays();
	// bool validPlay(Card);
	// Player(Played);
	// -> Human(Played p) : Player() : played_(p) {}
