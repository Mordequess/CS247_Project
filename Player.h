#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
public:
	Player(int type);

	void print();
	void play();
private:
	int score_;
	int order_;
};

#endif
