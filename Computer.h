#ifndef COMPUTER_H
#define COMPUTER_H

#include "Card.h"

class Computer : public Player {
public:
	Computer();
	~Computer();
	void print();
	void playTurn(bool);
private:



};

#endif

// Card*[] hand_;
// 	int score_;
// 	int order_;
