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
    void ragePlayer();		//calls rage quit on active player

    void playTurn();
    void cardPlayDiscard(int card, bool legal);

    int getScore(int player);
    int getActivePlayer();
    Played* getPlayed ();
	Player* getPlayer (int player);
    bool gameIsNull();
    bool checkEnd();
    std::string getWinners();
	bool getPlayerType(int player);
    void setPlayerType(int player);     //flips a player from computer to human and back

private:
    bool playerType_[4];				//keeps track of whether player is human or computer: 0 = human
    int activePlayer_;
    Straights* game;						//instance of the game
}; // Model

#endif
