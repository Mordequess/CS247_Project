CXX_FLAGS=-g -Wall

GTEST_DIR=~/Programming/gtest
GTEST_FLAGS=-isystem $(GTEST_DIR)/include -pthread
GTEST_LIBS=$(GTEST_DIR)/lib/*


.SUFFIXES:
.SUFFIXES: .o .cpp

.cpp.o:
	${CXX} $(CXX_FLAGS) -c $<


all: straights

test: a2q2_test


straights: Card.o Command.o Computer.o Deck.o Human.o Played.o Player.o Straights.o T_Harness.cpp 
	${CXX} $(CXX_FLAGS) $^ -o $@

a2q2_test: UserAccountTests.cpp UserAccount.o Password.o Userid.o 
	${CXX} $(GTEST_FLAGS) $(CXX_FLAGS) $^ $(GTEST_LIBS) -o $@;
	-./$@


clean:
	rm -f *.o
	rm -f straights
