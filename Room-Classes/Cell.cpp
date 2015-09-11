/***********************************************************
* PROGRAM FILENAME: CELL.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE CELL
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS POINTERS TO THE NAVIGATION LIST, DISPLAYS 
*	THE LIST, DISPLAYS ROOM INFORMATION, HAS THE USER MAKE 
*	AN OPTION FOR WHERE TO GO.
* INPUT: USER'S CHOICE TO NAVIGATION
* OUTPUT: ROOM DESCRIPTION, NAV OPTIONS
***********************************************************/

#include "Cell.hpp"
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

void Cell::add(Room *cn, Room *cs, Room *ce, Room *cw)
{

	roomName = "Holding Cell";
	north = new linkedRoom(cn, 1);
	linkedRoom *ptr = north;
	ptr->next = new linkedRoom(cs, 2);
	ptr = ptr->next;
	ptr->next = new linkedRoom(ce, 3);
	ptr = ptr->next;
	ptr->next = new linkedRoom(cw, 4);

}


/*********************************************************************  
** Function:  DISPLAY LINKS
** Description:  DISPLAYS THE NAMES OFF ALL OF THE NAV LINKS AND 
**	THIER DIRECTIONS
** Parameters:  NONE
** Pre-Conditions: THE LINKS HAVE TO BE ADDED TO THE LIST
** Post-Conditions: NONE
*********************************************************************/
void Cell::displayLinks()
{
	linkedRoom *ptr = north;
	while(ptr)
	{
		if(ptr->value == 1)
			{std::cout << std::setw(35) << "			1. North: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 2)
			{std::cout << std::setw(35) << "					2. South: The cell where the prisoners are held." << std::endl;}
		else if(ptr->value == 3)
			{std::cout << std::setw(35) << "					3. East: Amathon may have some information" << std::endl;}
		else if(ptr ->value == 4)
			{std::cout << std::setw(35) << "					4. West: There is a wall here." <<  std::endl << std::endl;}
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
Room* Cell::getRoomInfo()
{
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
	std::cout << std::setw(55) << "Cell" << std::endl << std::endl;
	std::cout << "	The holding cell is where you would keep prisoners. The guard, Amathon, tends to spend his time here " << std::endl;
	std::cout << "	even when there are no prisoners. The holding cell is chilly and damp with very little light. " << std::endl;
	std::cout << "	To your right is a wall. Directly behind you is the way back to the hallway. " << std::endl;
	std::cout << "	Straight ahead is the cell for prisoners. You can't remember the last time someone was in there." << std::endl;
	std::cout << "	If all goes well, there will be a traitor rotting there tonight. To your left you notice Amathon " << std::endl;
	std::cout << "	tending to some weapons. Best to keep them sharp, he always says, you never know when you'll need them." << std::endl << std::endl;
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
** Pre-Conditions:  MUST BE IN THE CELL
** Post-Conditions:  MUST CHOOSE A DIRECTION AND MOVE ROOMS
*********************************************************************/
 void Cell::chooseDirection()
{

	std::cout << std::setw(50) << "Your choices are" << std::endl << std::endl;

//DISPLAY THE NAV OPTIONS
	displayLinks();
	std::cout << std::setw(50) << "Please make a choice" << std::endl;

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
// 	PHYSICALLY CHANGE ROOMS FROM THE CELL BY GOING NORTH. THE OTHER THREE
//	DIRECTIONS ARE INTERACTIONS.
		if(move == 1)
		{
			std::cout << "			Moving to " << ptr->link->getRoomName() << std::endl << std::endl;
			change = ptr->link;
		}
		else if(move == 2)
			{
				std::cout << "-------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			There is nothing in the cell for you." << std::endl;
				std::cout << "-------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
			}
		else if(move == 3)
			{
				std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "	You go talk to Amathon. He tells you he has noticed Gorfuinor practicing with a bow." << std::endl;
				std::cout << "	You wonder why he would do that. He is just a watchman." << std::endl;
				std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
			}
		else if(move == 4)
			{
				std::cout << "-----------------------------------------------------------------------------------" << std::endl;
				std::cout << "			There is a wall there..." << std::endl;
				std::cout << "-----------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
				
			}
		
		ptr = ptr->next;
		for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
}