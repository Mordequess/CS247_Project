#include <iostream>
#include "Straights.h"
#include <stdlib.h>

using namespace std;

//int main(int argc, char* argv[]) {
    //int test = 0;
/*    if (argc >= 2) {
        srand48(atoi(argv[1]));
    }
    else srand48(0);
*/
   // int seedfdsfsdalkjfhsdakjfsdahfsdkjhflkjsdaf;


//int main(int argc, char* argv[]) {
int main() {
    //srand48(seed);
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
            catch (...) {
                exit(0);
            }
        }
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
