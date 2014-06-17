#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Played.h"

#include <iostream>
#include <vector>

class Player {
public:
	Player(int number, Played* played);  				// Constructor takes player number, pointer to played cards
	virtual ~Player();									// Virtual Destructor
	virtual void playTurn(bool) = 0;					// Vitrual Playturn called by child class
	void playCard(Card*); 								// Play card from hand 
	void discardCard(Card*);							// Discard card from hand
	
	std::vector<Card*> getHand();						// Return Player's hand
	void setHand(std::vector<Card*>);					// Set player's hand	
	bool inHand(Card*);									// Checks if a card is in the player's hand

	std::vector<Card*> getDiscarded(); 					// Returns vector of discarded cards 
	void setDiscard(std::vector<Card*>);				// Sets player discard
	
	std::vector<Card*> legalPlays(std::vector<Card*>);  // Returns vector of legal plays
	
	int getScore();										// Accessor for player's score
	int incrementScore(); 								// Mutator - Increments player score, returns amount it was incremented

	
// TODO make functions protected
protected:
	int plnumber_; 										// playernumber 1-4
	// TODO move to private
	Played* played_;
private:

	std::vector<Card*> hand_;							// Player hand
	std::vector<Card*> discarded_;						// Discarded cards, reset each round
	int score_;											// Player score
};		

#endif
