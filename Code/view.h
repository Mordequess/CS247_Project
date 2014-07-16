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


#ifndef MVC_VIEW_H
#define MVC_VIEW_H


#include <gtkmm.h>
#include "DeckGUI.h"
#include "observer.h"

class Controller;
class Model;


class View : public Gtk::Window, public Observer {
public:
        View( Controller*, Model* );
	virtual ~View();
	virtual void update0();	// Observer Pattern: concrete update() method
	virtual void update1();	// Observer Pattern: concrete update() method
	virtual void update2();	// Observer Pattern: concrete update() method

private:
	// Observer Pattern: to access Model accessors without having to downcast subject
	Model *model_;
	
	// Strategy Pattern member (plus signal handlers)
	Controller *controller_;

	// Card Images/
	DeckGUI deck;

	// Member widgets:

	Gtk::VBox shell;

	Gtk::HBox hbox_1;
	Gtk::Button startgame;
	Gtk::HBox hbox_2;
    Gtk::Entry   nameField;                  // Text entry for the user's name
    Gtk::Label   nameLabel;
	Gtk::Button endgame;

	Gtk::Frame frame; 
	Gtk::Table table;
	Gtk::Image tableCards[52];
	Gtk::Button handButtons[13];
	Gtk::Image handImages[13];
	
	//Gtk::Frame playerframe;
	Gtk::HBox playerbox;
	Gtk::Frame players[4];
	Gtk::VBox play[4];
	Gtk::Button playerType[4];
	Gtk::Label score[4];
	Gtk::Label discards[4];

	Gtk::Frame playerhand_frame;
	Gtk::Table hand_table;

	Gtk::Image card;

	// Signal handlers:
	void playerTypeButtonClicked(int playerNum);
	void startGameButtonClicked();
	void endGameButtonClicked();



}; // View

#endif
