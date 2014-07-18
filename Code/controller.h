#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>

class Model;

class Controller {
public:
   Controller( Model* );
   void playerTypeButtonClicked(int player);
   void cardButtonClicked(int card, bool legal);
   void endGameButtonClicked();
   void startGameButtonClicked(int seed);
private:
   Model *model_;
}; // Controller


#endif

