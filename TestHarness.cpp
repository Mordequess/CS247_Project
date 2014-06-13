#include <iostream>
#include <cassert>

#include "Command.h"
#include "Straights.h"

using namespace std;


//************************************************************************
//  Test Harness Helper functions
//************************************************************************
void turnIncrement(int& whosTurn){
    whosTurn = (++whosTurn)%4;
}


//******************************************************************
// Harness for Straights
//******************************************************************

int main() {
    cout << "Harness for Straights Game:" << endl << endl;
    Straights game = new Straights();
    int whosTurn = game.getFirstPlayer();
    //get first command
    Command command;
    cin >> command;
    
    while ( !cin.eof() ) {
        switch (command.type) {
    
            //play a card
            case PLAY: {
                //command.card
                turnIncrement(whosTurn);
            }
            
            //discard a card
            case DISCARD: {
                turnIncrement(whosTurn);
            }
                
                
            //print the deck
            case DECK: {
                game.printDeck();
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
    cin >> command;
        
    } // while cin OK
    
    return 0;
}
