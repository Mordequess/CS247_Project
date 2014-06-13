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
    Straights game = new Straights(0); //*** retrieve input from string[args]?
    int whosTurn = game.getFirstPlayer();
    //get first command
    Command command;
    cin >> command;
    
    bool quit = false;
    while (!cin.eof()) {
        switch (command.type) {
    
            //play a card
            case PLAY: {
                game.playCard(whosTurn, command.card);
                turnIncrement(whosTurn);
                break;
            }
            
            //discard a card
            case DISCARD: {
                game.discardCard(whosTurn, command.card);
                turnIncrement(whosTurn);
                break;
            }
                
            //print the deck
            case DECK: {
                game.printDeck();
                break;
            }
                
            //exit program
            case QUIT: {
                quit = false;
                break;
            }

            //replace current human player with a computer
            case RAGEQUIT: {
                game.rageQuit(whosTurn);
                break;
            }
                
            default:
                break;
        } // switch
					
    //get next command
    if (quit) break;
    cin >> command;
        
    } // while cin OK
    
    //***delete game?
    return 0;
}