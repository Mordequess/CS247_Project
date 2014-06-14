#include <iostream>
#include "Straights.h"

using namespace std;

int main() {
    Straights game = new Straights(0); //*** retrieve input from std::string[args]?
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
        if (game.getScore(i) == winScore) std::cout << "Player " << winner << " wins!" << std::endl;
    }
}

/*
if (card.getRank() == "7") return true;
if (card.getRank() == "A")     //[suit][rank]
if (card.getSuit() == "CLUB") return (played_.playedClub[card.getRank()-1] || played_.playedClub[card.getRank()+1]);
if (card.getSuit() == "HEART") return (played_.playedHeart[card.getRank()-1] || played_.playedHeart[card.getRank()+1]);
if (card.getSuit() == "DIAMOND") return (played_.playedDiamond[card.getRank()-1] || played_.playedDiamond[card.getRank()+1]);
if (card.getSuit() == "SPADE") return (played_.playedSpade[card.getRank()-1] || played_.playedSpade[card.getRank()+1]);

*/