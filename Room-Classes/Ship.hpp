/********************************************************
* PROGRAM FILENAME: SHIP.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE SHIP 
*	CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR". THIS FILE
	CREATES THE 10 ROOMS AND POINTERS FOR THE SHIP. 
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/



#ifndef SHIP_CPP
#define SHIP_CPP
#include <string>
#include "Room.hpp"
#include "Hallway.hpp"
#include "Deck.hpp"
#include "Storage.hpp"
#include "Quarters.hpp"
#include "Cell.hpp"
#include "Nest.hpp"
#include "Wheel.hpp"
#include "Mess.hpp"
#include "Bow.hpp"
#include "Stern.hpp"
#include <iomanip>
#include <vector>

class Ship 
{
protected:

	std::string name;

//CREATE 10 ROOMS
	Hallway hall;
	Deck deck;
	Storage storage;
	Quarters quarters;
	Cell cell;
	Nest nest;
	Wheel wheel;
	Mess mess;
	Bow bow;
	Stern stern;

//CREATE POINTERS FOR THE ROOMS
	Hallway *hallptr;
	Deck *deckptr;
	Storage *storeptr;
	Quarters *quarptr;
	Cell *cellptr;
	Nest *nestptr;
	Wheel *wheelptr;
	Mess *messptr;
	Bow *bowptr;
	Stern *sternptr;
	Room *interact;
	Room *current;

public:
	void solve();
	friend class Room;	
	Ship();
	void answer();	
	Room* getCurrentRoom();
	void createRooms();
	void showLinks();
	std::string getName(){return name;}
	std::string getCurrentRoomName();
	bool getBook(){return quarptr->getLogBook();}
	bool getInk(){return wheelptr->getSmudge();}
	bool getA(){return nestptr->getArrow();}
};
#endif