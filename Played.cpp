#include "Played.h"
#include <sstream>
using namespace std;

ostream &operator<<(ostream &out, Played &p){
	out << "Cards on the table:" << endl << "Clubs:";
	for (int i = 0; i < 13; i++) {
		if (p.playedClub[i]) cout << " " << rank[i];
	}
	out << endl << "Diamonds:";
	for (int i = 0; i < 13; i++){
		if (p.playedDiamond[i]) cout << " " << rank[i];
	}
	out << endl << "Hearts:";
	for (int i = 0; i < 13; i++) {
		if (p.playedHeart[i]) cout << " " << rank[i];
	}
	out << endl << "Spades:";
	for (int i = 0; i < 13; i++) {
		if (p.playedSpade[i]) cout << " " << rank[i];
	}

	return out;
}

// bool[13] playedHeart;
// bool[13] playedClub;
// bool[13] playedSpade;
// bool[13] playedDiamond;
