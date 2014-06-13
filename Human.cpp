#include "Human.h"

Human::Human() { 
	Player();
}

void Human::print() {
	cout << played_;
	vector<Card> currHand= getHand();
	for (int i = 0; i < currHand.size() ; i++) {
		
	}
}