#ifndef PLAYED_H
#define PLAYED_H

#include <istream>

struct Played{
	Played();
	void resetBoard();

	bool playedHeart[13];
	bool playedClub[13];
	bool playedSpade[13];
	bool playedDiamond[13];
};





std::ostream &operator<<(std::ostream &, Played const &);

#endif
