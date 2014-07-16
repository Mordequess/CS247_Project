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
#include <iostream>

// Creates buttons with labels. Sets Vpanel elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_(m), controller_(c), table(4, 13, true), hand_table(1, 13, true), card(deck.null()) {

	//set initial values for all elements
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			tableCards[j + i*13].set(deck.null()); 	//deck.null() or deck.image(j*4 + i)
		}
	}
	for (int i = 0; i < 13; i++) {
		handImages[i].set(deck.null()); 			
		handButtons[i].set_image(handImages[i]); 	//set hand buttons to be card backs
	}

	players[0].set_label("Player 1");
	players[1].set_label("Player 2");
	players[2].set_label("Player 3");
	players[3].set_label("Player 4");

    
    nameLabel.set_text("Enter Seed: ");
    nameField.set_text( "0" );

	frame.set_label( "Cards Played:" );
	frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );

	for (int i = 0; i < 4; i++){
		playerType[i].signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &View::playerTypeButtonClicked), i));
	}

	players[0].set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	
	startgame.set_label("Start new game with seed");
	endgame.set_label("End current game");

	// Sets some properties of the window.
    set_title("Straights Game");
	set_default_size(760, 500);

    //add elements to the shell and views
	shell.add ( hbox_1 );

    // Add the text entry widget to the dialog box.
    // Add the text entry widget to the vertical box section of the dialog box.
	hbox_1.add ( startgame );
	hbox_1.add ( hbox_2 );
	hbox_2.add ( nameLabel );
	hbox_2.add ( nameField );
	hbox_1.add ( endgame );


	for(int i = 0; i < 4; i ++) {
		score[i].set_label("Score: ");
		discards[i].set_label("Discards: ");
	}
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
	}


	add ( shell );
	show_all();

	// Register view as observer of model
	model_->subscribe(this);

} // View::View

View::~View() {}


void View::update0() {
}

void View::update1() {
}

void View::update2() {
}

void View::nextButtonClicked() {
  //controller_->nextButtonClicked();
} // View::nextButtonClicked

void View::playerTypeButtonClicked(int playerNum) {
	 std::string text = playerType[playerNum].get_label();
	if (text == "Computer")
		playerType[playerNum].set_label("Human");
	else if (text == "Human")
		playerType[playerNum].set_label("Computer");


	//playerType[playerNum].set_label("Human");
}

void View::resetButtonClicked() {
  //controller_->resetButtonClicked();
} // View::resetButtonClicked
