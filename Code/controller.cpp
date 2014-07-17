/*
 * MVC example of GTKmm program
 *
 * Controller class.  Is responsible for translating UI events (from the View)
 * into method calls to the Model.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}

void Controller::playerTypeButtonClicked(int player) {
	if (model_->gameIsNull()){
		model_->setPlayerType(player);
	}
	else {
		//rage
		model_->ragePlayer();
	}
}

void Controller::cardButtonClicked(int card, bool legal) {
	model_->cardPlayDiscard(card, legal);
} 

void Controller::startGameButtonClicked(int seed) {
	model_->startGame(seed);
} 

void Controller::endGameButtonClicked() {
	model_->quitGame();
} 

