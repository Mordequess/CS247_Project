/*
 * MVC example of GTKmm program
 *
 * View class.  Is responsible for buttons (that user clicks) and for displaying
 * the top card of the deck.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"

#include <cstring>
#include <iostream>

// Creates buttons with labels. Sets Vpanel elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_(m), controller_(c), table(4, 13, true), hand_table(1, 13, true), card(deck.null()) {

	//set initial values for all elements
	setNullCards();
	setScoreZero();
	setDiscardZero();

	players[0].set_label("Player 1");
	players[1].set_label("Player 2");
	players[2].set_label("Player 3");
	players[3].set_label("Player 4");

    
    nameField.set_text( "0" );

	frame.set_label( "Cards Played:" );
	frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );

	for (int i = 0; i < 4; i++){
		playerType[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &View::playerTypeButtonClicked), i));
	}

	players[0].set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	
	startgame.set_label("Start new game with seed:");
	startgame.signal_clicked().connect( sigc::mem_fun( *this, &View::startGameButtonClicked ) );
	endgame.set_label("End current game");
	endgame.set_sensitive(false);
	endgame.signal_clicked().connect( sigc::mem_fun( *this, &View::endGameButtonClicked ) );

	// Sets some properties of the window.
    set_title("Straights Game");
	set_default_size(760, 500);

    //add elements to the shell and views
	shell.add ( hbox_1 );

    // Add the text entry widget to the dialog box.
    // Add the text entry widget to the vertical box section of the dialog box.
	hbox_1.add ( startgame );
	hbox_1.add ( hbox_2 );
	hbox_2.add ( nameField );
	hbox_1.add ( endgame );

	// Add the horizontal box for laying out the images to the frame.
	shell.add ( frame );
	frame.add( table );

	for (int i = 0; i < 52; i++) {
      table.attach(tableCards[i], i % 13, (i % 13) + 1, i / 13, (i / 13) + 1);
	}

	playerbox.set_homogeneous(true);

	shell.add ( playerbox );
	for (int i = 0; i < 4; i ++) {
		playerbox.add ( players[i] );
		players[i].add(play[i]);	
		playerType[i].set_label("Human");
		play[i].add(playerType[i]);
		play[i].add(score[i]);
		play[i].add(discards[i]);
	}
	
	playerhand_frame.set_label( "Current Hand:" );
	playerhand_frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	shell.add(playerhand_frame);
	playerhand_frame.add(hand_table);

	for (int i = 0; i < 13; i++) {
     	hand_table.attach(handButtons[i], i % 13, (i % 13) + 1, i / 13, (i / 13) + 1);
		handButtons[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &View::cardButtonClicked), i));
		handButtons[i].set_sensitive(false);
	}


	add ( shell );
	show_all();

	// Register view as observer of model
	model_->subscribe(this);

} // View::View

void View::setNullCards() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			tableCards[j + i*13].set(deck.null()); 	//deck.null() or deck.image(j*4 + i)
		}
	}
	for (int i = 0; i < 13; i++) {
		handImages[i].set(deck.null()); 			
		handButtons[i].set_image(handImages[i]); 	//set hand buttons to be card backs
	}
}

void View::setScoreZero() {
	for(int i = 0; i < 4; i ++) {
		score[i].set_label("Score: 0");
	}
}

void View::setDiscardZero() {
	for(int i = 0; i < 4; i ++) {
		discards[i].set_label("Discards: 0");
	}
}

View::~View() {}

void View::updateRoundEnd() {
	//reset discards, set score
	for (int i = 0; i < 4; i++){
		Player* active = model_->getPlayer(i);
		discards[i].set_label("Discards: 0");
		score[i].set_label("Score: " + convert(active->getScore()));
	}
	setDiscardZero();

	//clear table
	setNullCards();


	Gtk::Dialog dialog( "Round Results", *this );
	Gtk::VBox* contentArea = dialog.get_vbox();

	for (int i = 0; i < 4; i++) {
		Player* active = model_->getPlayer(i);

		roundDiscard[i].set_label("Player " +  convert(i +1) + "'s discards: " + convert(active->getDiscarded()));
		roundDiscard[i].set_justify( Gtk::JUSTIFY_LEFT);
		contentArea->pack_start(roundDiscard[i], true, false );
		roundDiscard[i].show();

		roundScore[i].set_label("Player " +  convert(i +1) + "'s score: " + convert(active->getScore()) + "\n");
		roundScore[i].set_justify( Gtk::JUSTIFY_LEFT);
		contentArea->pack_start(roundScore[i], true, false );
		roundScore[i].show();
	}


	if (model_->checkEnd()){
		extra.set_label(model_->getWinners());
	}
	else {
		extra.set_label("A new round begins. It's player " + convert(model_->getActivePlayer() + 1) + "'s turn to play.");
	}
	extra.set_justify( Gtk::JUSTIFY_LEFT);
	contentArea->pack_start(extra, true, false );
	extra.show();
    std::cout << "I have ended a round" << std::endl;  
    dialog.add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);

    int result = dialog.run();
    std::string name;
    switch (result) {
        case Gtk::RESPONSE_OK:
        case Gtk::RESPONSE_ACCEPT:
            name = nameField.get_text();
            std::cout << "Entered '" << name << "'" << std::endl;
            break;
        case Gtk::RESPONSE_CANCEL:
            std::cout << "dialog cancelled" << std::endl;
            break;
        default:
            std::cout << "unexpected button clicked" << std::endl;
            break;
    } // switch
	//show dialogue
	//list scores, discards
	//list winners if game over
	//else list first player for next round
}


void View::updateGameStartEnd() {
	setNullCards();
	setScoreZero();
	setDiscardZero();
	if (!model_->gameIsNull()){
		//disable all player buttons, set human buttons to rage
		for(int i = 0; i < 4; i ++) {
			playerType[i].set_sensitive(false);
			if (!model_->getPlayerType(i)) playerType[i].set_label("Rage Quit");
		}
		endgame.set_sensitive(true);
	}
	else {
		endgame.set_sensitive(false);
		//disable hand
		for(int i = 0; i < 13; i ++) {
			handButtons[i].set_sensitive(false);
			handImages[i].set(deck.null());
		}
		//enable player buttons, set rage buttons to human/comp
		for(int i = 0; i < 4; i ++) {
			playerType[i].set_sensitive(true);
			if (!model_->getPlayerType(i)) playerType[i].set_label("Human");
		}
	}
}

void View::updateDrawHand() {
	//turn off rage button
	playerType[model_->getActivePlayer()].set_sensitive(true);

	Player* active = model_->getPlayer(model_->getActivePlayer());
	Played* table = model_->getPlayed();
	for (unsigned int i = 0; i < active->getHand().size(); i++) {
		//check if card is legal (or if no legal plays), make button clickable
		handButtons[i].set_sensitive(false);
		if (active->legalPlays(active->getHand()).size() == 0 || table->isLegal(*active->getHand()[i])) {
			handButtons[i].set_sensitive(true);
		}
		handImages[i].set(deck.image(active->getHand()[i]->getSuit() + active->getHand()[i]->getRank() * 4));
	}
	for (unsigned int i = active->getHand().size(); i < 13; i++) {
		handButtons[i].set_sensitive(false);
		handImages[i].set(deck.null());
	}
}

void View::updateCardPlayed() {
	Played* cards = model_->getPlayed();
	for (int i = 0; i < 4; i++) {

		Player* active = model_->getPlayer(i);
		discards[i].set_label("Discards: " + convert(active->getDiscarded().size()));


		for (int j = 0; j < 13; j++) {
			if(cards->playedCards[i][j] == true) {
				tableCards[j + i*13].set(deck.image(j*4 + i)); 	//deck.null() or deck.image(j*4 + i)
			}
		}
	}
}

void View::playerTypeButtonClicked(int playerNum) {
	if (model_->gameIsNull()){
		if (model_->getPlayerType(playerNum)) {
			playerType[playerNum].set_label("Human");
		}
		else {
			playerType[playerNum].set_label("Computer");
		}
	}
	else {
		//ragequit the player
		playerType[playerNum].set_label("Computer");
		playerType[playerNum].set_sensitive(false);
	}
	controller_->playerTypeButtonClicked(playerNum);
}

void View::startGameButtonClicked() {
	//startgame.set_label("Muffin");
	std::string name = nameField.get_text();
	int seed = atoi(name.c_str());
	std::cout << seed << std::endl;
	controller_->startGameButtonClicked(seed);
}


void View::endGameButtonClicked() {
	controller_->endGameButtonClicked();
}


void View::cardButtonClicked(int cardnum) {
	//turn off rage button
	playerType[model_->getActivePlayer()].set_sensitive(false);

	Player* active = model_->getPlayer(model_->getActivePlayer());
	Played* table = model_->getPlayed();
	controller_->cardButtonClicked(cardnum, table->isLegal(*active->getHand()[cardnum]));
}

std::string convert(int num) {
	std::ostringstream convert;   // stream used for the conversion
	convert << num;      // insert the textual representation of 'Number' in the characters in the stream
	return convert.str(); // set 'Result' to the contents of the stream
}

std::string convert(std::vector<Card*> cards) {
	std::ostringstream convert;   // stream used for the conversion
	for (unsigned int i = 0; i < cards.size(); i++) {
		convert << " " << *(cards[i]);
	}
	return convert.str(); // set 'Result' to the contents of the stream
}

//48x70