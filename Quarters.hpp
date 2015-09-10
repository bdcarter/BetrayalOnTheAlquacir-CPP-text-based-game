/********************************************************
* PROGRAM FILENAME: QUARTERS.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE QUARTERS 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE CONSTRUCTOR FOR QUARTERS ROOMS, A 
*	FUNCTION TO DISPLAY THE LINKED LIST, A FUNCTION TO NAVIGATE 
*	ROOMS, A FUNCTION TO GET INFORMATION ABOUT THE ROOM.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef QUARTERS_CPP
#define QUARTERS_CPP
#include "Room.hpp"

class Quarters : public Room
{
protected:
	bool logBook;
public:
	void add(Room *qn, Room *qs, Room *qe, Room *qw);
	Room* getRoomInfo();
	void chooseDirection();
	virtual void displayLinks();
	bool getLogBook(){return logBook;}
};
#endif