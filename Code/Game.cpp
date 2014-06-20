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
        for (int i = 0; i < NUM_CARDS; i++) {
            game.playerTurn( (whosTurn+i) % NUM_PLAYERS );
        }
        game.updateScores();
        end = game.checkEnd();
    }

    int winScore = game.getMinScore();
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (game.getScore(i) == winScore) 
            std::cout << "Player " << i + 1 << " wins!" << std::endl;
    }

    return 0;
}


