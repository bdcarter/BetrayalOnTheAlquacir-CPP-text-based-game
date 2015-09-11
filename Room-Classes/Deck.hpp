/********************************************************
* PROGRAM FILENAME: DECK.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE DECK 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR DECK ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef DECK_CPP
#define DECK_CPP
#include "Room.hpp"

class Deck : public Room
{
public:
	void add(Room *dn, Room *ds, Room *de, Room *dw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif
