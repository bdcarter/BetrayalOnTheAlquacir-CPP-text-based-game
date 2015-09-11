/********************************************************
* PROGRAM FILENAME: ROOM.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE ROOM 
*	CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS THE ROOM POINTERS TO EACH ROOM'S STRUCT
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#include "Room.hpp"
#include <vector>
#include <iostream>
#include <string>



Room::~Room()
{
	linkedRoom *ptr = north;
	while (ptr != NULL)
	{
		linkedRoom *garbage = ptr;
		ptr = ptr->next;
		delete garbage;
	}
}
/*********************************************************************  
** Function:  ADD
** Description:  ADDS A LINK TO THE NAVIGATION STRUCT, THIS FUNCTION
**	IS OVERRIDDEN BY THE CHILD CLASSES.
** Parameters:  ROOM POINTER, INT
** Pre-Conditions:  A ROOM OBJECT AND POINTER MUST BE CREATED
** Post-Conditions:  A LINK WILL BE ADDED TO THE LIST
*********************************************************************/

void Room::add(Room *r,int number)
{
	if(north == NULL)
		{
		
			north = new linkedRoom(r,number);//
		
		}
	else
	{
		linkedRoom *ptr = north;
		while(ptr->next != NULL)
			{	ptr = ptr->next;}
		ptr->next = new linkedRoom(r,number);// 
		
	}

}



