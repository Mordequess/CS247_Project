CXX_FLAGS=-g -Wall

GTEST_DIR=~/Programming/gtest
GTEST_FLAGS=-isystem $(GTEST_DIR)/include -pthread -std=c++98
GTEST_LIBS=$(GTEST_DIR)/lib/*


.SUFFIXES:
.SUFFIXES: .o .cpp 

.cpp.o:
	${CXX} $(CXX_FLAGS) -c $<


all: straights

test: diffFileOutput


Card.o: Card.cpp Card.h
Command.o: Command.cpp Command.h Card.h
Computer.o: Computer.cpp Computer.h Player.h Card.h Played.h 
Deck.o: Deck.cpp Deck.h Card.h 
Human.o: Human.cpp Human.h Command.h Card.h Player.h Played.h
Played.o: Played.cpp Played.h Card.h
Player.o: Player.cpp Player.h Card.h Played.h
Straights.o: Straights.cpp Straights.h Deck.h Card.h Played.h Player.h Human.h Computer.h


straights: Card.o Command.o Computer.o Deck.o Human.o Played.o Player.o Straights.o T_Harness.cpp 
	${CXX} $(CXX_FLAGS) $^ -o $@

diffFileOutput:
	./straights 4 >> ourOutput.txt
	./straightspro 4 >> proOutput.txt
	diff ourOutput.txt proOutput.txt



clean:
	rm -f *.o
	rm -f straights
