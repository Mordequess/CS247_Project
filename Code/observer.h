#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;


class Observer {
public:
	virtual void updateGameStartEnd () = 0;
	virtual void updateRoundEnd () = 0;
	virtual void updateDrawHand () = 0;
	virtual void updateCardPlayed () = 0;
};


#endif