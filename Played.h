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
	for (int i = 0; i < 13; i++) {
		playedDiamond[i] = false;
		playedHeart[i] = false;
		playedSpade[i] = false;
		playedClub[i] = false;
	}
}

std::ostream &operator<<(std::ostream &, const Played &);

#endif
