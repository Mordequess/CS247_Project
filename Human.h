#ifndef HUMAN_H
#define HUMAN_H

#include "Card.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

class Human : public Player {
public:
	Human(int);
	~Human();
	void print();
	void playTurn(bool);
};

#endif

// Card*[] hand_;
// 	int score_;
// 	int order_;

// Copy constructor for computer player