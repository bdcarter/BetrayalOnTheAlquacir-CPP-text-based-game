/********************************************************
* PROGRAM FILENAME: HALLWAY.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE HALLWAY 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR HALLWAY ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/


#ifndef HALLWAY_CPP
#define HALLWAY_CPP
#include "Room.hpp"

class Hallway : public Room
{
public:
	void add(Room *hn, Room *hs, Room *he, Room *hw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif