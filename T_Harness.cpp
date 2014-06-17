#include <iostream>
#include "Straights.h"
#include <stdlib.h>


int main(int argc, char* argv[]) {
    if (argc >= 2) {
       srand48(atoi(argv[1]));
    }
    else { 
        srand48(0);
    }
    
    Straights game = Straights();
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
            catch (char const*) {
                exit(0);
            }
        }
        game.updateScores();
        end = game.checkEnd();
    }

    int winScore = game.getMinScore();
    for (int i = 0; i < 4; i++) {
        if (game.getScore(i) == winScore) 
            std::cout << "Player " << i + 1 << " wins!" << std::endl;
    }

    return 0;
}


