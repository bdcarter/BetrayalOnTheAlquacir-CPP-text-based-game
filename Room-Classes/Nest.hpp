/********************************************************
* PROGRAM FILENAME: NEST.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE NEST 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR NEST ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef NEST_CPP
#define NEST_CPP
#include "Room.hpp"

class Nest : public Room
{
protected:
	bool arrow;
public:
	bool getArrow(){return arrow;}
	void add(Room *nn, Room *ns, Room *ne, Room *nw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
};
#endif