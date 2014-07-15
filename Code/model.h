/*
 * MVC example of GTKmm program
 *
 * Model class.  Is responsible keeping track of the deck of cards.  
 * It knows nothing about views or controllers.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"

const int numFaces = 13;
const int numSuits = 4;
const int numCards = numFaces * numSuits;

enum Faces { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, NOFACE };
enum Suits { CLUB, DIAMOND, HEART, SPADE, NOSUIT };

class Model : public Subject {
public:
    Model();
    Suits suit();
    Faces face();
    void nextCard();
    void resetCards();
private:
    int topCard_;
}; // Model


#endif
