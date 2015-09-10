/***********************************************************
* PROGRAM FILENAME: WHEEL.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE WHEEL
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS POINTERS TO THE NAVIGATION LIST, DISPLAYS 
*	THE LIST, DISPLAYS ROOM INFORMATION, HAS THE USER MAKE 
*	AN OPTION FOR WHERE TO GO.
* INPUT: USER'S CHOICE TO NAVIGATION
* OUTPUT: ROOM DESCRIPTION, NAV OPTIONS
***********************************************************/

#include "Wheel.hpp"
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
void Wheel::add(Room *wn, Room *ws, Room *we, Room *ww)
{

	roomName = "Navigation Wheel";
	smudge = false;
	north = new linkedRoom(wn, 1);
	linkedRoom *ptr = north;
	ptr->next = new linkedRoom(ws, 2);
	ptr = ptr->next;
	ptr->next = new linkedRoom(we, 3);
	ptr = ptr->next;
	ptr->next = new linkedRoom(ww, 4);

}

/*********************************************************************  
** Function:  DISPLAY LINKS
** Description:  DISPLAYS THE NAMES OFF ALL OF THE NAV LINKS AND 
**	THIER DIRECTIONS
** Parameters:  NONE
** Pre-Conditions: THE LINKS HAVE TO BE ADDED TO THE LIST
** Post-Conditions: NONE
*********************************************************************/
void Wheel::displayLinks()
{
	linkedRoom *ptr = north;
	while(ptr)
	{
		if(ptr->value == 1)
			{std::cout << std::setw(35) << "			1. North: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 2)
			{std::cout << std::setw(35) << "			2. South: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 3)
			{std::cout << std::setw(35) << "					3. East: The first mate, Thannor, is steering" << std::endl;}
		else if(ptr ->value == 4)
			{std::cout << std::setw(35) << "					4. West: There is some sort of residue here" << std::endl << std::endl;}
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
Room* Wheel::getRoomInfo()
{
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
	std::cout << std::endl << std::endl;
	std::cout<< std::setw(55) << "Navigation Wheel" << std::endl << std::endl;
	std::cout << "	The bow of the ship is straight ahead. To your left the first mate, " << std::endl;
	std::cout << "	Thannor, is navigating. The deck is behind you. To the right, " << std::endl;
	std::cout << "	you notice a strange black smudge on some rigging near the wheel." << std::endl << std::endl;
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
** Pre-Conditions:  MUST BE AT THE WHEEL
** Post-Conditions:  MUST CHOOSE A DIRECTION AND MOVE ROOMS
*********************************************************************/
 void Wheel::chooseDirection()
{

	std::cout << std::setw(50) << "Your choices are" << std::endl;
	
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
// 	PHYSICALLY CHANGE ROOMS FROM THE WHEEL BY GOING NORTH OR SOUTH. THE OTHER TWO
//	DIRECTIONS ARE INTERACTIONS.	
		if(move == 1)
		{
			std::cout << "			Entering the " << ptr->link->getRoomName() << std::endl << std::endl;
			change = ptr->link;
		}
		else if(move == 2)
			{
				std::cout << "			Entering the " << ptr->link->getRoomName() << std::endl << std::endl;;
				change = ptr->link;
			}
		else if(move == 3)
			{
				std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			Thannor has been a loyal, kind first mate for many years" << std::endl;
				std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
				change = ptr-> link;
				
			}
		else if(move == 4)
			{
				std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "			This black smudge looks familiar. And this rigging seems to lead up " << std::endl;
				std::cout << "			to the Crow's nest." << std::endl;
				std::cout << "---------------------------------------------------------------------------------------------------" << std::endl << std::endl;
				smudge = true;
				change = ptr-> link;
				
			}
		
		ptr = ptr->next;
		for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
}