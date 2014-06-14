#ifndef PLAYED_H
#define PLAYED_H

#include <istream>

enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
			EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT };

struct Played{
	bool[13] playedHeart;
	bool[13] playedClub;
	bool[13] playedSpade;
	bool[13] playedDiamond;
	
	Played() : playedDiamond({false}), playedHeart({false}),playedSpade({false}),playedClub({false}) {}
};

std::ostream &operator<<(std::ostream &, const Played &);

#endif
