/********************************************************
* PROGRAM FILENAME: QUARTER.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE QUARTER
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS POINTERS TO THE NAVIGATION LIST, DISPLAYS 
*	THE LIST, DISPLAYS ROOM INFORMATION, HAS THE USER MAKE 
*	AN OPTION FOR WHERE TO GO.
* INPUT: USER'S CHOICE TO NAVIGATION
* OUTPUT: ROOM DESCRIPTION, NAV OPTIONS
***********************************************************/

#include "Quarters.hpp"
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
void Quarters::add(Room *qn, Room *qs, Room *qe, Room *qw)
{

	roomName = "Captain's Quarters";
	logBook = false;
	north = new linkedRoom(qn, 1);
	linkedRoom *ptr = north;
	ptr->next = new linkedRoom(qs, 2);
	ptr = ptr->next;
	ptr->next = new linkedRoom(qe, 3);
	ptr = ptr->next;
	ptr->next = new linkedRoom(qw, 4);

}

/*********************************************************************  
** Function:  DISPLAY LINKS
** Description:  DISPLAYS THE NAMES OFF ALL OF THE NAV LINKS AND 
**	THIER DIRECTIONS
** Parameters:  NONE
** Pre-Conditions: THE LINKS HAVE TO BE ADDED TO THE LIST
** Post-Conditions: NONE
*********************************************************************/
void Quarters::displayLinks()
{
	linkedRoom *ptr = north;
	while(ptr)
	{
		if(ptr->value == 1)
			{std::cout << std::setw(35) << "			1. North: There is a painting hanging on the wall" << std::endl;}
		else if(ptr->value == 2)
			{std::cout << std::setw(35) << "			2. South: You notice the Captain's log on the desk. Could be useful." << std::endl;}
		else if(ptr->value == 3)
			{std::cout << std::setw(25) << "		3. East: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr ->value == 4)
			{std::cout << std::setw(35) << "			4. West: There is a window with a beautiful view." << std::endl << std::endl;}
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
Room* Quarters::getRoomInfo()
{
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
	std::cout << std::setw(55) << "Captain's Quarters" << std::endl << std::endl;
	std::cout << "		This room reminds you so much of your father." << std::endl;
	std::cout << "		Straight ahead you notice the painting of him " << std::endl;
	std::cout << "		seems to speak to you. If only he could." << std::endl;
	std::cout << "		On the desk you notice his Captain's log." << std::endl;
	std::cout << "		To your left there is a window overlooking the" << std::endl;
	std::cout << " 		ocean. The exit to the hallway is directly behind you." << std::endl << std::endl;
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
** Pre-Conditions:  MUST BE IN THE CAPTAINS QUARTERS
** Post-Conditions:  MUST CHOOSE A DIRECTION AND MOVE ROOMS
*********************************************************************/
 void Quarters::chooseDirection()
{

	std::cout << std::setw(50) << "Your choices are:" << std::endl << std::endl;

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
		std::cout << std::endl << std::endl;

//INDICATE MOVEMENT TO THE NEW ROOM, SET CHANGE TO THE NEW ROOM. USER CAN ONLY 
// 	PHYSICALLY CHANGE ROOMS FROM THE CAPTAINS QUARTERS BY GOING EAST. THE OTHER THREE
//	DIRECTIONS ARE INTERACTIONS.	
		if(move == 1)
		{
			std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "			You sit looking at your father's portrait for a time." << std::endl;
			std::cout << "			You vow to find the person responsible for his death." << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;

			change = ptr-> link;
			
		}
		else if(move == 2)
			{
				std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			You pick up the log and notice some pages missing " << std::endl;
				std::cout << "			and the black ink is smudged. Who would do this?" << std::endl;
				std::cout << "---------------------------------------------------------------------------------------------" << std::endl << std::endl;
				logBook = true;
				change = ptr-> link;			
			}
		else if(move == 3)
			{
				std::cout << "			Entering the " << ptr->link->getRoomName() << std::endl << std::endl;
				change = ptr->link;
			}
		else if(move == 4)
			{
				std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			You caught Father gazing out this window many times." << std::endl;
				std::cout << "			What was he thinking about?" << std::endl;
				std::cout << "--------------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
			}
		
		ptr = ptr->next;
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
	
}