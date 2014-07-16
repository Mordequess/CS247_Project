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


#include "model.h"
//#include "Played.h"
//#include "Straights.h"
#include <stdlib.h>


Model::Model() {
	playerType_ = {0,0,0,0};	//all players default to human
	playerScore_ = {0,0,0,0};	//all players start at 0 points
	playerDiscard_ = {0,0,0,0};	//all players start with empty discard piles
}

void Model::startGame(int seed) {
	//
	srand48(seed);
    Straights game = Straights(playerType_);

    //set first player
    int whosTurn = game.getFirstPlayer();
    //game.nextRound();

	//change human/comp buttons to rage (only humans, computers say comp?)

 	notify();
}

void Model::quitGame() {
 	//
 	//destroy game
 	game.~Straights();

	//clear board
 	for (int i = 0; i < 52; i++) {
		//images[i] = deck(null);
	}

	//clear hand
 	for (int i = 0; i < 13; i++) {
		//images[i] = deck(null);
	}

	//change rage buttons back to human/comp
  	notify();
}

void Model::ragePlayer (int player) {
	//ragequit
	//notify();
}

bool Model::getPlayerType (int player) {
	return playerType_[player];
}

int Model::getScore (int player) {
	return game.getScore(player);
}

Played Model::getPlayed () {
	return game.getPlayedCards();
}

//running the rounds
/*
    bool end = false;
    while (!end) {
        game.nextRound();
        int whosTurn = game.getFirstPlayer();
        
        //play out every card till no more in hand 
        for (int i = 0; i < NUM_CARDS; i++) {
            game.playerTurn( (whosTurn+i) % NUM_PLAYERS );
        }
        game.updateScores();
        end = game.checkEnd();
    }
*/

//winners
/*int winScore = game.getMinScore();
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (game.getScore(i) == winScore) 
            std::cout << "Player " << i + 1 << " wins!" << std::endl;
    }
*/



