#ifndef STRAIGHTS_H
#define STRAIGHTS_H

#import "Card.h"
#import "Deck.h"
#import "Round.h"
#import "Player.h"

class Straights {
public:
	Straights();
	Straights(int seed);
	Straights();

	newRound();
	void invitePlayers();
	void updateScores();

private:
	Player[4] players;
	Deck deck_;
};

#endif
