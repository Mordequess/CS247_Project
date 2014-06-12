#ifndef PLAYED_H
#define PLAYED_H

#include <istream>

enum rank = {"A", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "J", "Q", "K"};

struct Played{
	bool[13] playedHeart;
	bool[13] playedClub;
	bool[13] playedSpade;
	bool[13] playedDiamond;
	
	Played() : playedDiamond({false}), playedHeart({false}),playedSpade({false}),playedClub({false}) {}
};

std::ostream &operator<<(std::ostream &, const Played &);

#endif
