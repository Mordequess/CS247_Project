#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
public:
	Player(int number);
	virtual ~Player();
	virtual void print();
	virtual void playTurn(bool);
	void playCard(Card);
	int incrementScore();
	int getScore();
	void setHand(vector<Card>);
	bool inHand(Card);
	bool isLegal(Card, Played); 

	vector<Card> legalPlays(vector<Card>, Played);
	vector<Card> getDiscard();
	vector<Card> setDiscard();
	vector<Card> getHand();
	void discardCard(Card &);

private:
	vector<Card> hand_;
	vector<Card> discarded_;
	int score_;
	int plnumber_; 
	Played played_;
};		

#endif



//to be implemented in Player
	// void printValidPlays();
	// bool validPlay(Card);
	// Player(Played);
	// -> Human(Played p) : Player() : played_(p) {}
