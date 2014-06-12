#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include "Card.h"
#include "Deck.h"
#include "Round.h"
#include "Player.h"

class Straights {
public:
	Straights();
	//Straights(int seed);
	~Straights();

	void invitePlayers();
	void updateScores();
	void printPlayedCards();
	void printDeck();

	void playCard(Card, Player);
	void discardCard(Card, Player);
	void rageQuit(int position);

	int getFirstPlayer();

private:
	Player[4] players_;
	Deck deck_;
	Round round_;
	//int seed_;
	
};

#endif
