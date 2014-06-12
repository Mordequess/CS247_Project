#import "Card.h"
#import "Deck.h"
#import "Round.h"
#import "Player.h"

class Straights {
public:
	void invitePlayers();
	newRound();
	void updateScores();
	void shuffle();

private:
	Player[4] players;
	Deck deck_;
}