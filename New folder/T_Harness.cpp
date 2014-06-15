#include <iostream>
#include "Straights.h"

using namespace std;

int main() {
    Straights game = Straights(0); //*** retrieve input from std::string[args]?
    bool end = false;
    while (!end) {
        game.nextRound();
        int whosTurn = game.getFirstPlayer();
        
        //play out every card till no more in hand 
        for (int i = 0; i < 52; i++) {
            try {
                game.playerTurn( (whosTurn+i)%4 );
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
        if (game.getScore(i) == winScore) std::cout << "Player " << i + 1 << " wins!" << std::endl;
    }
}

/*

PLAYED SHOWS ADDRESS
Implement is Valid

*/
