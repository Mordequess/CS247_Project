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

void Player::playCard(Card card) {
	if(card.getSuit()) == "CLUB") {
		played_.playedClub[card.getRank()] = true;
	} else if (card.getSuit() == "DIAMOND") {
		played_.playedDiamond[card.getRank()] = true;
	} else if (card.getSuit() == "HEART") {
		played_.playedHeart[card.getRank()] = true;
	} else if (card.getSuit() == "SPADE") {
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
	for(int i = 0; i < discard_.size(0; i++)){
		scoreIncrement += discard[i].getRank() + 1;
	}
	score_ += scoreIncrement; 
	return scoreIncrement;
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

void Player::discardCard(Card &card) {
	discard_.push_back(card);
	std::vector<Card>::iterator position = find(hand_.begin(), hand_.end(), card);
    hand_.erase(position);
}


bool Player::isLegal(Card, Played) {
	return true;
}
//play card needs to modify played_ and remove card from hand
