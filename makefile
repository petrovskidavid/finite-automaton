
# David Petrovski
#

CXXFLAGS = -Wall -Werror -std=c++11

fa: nfa.o dfa.o fa_main.o
	g++ $(CXXFLAGS) -o fa nfa.o dfa.o fa_main.o

nfa.o: nfa.cc nfa.h

dfa.o: dfa.cc dfa.h

fa_main.o: fa_main.cc nfa.h dfa.h

clean:
	rm -f fa *.o
