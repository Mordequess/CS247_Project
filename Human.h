#ifndef HUMAN_H
#define HUMAN_H

#include "Card.h"

class Human : public Player {
public:
	Human();
	~Human();
	void print();
	void playerTurn();
};

#endif

// Card*[] hand_;
// 	int score_;
// 	int order_;

// Copy constructor for computer player