#ifndef PLAYED_H
#define PLAYED_H

#include <istream>

struct Played{
	bool playedHeart[13];
	bool playedClub[13];
	bool playedSpade[13];
	bool playedDiamond[13];
	
	Played();
};

Played::Played() {
	/*playedDiamond = {false};
	playedHeart = {false};
	playedSpade = {false};
	playedClub = {false}; */
}

std::ostream &operator<<(std::ostream &, const Played &);

#endif
