/***********************************************************
* PROGRAM FILENAME: STORAGE.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE STORAGE
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS POINTERS TO THE NAVIGATION LIST, DISPLAYS 
*	THE LIST, DISPLAYS ROOM INFORMATION, HAS THE USER MAKE 
*	AN OPTION FOR WHERE TO GO.
* INPUT: USER'S CHOICE TO NAVIGATION
* OUTPUT: ROOM DESCRIPTION, NAV OPTIONS
***********************************************************/

#include "Storage.hpp"
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
void Storage::add(Room *sn, Room *ss, Room *se, Room *sw)
{

	roomName = "Storage";
	north = new linkedRoom(sn, 1);
	linkedRoom *ptr = north;
	ptr->next = new linkedRoom(ss, 2);
	ptr = ptr->next;
	ptr->next = new linkedRoom(se, 3);
	ptr = ptr->next;
	ptr->next = new linkedRoom(sw, 4);

}

/*********************************************************************  
** Function:  DISPLAY LINKS
** Description:  DISPLAYS THE NAMES OFF ALL OF THE NAV LINKS AND 
**	THIER DIRECTIONS
** Parameters:  NONE
** Pre-Conditions: THE LINKS HAVE TO BE ADDED TO THE LIST
** Post-Conditions: NONE
*********************************************************************/
void Storage::displayLinks()
{
	linkedRoom *ptr = north;
	while(ptr)
	{
		if(ptr->value == 1)
			{std::cout << std::setw(35) << "					1. North: The weapons are stored here. It looks like someone was here." << std::endl;}
		else if(ptr->value == 2)
			{std::cout << std::setw(35) << "			2. South: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 3)
			{std::cout << std::setw(35) << "					3. East: The gun powder is here. Looks normal." << std::endl;}
		else if(ptr ->value == 4)
			{std::cout << std::setw(35) << "		4. West: " << ptr->link->getRoomName() << std::endl;}
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
Room* Storage::getRoomInfo()
{
		for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
		std::cout<< std::setw(55) << "Storage" << std::endl << std::endl;
		std::cout << "		There is enough light in the storage area to see everything. " << std::endl;
		std::cout << "		There is weapons storage to your left. We haven't needed weapons in many weeks, so " << std::endl;
		std::cout << "		things should be undisturbed. To your right is the gun powder. Straight ahead is the " << std::endl;
		std::cout << "		path to the mess hall. Faint laughter and activity is slithering from that direction. " << std::endl;
		std::cout << "		The hallway is behind you." << std::endl << std::endl;
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
** Pre-Conditions:  MUST BE IN THE STORAGE ROOM
** Post-Conditions:  MUST CHOOSE A DIRECTION AND MOVE ROOMS
*********************************************************************/
 void Storage::chooseDirection()
{

	std::cout << std::setw(50) << "Your choices are" << std::endl << std::endl;
	
//DISPLAY THE NAV OPTIONS
	displayLinks();
	std::cout << std::setw(50) << "Please make a choice" << std::endl << std::endl;

	std::cin >> move;

	while(move < 1 || move > 4)
	{
		std::cout << std::setw(50) << "Invalid choice. Please choose again." << std::endl << std::endl;
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
// 	PHYSICALLY CHANGE ROOMS FROM THE STORAGE BY GOING SOUTH. THE OTHER THREE
//	DIRECTIONS ARE INTERACTIONS.	
		if(move == 1)
		{
			std::cout << "-------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "			It looks like some arrows are missing from the storage. " << std::endl;
			std::cout << "			Pengon is the only one who knows how to use a bow and arrow." << std::endl;
			std::cout << "-------------------------------------------------------------------------------------------------" << std::endl << std::endl;
			change = ptr->link;
		}
		else if(move == 2)
			{
				std::cout << "			Entering the " << ptr->link->getRoomName() << std::endl << std::endl;
				change = ptr->link;
			}
		else if(move == 3)
			{
				std::cout << "------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			This gun powder looks undisturbed."  << std::endl;
				std::cout << "------------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr->link;
			}
		else if(move == 4)
			{
				std::cout << "			Entering the " << ptr->link->getRoomName() << std::endl << std::endl;
				change = ptr->link;
			}
		
		ptr = ptr->next;
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
}