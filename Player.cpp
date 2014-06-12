#include "player.h"
#include <vector>

Player::Player() {
	score_ = 0;
	hand_ = NULL;
	discarded_ = NULL;
}
	
int Player::incrementScore (int score) {
	score_ += score;
	return score_;
}

vector<Card> Player::getHand(){
	return hand_;
}

vector<Card> Player::discardCard(Card &card) {
	discarded_.push_back(card);
	IntIterator i = find(cards.begin(), cards.end(), card)	
	hand_.erase(i);
}