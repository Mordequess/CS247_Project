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
    int winner;
    bool end = false;
    while (!end) {
        game.newRound();
        int whosTurn = game.getFirstPlayer();
        for (int i = 0; i < 13; i++) { //play out every card till no more in hand 
            try {
                game.playerTurn( (whosTurn+j) %4 );
            }
            catch (q_err) {
                end = true;
                break;
            }
        }
        if (end) break;
        game.updateScores();

        //check for ties***
        winner = game.checkWinner();
        if (winner > -1) {
            end = true;
            cout << "Player " << winner << " has won the game!" << endl;
        }
    }
}
