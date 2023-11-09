# Patrick Ging
# makefile

# executables
main: main.o Card.o Hand.o PointCard.o ActionCard.o Deck.o
	g++ -std=c++11 -o main main.o Card.o Hand.o PointCard.o ActionCard.o Deck.o

test: test.o Card.o Hand.o PointCard.o ActionCard.o Deck.o
	g++ -std=c++11 -o test test.o Card.o Hand.o PointCard.o ActionCard.o Deck.o


# .o files
main.o: main.cpp main.hpp
	g++ -std=c++11 -c main.cpp main.hpp

test.o: test.cpp
	g++ -std=c++11 -c test.cpp

card.o: Card.cpp Card.hpp
	g++ -std=c++11 -c Card.cpp Card.hpp

deck.o: Deck.cpp Deck.hpp
	g++ -std=c++11 -c Deck.cpp Deck.hpp

hand.o: Hand.cpp Hand.hpp
	g++ -std=c++11 -c Hand.cpp Hand.hpp

pointCard.o: pointCard.cpp PointCard.hpp Card.cpp Card.hpp
	g++ -std=c++11 -c PointCard.cpp PointCard.hpp Card.cpp Card.hpp

actionCard.o: ActionCard.cpp ActionCard.hpp Card.cpp Card.hpp
	g++ -std=c++11 -c ActionCard.cpp ActionCard.hpp Card.cpp Card.hpp
# misc
clean:
	rm ./main *.o ./*.gch ./test