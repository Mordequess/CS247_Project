#include "Player.h"
//#include <algorithm>

Player::Player(int number, Played* played) {
	hand_ = std::vector<Card*>();
	discarded_ = std::vector<Card*>();
	score_ = 0;
	plnumber_ = number + 1;
	played_ = played; 
}

Player::~Player(){
}
void Player::playTurn(bool ignore){
}

void Player::setHand(std::vector<Card*> playerhand) {
	hand_ = playerhand;
}

void Player::playCard(Card* card) {
	played_->setCard(*card);

	std::vector<Card*>::iterator it;
	int j = 0;
	for (it = hand_.begin(); it < hand_.end(); it++) {
		if (*card == *hand_[j]) {
			break;
		}
		j++;
	}
    hand_.erase(it);
}


int Player::getScore() {
	return score_;
}

int Player::incrementScore () {
	int scoreIncrement = 0;
	for(int i = 0; i < discarded_.size(); i++){
		scoreIncrement += discarded_[i]->getRank() + 1;
	}
	score_ += scoreIncrement; 
	return scoreIncrement;
}

std::vector<Card*> Player::getHand() {
	return hand_;
}

std::vector<Card*> Player::getDiscarded() {
	return discarded_;
}

void Player::setDiscard(std::vector<Card*> discard) {
	discarded_ = discard;
}

std::vector<Card*> Player::legalPlays(std::vector<Card*> currHand){
	std::vector<Card*> legalCards;
	for (int i = 0; i < currHand.size(); i++){
		if (isLegal(currHand[i])) {
			legalCards.push_back(currHand[i]);
		}
	}
	return legalCards;
}

bool Player::inHand (Card* card) {
	bool found = false;
	for (int i = 0; i < hand_.size(); i++) {
		if (*card == *hand_[i]) {
			found = true;
		}
	}
	return found;
}

void Player::discardCard(Card* card) {
	std::vector<Card*>::iterator it;
	discarded_.push_back(card);

//*** make function later
	int j = 0;
	for (it = hand_.begin(); it < hand_.end(); it++) {
		if (*card == *hand_[j]) {
			break;
		}
		j++;
	}
    hand_.erase(it);
}


bool Player::isLegal(Card* card) {
	return played_->isLegal(*card);
	return true;
}
//play card needs to modify played_ and remove card from hand
