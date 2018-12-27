main: main.o patron.o restaurant.o controller.o
	g++ main.o patron.o restaurant.o controller.o -o main

main.o: main.cpp restaurant.h patron.h
	g++ -g -Wall -c main.cpp

patron.o: patron.cpp patron.h
	g++ -g -Wall -c patron.cpp

restaurant.o: restaurant.cpp restaurant.h venue.h
	g++ -g -Wall -c restaurant.cpp

controller.o: controller.cpp controller.h venue.h restaurant.h
	g++ -g -Wall -c controller.cpp

clean:
	rm main.o patron.o restaurant.o controller.o main
