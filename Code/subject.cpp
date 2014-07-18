#include <set>
#include "subject.h"
#include "observer.h"

void Subject::subscribe (Observer *newView) {
    observers_.insert(newView);
}


void Subject::unsubscribe (Observer *formerView) {
     observers_.erase(formerView);
}


void Subject::notifyGameStartEnd() {
  Observers::iterator i;
  for (i = observers_.begin(); i != observers_.end(); ++i)
    (*i)->updateGameStartEnd();
}

void Subject::notifyDrawHand() {
  Observers::iterator i;
  for (i = observers_.begin(); i != observers_.end(); ++i)
    (*i)->updateDrawHand();
}

void Subject::notifyRoundEnd() {
  Observers::iterator i;
  for (i = observers_.begin(); i != observers_.end(); ++i)
    (*i)->updateRoundEnd();
}

void Subject::notifyCardPlayed() {
  Observers::iterator i;
  for (i = observers_.begin(); i != observers_.end(); ++i)
    (*i)->updateCardPlayed();
}
