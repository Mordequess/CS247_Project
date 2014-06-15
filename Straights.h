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

	void playerTurn(int);

private:
	Player players_[4];
	Deck deck_;
	Played played_;
};

#endif
