#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}

// Control player type // rage quit button clicked
void Controller::playerTypeButtonClicked(int player) {
	if (model_->gameIsNull()){
		model_->setPlayerType(player);
	}
	else {
		//rage
		model_->ragePlayer();
	}
}

// Player clicks on a card in hand
void Controller::cardButtonClicked(int card, bool legal) {
	model_->cardPlayDiscard(card, legal);
} 

// Player clicks button to start game
void Controller::startGameButtonClicked(int seed) {
	model_->startGame(seed);
} 

// Game is ended
void Controller::endGameButtonClicked() {
	model_->quitGame();
} 

