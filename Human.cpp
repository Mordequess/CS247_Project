#include "Human.h"

Human::Human() { 
	Player();
}

void Human::print() {
	cout << played_ << endl;
	vector<Card> currHand = getHand();
	cout << "Your hand:";
	for (int i = 0; i < currHand.size() ; i++) {
		cout << " " << currHand[i];
	}
	cout "\n";
	
}