CXX= g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags`
LDFLAGS=`pkg-config gtkmm-2.4 --libs`
OBJS = subject.o model.o controller.o DeckGUI.o view.o Card.o Command.o Computer.o Deck.o Human.o Played.o Player.o Straights.o main.o
EXEC = straights

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(CXXFLAGS) -o $(EXEC)



clean:
	rm $(EXEC) $(OBJS)
	rm -f straights

all: straights


DeckGUI.o: DeckGUI.h DeckGUI.cpp
model.o: subject.h model.h model.cpp
subject.o: subject.h subject.cpp
controller.o: controller.h model.h controller.cpp
view.o: view.h observer.h controller.h model.h subject.h DeckGUI.h view.cpp
main.o: view.h controller.h model.h main.cpp
Card.o: Card.cpp Card.h
Command.o: Command.cpp Command.h Card.h
Computer.o: Computer.cpp Computer.h Player.h Card.h Played.h 
Deck.o: Deck.cpp Deck.h Card.h 
Human.o: Human.cpp Human.h Command.h Card.h Player.h Played.h
Played.o: Played.cpp Played.h Card.h
Phlayer.o: Player.cpp Player.h Card.h Played.h
Straights.o: Straights.cpp Straights.h Deck.h Card.h Played.h Player.h Human.h Computer.h

