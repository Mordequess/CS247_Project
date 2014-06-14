#include "Human.h"

Human::Human() : Player(pl) { }

void Human::print() {
	cout << played_ << endl;
	vector<Card> currHand = getHand();
	cout << "Your hand:";
	for (int i = 0; i < currHand.size() ; i++) {
		cout << " " << currHand[i];
	}
	cout "\n";
	cout << "Legal plays:";
	for (int i = 0; i < currHand.size() ; i++) {
		if (isLegal(currhand[i])) {
			cout << " " << currhand[i];
		}
	}
	cout "\n";
}

void Human::playerTurn() {
	
}

