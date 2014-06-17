#include "Player.h"



// Player constructor. Passes player number and reference to all played cards 
Player::Player(int number, Played* played) {
	hand_ = std::vector<Card*>();
	discarded_ = std::vector<Card*>();
	score_ = 0;
	playernum_ = number + 1;
	played_ = played; 
}

Player::~Player(){ 
	delete played_;
}

// Play a card, erase it from hand
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

// Discard a card, removes card from hand, places in discard 
void Player::discardCard(Card* card) {
	std::vector<Card*>::iterator it;
	int j = 0;
	for (it = hand_.begin(); it < hand_.end(); it++) {
		if (*card == *hand_[j]) {
			discarded_.push_back(hand_[j]);
			break;
		}
		j++;
	}
    hand_.erase(it);
}


// Get the player's hand, returns vector of cards
std::vector<Card*> Player::getHand() {
	return hand_;
}

// Set the players hand from the deck
void Player::setHand(std::vector<Card*> playerhand) {
	hand_ = playerhand;
}


// Determine if a card is in the players hand
bool Player::inHand (Card* card) {
	//find if card is in hand
	bool found = false;
	for (int i = 0; i < hand_.size(); i++) {
		if (*card == *hand_[i]) {
			found = true;
		}
	}
	return found;
}


// Return a vactor of legal plays for the player
std::vector<Card*> Player::legalPlays(std::vector<Card*> currHand){
	std::vector<Card*> legalCards;
	for (int i = 0; i < currHand.size(); i++){
		if (played_->isLegal(*currHand[i])) {
			legalCards.push_back(currHand[i]);
		}
	}
	return legalCards;
}


// Get the cards that a player has discarded, used for scoring
std::vector<Card*> Player::getDiscarded() {
	return discarded_;
}

// Set discard pile if computer takes over. TODO: Copy constructor
void Player::setDiscard(std::vector<Card*> discard) {
	discarded_ = discard;
}


// Get the player score
int Player::getScore() {
	return score_;
}

// Increment the player score, return amount that score was incremented
int Player::incrementScore() {
	int scoreIncrement = 0;
	for(int i = 0; i < discarded_.size(); i++){
		scoreIncrement += discarded_[i]->getRank() + 1;
	}
	score_ += scoreIncrement; 
	return scoreIncrement;
} 

int Player::getPlayerNum() {
	return playernum_;
}

Played* Player::getPlayed() {
	return played_;
}