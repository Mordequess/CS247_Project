#ifndef HUMAN_H
#define HUMAN_H

#include "Card.h"
#include "Player.h"
#include "Played.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>



class deckError : public std::runtime_error {
public:
	deckError(const std::string& e) : std::runtime_error(e) {}
};

class rquitError : public std::runtime_error {
public:
	rquitError(const std::string& e) : std::runtime_error(e) {}
};

class quitError : public std::runtime_error {
public:
	quitError(const std::string& e) : std::runtime_error(e) {}
};


class Human : public Player {
public:
	Human(int, Played*);
	//~Human();
	void print();
	void playTurn(bool);
};

#endif

// Card*[] hand_;
// 	int score_;
// 	int order_;

// Copy constructor for computer player
