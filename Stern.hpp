/********************************************************
* PROGRAM FILENAME: STERN.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE STERN 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR STERN ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef STERN_CPP
#define STERN_CPP
#include "Room.hpp"

class Stern : public Room
{
public:
	void add(Room *stn, Room *sts, Room *ste, Room *stw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif