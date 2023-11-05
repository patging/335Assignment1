# Patrick Ging
# makefile

# executables
main: main.o Card.o Hand.o PointCard.o ActionCard.o Deck.o
	g++ -std=c++11 -o main main.o Card.o Hand.o PointCard.o ActionCard.o Deck.o


# .o files
main.o: main.cpp
	g++ -std=c++11 -c main.cpp

card.o: Card.cpp Card.hpp
	g++ -std=c++11 -c Card.cpp

deck.o: Deck.cpp Deck.hpp
	g++ -std=c++11 -c Deck.cpp

hand.o: Hand.cpp Hand.hpp
	g++ -std=c++11 -c Hand.cpp

pointCard.o: pointCard.cpp pointCard.hpp
	g++ -std=c++11 -c PointCard.cpp

actionCard.o: ActionCard.cpp
	g++ -std=c++11 -c ActionCard.cpp

# misc
clean:
	rm ./main *.o