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

class Model : public Subject {
public:
    Model();
    void startGame();
    void quitGame();
    void setPlayerType(int player);		//flips a player from computer to human and back
    void ragePlayer(int player);		//calls rage quit on active player

	void updatePlayed ();

private:
    bool[4] playerType_;				//keeps track of whether player is human or computer: 0 = human
    int[4] playerScore_;				//keeps track of player score
    int[4] playerDiscard_;				//keeps track of number of discarded cards
    Straights game;

}; // Model


#endif
