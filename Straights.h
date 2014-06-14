#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#include "Deck.h"
#include "Player.h"
#include "Played.h"

class Straights {
public:
	Straights(int seed);
	~Straights();

	void nextRound();
	bool checkEnd();
	int getScore(int position);
	int getMinScore();
	void updateScores();
	int getFirstPlayer();

	void playerTurn();

private:
	void invitePlayers();

	Player[4] players_;
	Deck deck_;
	Played played_;
};

#endif
