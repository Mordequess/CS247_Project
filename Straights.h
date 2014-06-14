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
	bool checkWinner();
	int getFirstPlayer();

	void playerTurn();
	void printDeck();
	void rageQuit(int);


private:
	void invitePlayers();
	void printPlayedCards();

	Player[4] players_;
	Deck deck_;
	Played played_;
};

#endif
