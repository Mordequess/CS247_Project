#include <iostream>
#include "Straights.h"

using namespace std;

//******************************************************************
// Harness for Straights
//******************************************************************

int main() {
    Straights game = new Straights(0); //*** retrieve input from string[args]?
    int winner;
    bool end = false;
    while (!end) {
        game.newRound();
        int whosTurn = game.getFirstPlayer();
        
        //play out every card till no more in hand 
        for (int i = 0; i < 13; i++) {
            try {
                game.playerTurn( (whosTurn+j)%4 );
            }
            //check if quit command is called
            catch (std::string e) {
                end = true;
                break;
            }
        }
        //check if quit command is called
        if (end) break;

        game.updateScores();
        end = game.checkEnd();
    }
     //check for ties
    int winScore = game.getMinScore();
    for (int i = 0; i < 4; i++) {
        if (game.getScore(i) == winScore) cout << "Player " << winner << " wins!" << endl;
    }
}
