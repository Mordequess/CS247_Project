#include "Player.h"
#include <algorithm>

Player::Player(int number) {
	score_ = 0;
	plnumber_ = number;
}

void Player::setHand(std::vector<Card*> playerhand) {
	hand_ = playerhand;
}

void Player::playCard(Card card) {
	if(card.getSuit() == 0 ) {
		played_.playedClub[card.getRank()] = true;
	} else if (card.getSuit() == 1) {
		played_.playedDiamond[card.getRank()] = true;
	} else if (card.getSuit() == 2) { //
		played_.playedHeart[card.getRank()] = true;
	} else if (card.getSuit() == 3) { //SPades
		played_.playedSpade[card.getRank()] = true;
	} else {
		throw "No card was marked as played";
	}
}


int Player::getScore() {
	return score_;
}

int Player::incrementScore () {
	int scoreIncrement = 0;
	for(int i = 0; i < discarded_.size(); i++){
		scoreIncrement += discarded_[i].getRank() + 1;
	}
	score_ += scoreIncrement; 
	return scoreIncrement;
}

std::vector<Card*> Player::getHand() {
	return hand_;
}

std::vector<Card*> Player::getDiscard() {
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

bool Player::inHand (Card card) {

	return (std::find(hand_.begin(), hand_.end(), card) != hand_.end());
}

void Player::discardCard(Card &card) {
	discarded_.push_back(card);
	std::vector<Card*>::iterator position = find(hand_.begin(), hand_.end(), card);
    hand_.erase(position);
}


bool Player::isLegal(Card) {
	return true;
}
//play card needs to modify played_ and remove card from hand
