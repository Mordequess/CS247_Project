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
if (card.getRank() == "7") return true;
if (card.getRank() == "A")     //[suit][rank]
if (card.getSuit() == "CLUB") return (played_.playedClub[card.getRank()-1] || played_.playedClub[card.getRank()+1]);
if (card.getSuit() == "HEART") return (played_.playedHeart[card.getRank()-1] || played_.playedHeart[card.getRank()+1]);
if (card.getSuit() == "DIAMOND") return (played_.playedDiamond[card.getRank()-1] || played_.playedDiamond[card.getRank()+1]);
if (card.getSuit() == "SPADE") return (played_.playedSpade[card.getRank()-1] || played_.playedSpade[card.getRank()+1]);




PLAYED SHOWS ADDRESS
Implement is Valid







*/