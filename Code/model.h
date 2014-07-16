/*
 * MVC example of GTKmm program
 *
 * Model class.  Is responsible keeping track of the deck of cards.  
 * It knows nothing about views or controllers.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */

#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include "Straights.h"
#include <vector>

class Model : public Subject {
public:
    Model();
    void startGame(int seed);
    void quitGame();
    void setPlayerType(int player);		//flips a player from computer to human and back
    void ragePlayer(int player);		//calls rage quit on active player

    int getScore(int player);
	Played getPlayed ();
	bool getPlayerType(int player);

private:
    bool playerType_[4];				//keeps track of whether player is human or computer: 0 = human
    std::vector<Card*> hands_[4];		//keeps a copy of each player's current hand

    //Straights game;						//instance of the game
}; // Model

#endif
