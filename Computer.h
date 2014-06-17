#ifndef COMPUTER_H
#define COMPUTER_H

#include "Card.h"
#include "Played.h"
#include "Player.h"


class Computer : public Player {
public:
	Computer(int, Played*);  			// Computer player constuctor
	Computer(Human*);  	// ragequit constuctor
	void playTurn(bool);				// Play computer turn 		
private:



};

#endif

