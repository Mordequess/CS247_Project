#include <iostream>

#include "Deck.h"
#include "Players.h"
#include "Human.h"
#include "Computer.h"
#include "Round.h"

using namespace std;

Straights::Straights (){
	deck_ = new Deck();
    invitePlayers();
    round_ = new Round(players_, deck_);
}

void Straights::invitePlayers () {
	for (int i = 0; i < 4; i++) {
        cout << "Is player " + i + " a human(h) or a computer(c)?" << endl;
        char type;
        cin >> type;
        assert (type == 'h' || type == 'c');
        if (type == h) players[i] = new Human();
        else players[i] = new Computer();
    }
}

void Straights::printDeck() {
	cout << deck_;
}


// Player[4] players;
// Deck deck_;
// Played Played_
