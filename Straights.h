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

	void updateScores();
	void printDeck();

	void playCard(Card, Player);
	void discardCard(Card, Player);
	void rageQuit(int position);

	int getFirstPlayer();

private:
	void invitePlayers();
	void printPlayedCards();

	Player[4] players_;
	Deck deck_;
	Round round_;
	//int seed_;
	
};

#endif
