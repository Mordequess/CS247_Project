#include "Played.h"
#include <sstream>
using namespace std;

ostream &operator<<(ostream &out, Played &p){
	out << "Cards on the table:" << std::endl << "Clubs:";
	for (int i = 0; i < 13; i++) {
		if (p.playedClub[i]) std::cout << " " << rank[i];
	}
	out << std::endl << "Diamonds:";
	for (int i = 0; i < 13; i++){
		if (p.playedDiamond[i]) std::cout << " " << rank[i];
	}
	out << std::endl << "Hearts:";
	for (int i = 0; i < 13; i++) {
		if (p.playedHeart[i]) std::cout << " " << rank[i];
	}
	out << std::endl << "Spades:";
	for (int i = 0; i < 13; i++) {
		if (p.playedSpade[i]) std::cout << " " << rank[i];
	}

	return out;
}

// bool[13] playedHeart;
// bool[13] playedClub;
// bool[13] playedSpade;
// bool[13] playedDiamond;
