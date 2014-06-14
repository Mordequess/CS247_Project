#include "player.h"

Player::Player() {
	score_ = 0;
	hand_ = NULL;
	discarded_ = NULL;
	number = plnumber_;
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
	discard_ = discard;
}

vector<Card> Player::legalPlays(vector<Card> currHand, Played &p){
	vector<Card> = legalCards;
	for (int i = 0; i < currHand.size(); i++){
		if (isLegal(currHand[i], p)){
			legalCards.push_back(currHand[i]);
		}
	}
}

bool Player::inHand (Card &card) {
	return (find(hand_.begin(), hand_.end(), card));
}



vector<Card> Player::discardCard(Card &card) {
	discarded_.push_back(card);
	std::vector<Card>::iterator position = find(hand_.begin(), hand_.end(), card);
    hand_.erase(position);
}



//play card needs to modify played_ and remove card from hand
