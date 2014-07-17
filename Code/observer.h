/*
* Observer class.  Abstract class for Observer Pattern
*
*
*  Created by Jo Atlee on 06/07/09.
*  Copyright 2009 UW. All rights reserved.
*
*/


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