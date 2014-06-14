#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <iostream>
#include "Played.h"

class Player {
public:
	Player(int number);
	virtual ~Player();
	virtual void print();
	virtual void playTurn(bool);
	void playCard(Card);
	int incrementScore();
	int getScore();
	void setHand(std::vector<Card>);
	bool inHand(Card);
	bool isLegal(Card); 

	std::vector<Card> legalPlays(std::vector<Card>);;
	std::vector<Card> getDiscard();
	std::vector<Card> setDiscard();
	std::vector<Card> getHand();
	void discardCard(Card &);
protected:
	int plnumber_; 
private:
	std::vector<Card> hand_;
	std::vector<Card> discarded_;
	int score_;
	Played played_;
};		

#endif



//to be implemented in Player
	// void printValidPlays();
	// bool validPlay(Card);
	// Player(Played);
	// -> Human(Played p) : Player() : played_(p) {}
