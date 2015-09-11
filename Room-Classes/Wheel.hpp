/********************************************************
* PROGRAM FILENAME: WHEEL.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE WHEEL 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR WHEEL ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef WHEEL_CPP
#define WHEEL_CPP
#include "Room.hpp"

class Wheel : public Room
{
protected:
	bool smudge;
public:
	void add(Room *wn, Room *ws, Room *we, Room *ww);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
	bool getSmudge(){return smudge;}
};
#endif