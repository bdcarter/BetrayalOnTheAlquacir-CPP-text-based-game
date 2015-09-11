/********************************************************
* PROGRAM FILENAME: CELL.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE CELL 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR CELL ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef CELL_CPP
#define CELL_CPP
#include "Room.hpp"

class Cell : public Room
{
public:
	void add(Room *cn, Room *cs, Room *ce, Room *cw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif