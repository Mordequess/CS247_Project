#ifndef HUMAN_H
#define HUMAN_H

#include "Card.h"
#include "Command.h"
#include "Player.h"
#include "Played.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>


// Human class, Derived from Player class
class Human : public Player {
public:
	Human(int, Played*); 	// Human constructos
	void print(); 			// Print human information for their turn
	void playTurn(bool); 	// Play a human turn
};



// class to catch when player wants to print deck
class deckError : public std::runtime_error {
public:
	deckError(const std::string& e) : std::runtime_error(e) {}
};
// Class to catch player rage quitting
class rquitError : public std::runtime_error {
public:
	rquitError(const std::string& e) : std::runtime_error(e) {}
};
// Class to catch player quitting
class quitError : public std::runtime_error {
public:
	quitError(const std::string& e) : std::runtime_error(e) {}
};



#endif
