#ifndef MVC_SUBJECT_H
#define MVC_SUBJECT_H

#include <set>


class Observer;

class Subject {
public:
       void subscribe( Observer* );
       void unsubscribe( Observer* );

protected:
       void notifyGameStartEnd();
       void notifyDrawHand();
       void notifyCardPlayed();
       void notifyRoundEnd();

private:
       typedef std::set< Observer* > Observers;
       Observers observers_;
}; // Subject


#endif
