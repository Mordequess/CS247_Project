#ifndef COMPUTER_H
#define COMPUTER_H

#include "Card.h"
#include "Player.h"


class Computer : public Player {
public:
	Computer(int);
	~Computer();
	void print();
	void playTurn(bool);
private:



};

#endif

// Card*[] hand_;
// 	int score_;
// 	int order_;
