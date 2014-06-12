#include <iostream>
#include "Card.h"

Straights::Straights (){
	deck_ = new Deck();
    invitePlayers();
    

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

// Player[4] players;
// Deck deck_;
