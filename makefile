# Patrick Ging
# makefile

# executables
main: main.o Card.o Hand.o PointCard.o ActionCard.o Deck.o
	g++ -o main main.o Card.o Hand.o PointCard.o ActionCard.o Deck.o


# .o files
main.o: main.cpp
	g++ -c main.cpp

card.o: Card.cpp Card.hpp
	g++ -c Card.cpp

deck.o: Deck.cpp Deck.hpp
	g++ -c Deck.cpp

hand.o: Hand.cpp Hand.hpp
	g++ -c Hand.cpp

pointCard.o: pointCard.cpp pointCard.hpp
	g++ -c PointCard.cpp

actionCard.o: ActionCard.cpp
	g++ -c ActionCard.cpp

# misc
clean:
	rm ./main *.o