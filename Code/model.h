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

const int numFaces = 13;
const int numSuits = 4;
const int numCards = numFaces * numSuits;

enum Faces { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, NOFACE };
enum Suits { CLUB, DIAMOND, HEART, SPADE, NOSUIT };

class Model : public Subject {
public:
    Model();
    void startGame();
    void quitGame();
    void setPlayerType(int player);		//flips a player from computer to human and back
    void ragePlayer(int player);		//calls rage quit on active player

	void getPlayed ();
	bool getPlayerType(int player);

private:
    bool[4] playerType_;				//keeps track of whether player is human or computer: 0 = human
    int[4] playerScore_;				//keeps track of player score
    int[4] playerDiscard_;				//keeps track of number of discarded cards
    vector<Card*>[4] hands_;			//keepe a copy of each player's current hand

    Straights game;						//instance of the game
}; // Model

#endif
