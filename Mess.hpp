/********************************************************
* PROGRAM FILENAME: MESS.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE MESS 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR MESS ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/


#ifndef MESS_CPP
#define MESS_CPP
#include "Room.hpp"

class Mess : public Room
{
public:
	void add(Room *mn, Room *ms, Room *me, Room *mw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif