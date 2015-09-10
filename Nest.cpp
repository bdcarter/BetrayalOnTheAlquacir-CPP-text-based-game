/********************************************************
* PROGRAM FILENAME: NEST.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE NEST
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS POINTERS TO THE NAVIGATION LIST, DISPLAYS 
*	THE LIST, DISPLAYS ROOM INFORMATION, HAS THE USER MAKE 
*	AN OPTION FOR WHERE TO GO.
* INPUT: USER'S CHOICE TO NAVIGATION
* OUTPUT: ROOM DESCRIPTION, NAV OPTIONS
***********************************************************/

#include "Nest.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

/*********************************************************************  
** Function:  ADD
** Description:  ADDS LINKS TO THE NAVIGATION STRUCT
** Parameters:  4 ROOM POINTERS
** Pre-Conditions:  THE ROOM OBJECTS AND POINTERS MUST BE CREATED
** Post-Conditions:  THE NAVIGATION LIST WILL BE COMPLETED
*********************************************************************/
void Nest::add(Room *nn, Room *ns, Room *ne, Room *nw)
{

	roomName = "Crow's Nest";
	arrow = false;
	north = new linkedRoom(nn, 1);
	linkedRoom *ptr = north;
	ptr->next = new linkedRoom(ns, 2);
	ptr = ptr->next;
	ptr->next = new linkedRoom(ne, 3);
	ptr = ptr->next;
	ptr->next = new linkedRoom(nw, 4);

}

/*********************************************************************  
** Function:  DISPLAY LINKS
** Description:  DISPLAYS THE NAMES OFF ALL OF THE NAV LINKS AND 
**	THIER DIRECTIONS
** Parameters:  NONE
** Pre-Conditions: THE LINKS HAVE TO BE ADDED TO THE LIST
** Post-Conditions: NONE
*********************************************************************/
void Nest::displayLinks()
{
	linkedRoom *ptr = north;
	while(ptr)
	{
		if(ptr->value == 1)
			{std::cout << std::setw(40) << "					1. North: Nothing but endless sky"  << std::endl;}
		else if(ptr->value == 2)
			{std::cout << std::setw(35) << "			2. South: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 3)
			{std::cout << std::setw(40) << "					3. East: There is something over there." << std::endl;}
		else if(ptr ->value == 4)
			{std::cout << std::setw(40) << "					4. West: Not a cloud in the sky" << std::endl << std::endl;}
		ptr = ptr->next;
	}
}

/*********************************************************************  
** Function:  GET ROOM INFO
** Description:  DISPLAYS THE ROOM DESCRIPTION. REPEATS WHILE THE USER 
**	CHOOSES TO NAVIGATE TO A LINK WITH A NULL POINTER
** Parameters: NONE
** Pre-Conditions:  USER MUST NAVIGATE TO THIS ROOM
** Post-Conditions: USER MUST CHOOSE TO MOVE IN A DIRECTION IS NOT NULL
*********************************************************************/
Room* Nest::getRoomInfo()
{
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
	std::cout<< std::setw(55) << "Crow's Nest" << std::endl << std::endl;
	std::cout << "	It is very quiet and peaceful in the crow's nest. You can see for miles in every direction." << std::endl;
	std::cout << "	To your left there is a piece of something that shouldn't be there." << std::endl << std::endl;
	std::cout << std::endl << std::endl;
// HAVE THE USER CHOOSE A DIRECTION, REPEAT IF CHANGE IS NULL
	do{
	this->chooseDirection();
	}while(change == NULL);
	return change;
}

/*********************************************************************  
** Function:  CHOOSE DIRECTION
** Description:  DISPLAY THE NAV OPTIONS, HAVE THE USER CHOOSE A DIRECTION
**	POINT CHANGE TO THE USER'S CHOICE AND INDICATE MOVEMENT TO THAT ROOM
** Parameters:  NONE
** Pre-Conditions:  MUST BE IN THE NEST
** Post-Conditions:  MUST CHOOSE A DIRECTION AND MOVE ROOMS
*********************************************************************/
 void Nest::chooseDirection()
{

	std::cout << std::setw(50) << "Your choices are " << std::endl;

//DISPLAY THE NAV OPTIONS
	displayLinks();
	std::cout << std::setw(50) << "Please make a choice" << std::endl;

	std::cin >> move;

	while(move < 1 || move > 4)
	{
		std::cout << std::setw(50) << "Invalid choice. Please choose again." << std::endl;
		std::cin >> move;
	}

//LOOP THROUGH THE LIST TO FIND THE USER'S CHOICE, SET THE POINTER TO THAT ELEMENT
	linkedRoom *ptr = north;
		while(ptr->next != NULL)
	{	if(ptr->value != move)
		{ptr = ptr->next;}
		else
			{break;}
	}
	
//INDICATE MOVEMENT TO THE NEW ROOM, SET CHANGE TO THE NEW ROOM. USER CAN ONLY 
// 	PHYSICALLY CHANGE ROOMS FROM THE CROWS NEST BY GOING SOUTH. THE OTHER THREE
//	DIRECTIONS ARE INTERACTIONS.	
		if(move == 1)
		{
			std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "			The sky is cloudless and the sun is hot." << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << std::endl << std::endl;
			change = ptr-> link;
			
		}
		else if(move == 2)
			{
				std::cout << "			Climbing down to the " << ptr->link->getRoomName() << std::endl;
				std::cout << std::endl << std::endl;
				change = ptr->link;
			}
		else if(move == 3)
			{
				std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			There is a broken arrow. What is that doing here?" << std::endl;
				std::cout << "			I will take this and examine it. " << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------" << std::endl << std::endl;
				arrow = true;
				change = ptr-> link;
				
			}
		else if(move == 4)
			{
				std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "		The view is beautiful but I should keep searching." << std::endl;
				std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
				std::cout << std::endl << std::endl;
				change = ptr-> link;
				
			}
		
		ptr = ptr->next;
		for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
}