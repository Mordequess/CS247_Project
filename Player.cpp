#include "player.h"

Player::Player() {
	score_ = 0;
	hand_ = NULL;
	discarded_ = NULL;
}

void Player::setHand(vector<Card> playerhand) {
	hand_ = playerhand;
}

int Player::getScore() {
	return score_;
}

void Player::incrementScore () {
	int scoreIncrement = 0;
	for(int i = 0; i < discard_.size(0; i++)){
		scoreIncrement = discard[i].getRank() + 1;
		score += scoreIncrement;
	}
}

vector<Card> Player::getHand() {
	return hand_;
}

vector<Card> Player::getDiscard() {
	return discard_;
}

vector<Card> Player::setDiscard(vector<Card> discard) {
	discard = discard_;
}



vector<Card> Player::discardCard(Card &card) {
	discarded_.push_back(card);
	std::v;ector<Card>::iterator position = std::find(vector.begin(), vector.end(), card);
    hand_.erase(position);
}

//play card needs to modify played_ and remove card from hand
