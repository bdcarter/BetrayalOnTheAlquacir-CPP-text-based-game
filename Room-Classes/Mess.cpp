/********************************************************
* PROGRAM FILENAME: MESS.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE MESS
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS POINTERS TO THE NAVIGATION LIST, DISPLAYS 
*	THE LIST, DISPLAYS ROOM INFORMATION, HAS THE USER MAKE 
*	AN OPTION FOR WHERE TO GO.
* INPUT: USER'S CHOICE TO NAVIGATION
* OUTPUT: ROOM DESCRIPTION, NAV OPTIONS
***********************************************************/

#include "Mess.hpp"
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
void Mess::add(Room *mn, Room *ms, Room *me, Room *mw)
{

	roomName = "Mess Hall";
	north = new linkedRoom(mn, 1);
	linkedRoom *ptr = north;
	ptr->next = new linkedRoom(ms, 2);
	ptr = ptr->next;
	ptr->next = new linkedRoom(me, 3);
	ptr = ptr->next;
	ptr->next = new linkedRoom(mw, 4);

}

/*********************************************************************  
** Function:  DISPLAY LINKS
** Description:  DISPLAYS THE NAMES OFF ALL OF THE NAV LINKS AND 
**	THIER DIRECTIONS
** Parameters:  NONE
** Pre-Conditions: THE LINKS HAVE TO BE ADDED TO THE LIST
** Post-Conditions: NONE
*********************************************************************/

void Mess::displayLinks()
{
	linkedRoom *ptr = north;
	while(ptr)
	{
		if(ptr->value == 1)
			{std::cout << std::setw(35) << "		1. North: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 2)
			{std::cout << std::setw(35) << "				2. South: The cook, Maeasson, may have some news" << std::endl;}
		else if(ptr->value == 3)
			{std::cout << std::setw(35) << "				3. East: Nothing in the crew quarters" << std::endl;}
		else if(ptr ->value == 4)
			{std::cout << std::setw(35) << "				4. West: Never disturb a sailor's poker game" << std::endl << std::endl;}
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
Room* Mess::getRoomInfo()
{
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
	std::cout << std::endl << std::endl;
	std::cout << std::setw(55) << "Mess Hall" << std::endl << std::endl;
	std::cout << "	The mess hall is dim and noisy. You enter and see the cook, Maeasson, behind you." << std::endl;
	std::cout << "	He might have some good information. The crew's quarters are to your right, there's nothing in there." << std::endl;
	std::cout << " 	To the left you see a gathering of crew members playing poker. It would be unwise to disturb them. The " << std::endl;
	std::cout << "	way back to storage is straight ahead. " << std::endl << std::endl;
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
** Pre-Conditions:  MUST BE IN THE MESS HALL
** Post-Conditions:  MUST CHOOSE A DIRECTION AND MOVE ROOMS
*********************************************************************/

 void Mess::chooseDirection()
{

	std::cout << std::setw(50) << "Here are your choices" << std::endl << std::endl;

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
// 	PHYSICALLY CHANGE ROOMS FROM THE MESS HALL BY GOING NORTH. THE OTHER THREE
//	DIRECTIONS ARE INTERACTIONS.
		if(move == 1)
		{
			std::cout << "			Entering " << ptr->link->getRoomName() << std::endl;
			change = ptr->link;
		}
		else if(move == 2)
			{
				std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			The cook said he heard Gorfuinor bragging about his new archery skills." << std::endl;
				std::cout << "			Why would he do that? He's just a watchman. Something doesn't seem right." << std::endl;
				std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
				
			}
		else if(move == 3)
			{
				std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "		There is nothing to see in the crew's quarters" << std::endl;
				std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
				
			}
		else if(move == 4)
			{
				std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			It is unwise to interrupt a poker game. You notice Gorfuinor among the crowd. " << std::endl;
				std::cout << "			He has an air of superiority."  << std::endl;
				std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
				
			}
		
		ptr = ptr->next;
		for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
}