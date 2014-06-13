#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Played.h"

class Straights {
public:
	Straights(int seed);
	~Straights();

	void nextRound();
	void printDeck();

	void playCard(int, Card);
	void discardCard(int, Card);
	void rageQuit(int);

	int getFirstPlayer();

private:
	void playCompTurn();
	void invitePlayers();
	void printPlayedCards();

	Player[4] players_;
	Deck deck_;
	Played played_;
};

#endif
