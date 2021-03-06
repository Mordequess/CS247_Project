#include "DeckGUI.h"
#include <algorithm>
#include <iterator>
#include <string>
using std::string;
using std::transform;

// Sets up an array of the Portable Network Graphics (PNG) file names that contain the necessary card images.
// The deck will load the contents into pixel buffers for later use.
const char * image_names[] = {
	// Set up A of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_0.png", "cards_png/1_0.png", "cards_png/2_0.png", "cards_png/3_0.png",
	// Set up 2 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_1.png", "cards_png/1_1.png", "cards_png/2_1.png", "cards_png/3_1.png",
	// Set up 3 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_2.png", "cards_png/1_2.png", "cards_png/2_2.png", "cards_png/3_2.png",
	// Set up 4 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_3.png", "cards_png/1_3.png", "cards_png/2_3.png", "cards_png/3_3.png",
	// Set up 5 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_4.png", "cards_png/1_4.png", "cards_png/2_4.png", "cards_png/3_4.png",
	// Set up 6 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_5.png", "cards_png/1_5.png", "cards_png/2_5.png", "cards_png/3_5.png",
	// Set up 7 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_6.png", "cards_png/1_6.png", "cards_png/2_6.png", "cards_png/3_6.png",
	// Set up 8 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_7.png", "cards_png/1_7.png", "cards_png/2_7.png", "cards_png/3_7.png",
	// Set up 9 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_8.png", "cards_png/1_8.png", "cards_png/2_8.png", "cards_png/3_8.png",
	// Set up 10 of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_9.png", "cards_png/1_9.png", "cards_png/2_9.png", "cards_png/3_9.png",
	// Set up J of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_10.png", "cards_png/1_10.png", "cards_png/2_10.png", "cards_png/3_10.png",
	// Set up Q of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_11.png", "cards_png/1_11.png", "cards_png/2_11.png", "cards_png/3_11.png",
	// Set up K of {CLUB,DIAMOND,HEART,SPADE}
	"cards_png/0_12.png", "cards_png/1_12.png", "cards_png/2_12.png", "cards_png/3_12.png",

	// Set up the back of a card for a place holder/null card
	"cards_png/back_1.png"
}; 

// Loads the image from the specified file name into a pixel buffer.
Glib::RefPtr<Gdk::Pixbuf> createPixbuf(const string & name) {
	return Gdk::Pixbuf::create_from_file( name );
} // createPixbuf

DeckGUI::DeckGUI()  {
	// Images can only be loaded once the main window has been initialized, so cannot be done as a static
	// constant array. Instead, use the STL transform algorithm to apply the method createPixbuf to every
	// element in the array of image names, starting with first and ending with the last. New elements are
	// added to the back of deck.
	transform( &image_names[0], &image_names[G_N_ELEMENTS(image_names)], 
			   std::back_inserter(deck), &createPixbuf );
} // DeckGUI::DeckGUI

DeckGUI::~DeckGUI() {
} // DeckGUI::~DeckGUI

// Returns the image for the specified card.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::image(int index) {
	return deck[ index ];
} // DeckGUI::getCardImage 

// Returns the image to use for the placeholder.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::null() {
	int size = deck.size();
	return deck[ size-1 ];
} // DeckGUI::getNullCardImage
