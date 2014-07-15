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
View::View(Controller *c, Model *m) : model_(m), controller_(c), table(13, 4, true), tableholder(10,true), card(deck.null()) {


	for (int i = 0; i < 52; i++) {
		buttons[i].set_label("Crd");
	}
	for (int i = 0; i < 4; i ++ ){
		players[i].set_label("Player");
	}
    
    
    // Add the text entry widget to the dialog box.
    // Add the text entry widget to the vertical box section of the dialog box.
      
    nameField.set_text( "Muffin" );

    nameLabel.set_text("Enter Seed: ");
    //nameField.show();

	frame.set_label( "Cards Played:" );
	frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	playerframe.set_label( "Players:" );
	playerframe.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	
	startgame.set_label("Start new game with seed");
	endgame.set_label("End current game");

	// Sets some properties of the window.
    set_title("Straights Game");
	set_border_width( 10 );
	set_default_size(800, 500);

	add ( shell );
	shell.add ( hbox_1 );
	shell.add ( frame );
	shell.add ( playerframe );

	hbox_1.add ( startgame );
	hbox_1.add ( hbox_2 );
	hbox_2.add ( nameLabel );
	hbox_2.add ( nameField );
	hbox_1.add ( endgame );

	playerframe.add (playerbox);
	for (int i = 0; i < 4; i ++) {
		playerbox.add ( players[i]);	
	}
	
	// Add the horizontal box for laying out the images to the frame.
	frame.add( table );

	//tableholder.add ( table );
	
	for (int i = 0; i < 52; i++) {
      table.attach(buttons[i], i % 13, (i % 13) + 1, i / 13, (i / 13) + 1);
	}
    
	// Add button box and card image to the panels
	//playedcards.add( table );
	/*playerhanded.add( deck1 );
	deck1.add( card );
	card.set( deck.null() );

	// Add buttons to the box (a container). Buttons initially invisible
	deck2.add( next_button);
	//Vpanel.add( next_button );
	//Vpanel.add( reset_button );


	// Associate button "clicked" events with local onButtonClicked() method defined below.
	//next_button.signal_clicked().connect( sigc::mem_fun( *this, &View::nextButtonClicked ) );
	//reset_button.signal_clicked().connect( sigc::mem_fun( *this, &View::resetButtonClicked ) );
	*/
	//table.show();

	// The final step is to display the buttons (they display themselves)
    nameField.show();

	show_all();

	// Register view as observer of model
	model_->subscribe(this);

} // View::View

View::~View() {}


void View::update() {
  Suits suit = model_->suit();
  Faces face = model_->face();
  if ( suit == NOSUIT ) 
    card.set( deck.null() );
  else
    card.set( deck.image(face, suit) );

}

void View::nextButtonClicked() {
  controller_->nextButtonClicked();
} // View::nextButtonClicked

void View::resetButtonClicked() {
  controller_->resetButtonClicked();
} // View::resetButtonClicked
