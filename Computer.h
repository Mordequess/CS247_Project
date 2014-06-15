#ifndef COMPUTER_H
#define COMPUTER_H

#include "Card.h"
#include "Player.h"
#include "Played.h"


class Computer : public Player {
public:
	Computer(int, Played*);
	//~Computer();
	void playTurn(bool);
private:



};

#endif

// Card*[] hand_;
// 	int score_;
// 	int order_;
