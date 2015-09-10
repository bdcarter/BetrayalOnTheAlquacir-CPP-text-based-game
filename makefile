PROGS := ship

all: $(PROGS)

ship: main.o Ship.o Room.o Player.o Item.o Hallway.o Deck.o Storage.o Quarters.o Cell.o Nest.o Wheel.o Mess.o Bow.o Stern.o
	g++ -g main.o Ship.o Room.o Player.o Item.o Hallway.o Deck.o Storage.o Quarters.o Cell.o Nest.o Wheel.o Mess.o Bow.o Stern.o -o ship

main.o: main.cpp
	g++ -c main.cpp

Ship.o: Ship.cpp Ship.hpp
	g++ -c Ship.cpp

Room.o: Room.hpp Room.cpp
	g++ -c Room.cpp

Player.o: Player.hpp Player.cpp
	g++ -c Player.cpp

Item.o: Item.hpp Item.cpp
	g++ -c Item.cpp

Hallway.o: Hallway.hpp Hallway.cpp
	g++ -c Hallway.cpp

Deck.o: Deck.hpp Deck.cpp
	g++ -c Deck.cpp

Storage.o: Storage.hpp Storage.cpp
	g++ -c Storage.cpp

Quarters.o: Quarters.hpp Quarters.cpp
	g++ -c Quarters.cpp

Cell.o: Cell.hpp Cell.cpp
	g++ -c Cell.cpp

Nest.o: Nest.hpp Nest.cpp
	g++ -c Nest.cpp

Wheel.o: Wheel.hpp Wheel.cpp
	g++ -c Wheel.cpp

Mess.o: Mess.hpp Mess.cpp
	g++ -c Mess.cpp

Bow.o: Bow.hpp Bow.cpp
	g++ -c Bow.cpp

Stern.o: Stern.hpp Stern.cpp
	g++ -c Stern.cpp

clean:
	rm -f ${PROGS} *.o *~
