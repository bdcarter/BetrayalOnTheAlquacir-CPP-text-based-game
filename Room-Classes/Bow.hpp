/********************************************************
* PROGRAM FILENAME: BOW.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE BOW 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR BOW ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef BOW_CPP
#define BOW_CPP
#include "Room.hpp"

class Bow : public Room
{
public:
	void add(Room *bn, Room *bs, Room *be, Room *bw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif