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
#include "Straights.h"
#include <stdlib.h>


Model::Model() {
    game = NULL;
	for (int i = 0; i < 4; i++) {
        playerType_[i] = false;	//all players default to human
    }
}

void Model::playTurn() {
    //play until human turn
    while (playerType_[activePlayer_]) {
        //*** loop only until hands are empty
        if (game->getPlayer(activePlayer_)->getHand().size() == 0) break;
        game->playerTurn(activePlayer_);
        activePlayer_ = ++activePlayer_%4;
    }
    //update board, show human player's hand
    notifyCardPlayed();
    notifyDrawHand();

    if (game->getPlayer(activePlayer_)->getHand().size() == 0) {
        game->updateScores();
        notifyRoundEnd();

        if (game->checkEnd()) {
            int winScore = game->getMinScore();
            for (int i = 0; i < NUM_PLAYERS; i++) {
                if (game->getScore(i) == winScore) {
                    //std::cout << "Player " << i + 1 << " wins!" << std::endl;
                    //***game end update
                }
            }
        }
        else {
            game->nextRound();
            //set first player
            activePlayer_ = game->getFirstPlayer();

            //run player rounds
            playTurn();
        }
    }
}

void Model::startGame(int seed) {
    //end existing game
    if (!gameIsNull()) quitGame();

	srand48(seed);
    game = new Straights(playerType_);
    game->nextRound();
    
    //set first player
    activePlayer_ = game->getFirstPlayer();

    //run player rounds
 	notifyGameStartEnd();
    playTurn();
}

void Model::quitGame() {
 	//destroy game
 	game->~Straights();
    game = NULL;

  	notifyGameStartEnd();
}

void Model::cardPlayDiscard (int card, bool legal) {
    //play or discard the card
    if (legal) {
        game->getPlayer(activePlayer_)->playCard(game->getPlayer(activePlayer_)->getHand()[card]);
    }
    else {
        game->getPlayer(activePlayer_)->discardCard(game->getPlayer(activePlayer_)->getHand()[card]);
    }

    //move on to next player
    activePlayer_ = ++activePlayer_%4;
    playTurn();
}

void Model::ragePlayer () {
	//ragequit
    game->rageQuit(activePlayer_);
    setPlayerType(activePlayer_);
    playTurn();
}

bool Model::gameIsNull () {
    return game == NULL;
}

bool Model::getPlayerType (int player) {
    return playerType_[player];
}

void Model::setPlayerType (int player) {
    playerType_[player] = !playerType_[player];
}

int Model::getScore (int player) {
    return game->getScore(player);
}

int Model::getActivePlayer () {
    return activePlayer_;
}

Played* Model::getPlayed () {
    return game->getPlayedCards();
}

Player* Model::getPlayer (int player) {
    return game->getPlayer(player);
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



