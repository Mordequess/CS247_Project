#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
public:
	Player();
	virtual ~Player();
	virtual void print();
	virtual void play();
	int incrementScore(int score);
	vector<Card> getHand();
	vector<Card> discardCard(Card &);
			
private:
	vector<Card> hand_;
	vector<Card> discarded_;
	int score_;
	Played played_;
};		

#endif


//to be implemented in Player
	//getScore() ?
	//getDiscardedSum() ?
	// void printValidPlays();
	// bool validPlay(Card);
	// Player(Played);
	// -> Human(Played p) : Player() : played_(p) {}