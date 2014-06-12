#include <iostream>

#include "Command.h"
#include "Deck.h"
#include "Player.h"
#include "Computer.h"
#include "Human.h"

using namespace std;


//************************************************************************
//  Test Harness Helper functions
//************************************************************************



//******************************************************************
// Harness for Straights
//******************************************************************

int main() {
    cout << "Harness for Straights Game:" << endl << endl;
    Straights game = new Straights();
    
    //get first command
    Command command;
    cin >> command;
    
    while ( !cin.eof() ) {
        switch (command.type) {
    
            //play a card
            case PLAY: {
            }
            
            //discard a card
            case DISCARD: {

            }
                
                
            //print the deck
            case DECK: {
            }
                
            //exit program
            case QUIT: {
            }


            //replace current human player with a computer
            case RAGEQUIT: {
            }
                
            default:
                break;
        } // switch
					
    //get next command	
    cout << "Command: ";
    Command command;
    cin >> command;
        
    } // while cin OK
    
    return 0;
}
