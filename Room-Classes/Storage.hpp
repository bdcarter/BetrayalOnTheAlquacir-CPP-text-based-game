/********************************************************
* PROGRAM FILENAME: STORAGE.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE STORAGE 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR STORAGE ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef STORAGE_CPP
#define STORAGE_CPP
#include "Room.hpp"

class Storage : public Room
{
public:
	void add(Room *sn, Room *ss, Room *se, Room *sw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif
