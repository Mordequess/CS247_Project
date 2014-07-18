#include "model.h"
#include "Straights.h"
#include <stdlib.h>


Model::Model() {
    game = NULL;
	for (int i = 0; i < 4; i++) {
        playerType_[i] = false;	//all players default to human
    }
}

// Plays a turn
void Model::playTurn() {
    //play until human turn
    while (playerType_[activePlayer_]) {
        if (game->getPlayer(activePlayer_)->getHand().size() == 0) break;
        game->playerTurn(activePlayer_);
        notifyCardPlayed();
        activePlayer_ = (activePlayer_+1)%4;
    }
    notifyCardPlayed();

    if (game->getPlayer(activePlayer_)->getHand().size() == 0) {
        //clean up the round
        game->updateScores();

        notifyRoundEnd();

        if (!checkEnd()) {
            game->nextRound();
            //set first player
            activePlayer_ = game->getFirstPlayer();

            //run player rounds
            playTurn();
        }
        else {
            quitGame();
        }
    }
    else {
        //update board, show human player's hand 
        notifyDrawHand();
    }
}

// Start a new game
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
 	//destroy game if (!gameIsNull()) 
 	delete game;
    game = NULL;

  	notifyGameStartEnd();
}

// Play or discard card
void Model::cardPlayDiscard (int card, bool legal) {
    //play or discard the card
    if (legal) {
        game->getPlayer(activePlayer_)->playCard(game->getPlayer(activePlayer_)->getHand()[card]);
    }
    else {
        game->getPlayer(activePlayer_)->discardCard(game->getPlayer(activePlayer_)->getHand()[card]);
    }

    //move on to next player
    activePlayer_ = (activePlayer_+1)%4;
    playTurn();
}

// Rage quit
void Model::ragePlayer () {
	//ragequit
    game->rageQuit(activePlayer_);
    setPlayerType(activePlayer_);
    playTurn();
}

// Return Winners
std::string Model::getWinners () {
    int winScore = game->getMinScore();
    std::ostringstream winners;   // stream used for the conversion
    for (int i = 0; i < 4; i++) {
        if (game->getScore(i) == winScore) 
            winners << "Player " << i + 1 << " wins!" << std::endl;
    }
    return winners.str();
}

// Returns true if no game exists
bool Model::gameIsNull () {
    return game == NULL;
}

// Checks if game is over
bool Model::checkEnd () {
    return game->checkEnd();
}

// returns the type of player (human or computer)
bool Model::getPlayerType (int player) {
    return playerType_[player];
}

// Set the player type to human or computer
void Model::setPlayerType (int player) {
    playerType_[player] = !playerType_[player];
}

// Get player score
int Model::getScore (int player) {
    return game->getScore(player);
}

// Return player with current turn
int Model::getActivePlayer () {
    return activePlayer_;
}

// Get played cards
Played* Model::getPlayed () {
    return game->getPlayedCards();
}

// Get player
Player* Model::getPlayer (int player) {
    return game->getPlayer(player);
}



