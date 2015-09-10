/********************************************************
* PROGRAM FILENAME: ROOM.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE ROOM 
*	CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS CONTAINS THE STRUCT LINKED LIST FOR NAVIGATION
*	IN EACH ROOM. A ROOM OBJECT WILL NEVER BE SUBSTANTIATED. 
*	THERE ARE 10 CHILD CLASSES FOR EACH TYPE OF ROOM IN THE SHIP.
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#ifndef ROOM_CPP
#define ROOM_CPP

#include <string>
#include <iostream>

class Room
{
protected:
	friend class Ship;
	std::string roomName;

	void setRoomName(std::string name){roomName = name;}

//THIS STRUCT HOLDS POINTERS TO THE ROOMS THAT CAN
// BE NAVIGAED FROM THE CURRENT ROOM
// THE LINKED ROOM POINTER NORTH POINTS TO THE ROOM TO THE NORTH
// OF EACH ROOM. THE VALUE IS THE DIRECTION IDENTIFIER, 1:NORTH,
// 2:SOUTH, 3:EAST, 4:WEST. NEXT POINTS TO THE NEXT ROOM IN THE 
// LIST.

		struct linkedRoom
		{
			friend class Room;
			int value;
			linkedRoom *next;
			Room *link;
			linkedRoom(Room *r, int v, linkedRoom *next1 = NULL)//
				{
					link = r;
					value = v;
					next = next1;		
				}
		};
	linkedRoom *north;

//CHANGE POINTS TO THE ROOM THE USER WOULD LIKE TO NAVIGATE TO
	Room *change;
public:	

	int move;
	Room()
		{	
			north = NULL;
			roomName = "x";
		}
	~Room();
	std::string getRoomName(){return roomName;}
	virtual void add(Room *r,int number); 
	virtual void displayLinks() = 0;
	virtual Room* getRoomInfo()=0;
	virtual void chooseDirection()=0;

};	
#endif

