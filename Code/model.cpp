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


Model::Model() {
	playerType_ = {0,0,0,0};	//all players default to human
}

void Model::startGame(int seed) {
	//
 	notify();
}

void Model::quitGame() {
 	//
  	notify();
}

void Model::setPlayerType (int player) {
	playerType_[player] = !playerType_[player];
	notify();
}

void Model::ragePlayer (int player) {
	//ragequit
	//notify();
}
