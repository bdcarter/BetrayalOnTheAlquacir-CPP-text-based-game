/********************************************************
* PROGRAM FILENAME: HALLWAY.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE HALLWAY 
*	CHILD CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS ADDS POINTERS TO THE NAVIGATION LIST, DISPLAYS 
*	THE LIST, DISPLAYS ROOM INFORMATION, HAS THE USER MAKE 
*	AN OPTION FOR WHERE TO GO.
* INPUT: USER'S CHOICE TO NAVIGATION
* OUTPUT: ROOM DESCRIPTION, NAV OPTIONS
***********************************************************/
#include "Hallway.hpp"
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

void Hallway::add(Room *hn, Room *hs, Room *he, Room *hw)
{

	roomName = "Hallway";
	north = new linkedRoom(hn, 1);
	linkedRoom *ptr = north;
	ptr->next = new linkedRoom(hs, 2);
	ptr = ptr->next;
	ptr->next = new linkedRoom(he, 3);
	ptr = ptr->next;
	ptr->next = new linkedRoom(hw, 4);

}

/*********************************************************************  
** Function:  DISPLAY LINKS
** Description:  DISPLAYS THE NAMES OFF ALL OF THE NAV LINKS AND 
**	THIER DIRECTIONS
** Parameters:  NONE
** Pre-Conditions: THE LINKS HAVE TO BE ADDED TO THE LIST
** Post-Conditions: NONE
*********************************************************************/

void Hallway::displayLinks()
{
	linkedRoom *ptr = north;
	while(ptr)
	{
		if(ptr->value == 1)
			{std::cout << std::setw(35) << "			1. North: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 2)
			{std::cout << std::setw(35) << "			2. South: " << ptr->link->getRoomName() << std::endl;}
		else if(ptr->value == 3)
			{std::cout << std::setw(35) << "		3. East: " << ptr->link->getRoomName() << std::endl;}
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
Room* Hallway::getRoomInfo()
{
//BLANK LINES
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}

//ROOM DESCRIPTION
	std::cout<< std::setw(55) << "Hallway" << std::endl << std::endl;
	std::cout <<  "		It is cramped and chilly. You can see the bright sun shining down the " << std::endl;
	std::cout <<  "		stairs from the deck. You can hear the faint thud of the waves as the ship " << std::endl;
	std::cout <<  "		glides through the water. The familiar sounds of the crew at work make you feel " << std::endl;
	std::cout <<  "		comforted. But you must be diligent, you are in danger and you must find your father's " << std::endl;
	std::cout <<  "		killer before he finds you. " << std::endl << std::endl << std::endl;
	std::cout <<  "		There are four paths to choose: " << std::endl;
	std::cout <<  "		Straight ahead are the stairs leading to the deck." << std::endl;
	std::cout <<  "		Behind you is the holding cell where you would keep prisoners." << std::endl;
	std::cout <<  "		To your right is the Captain's Quarters." << std::endl;
	std::cout <<  "		To your left is supply storage with food and weapons and the way to the mess hall." << std::endl << std::endl;
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
** Pre-Conditions:  MUST BE IN THE HALLWAY
** Post-Conditions:  MUST CHOOSE A DIRECTION AND MOVE ROOMS
*********************************************************************/
 void Hallway::chooseDirection()
{

	std::cout << std::setw(50) << "Your choices are: " << std::endl;

//DISPLAY THE NAV OPTIONS
	displayLinks();
	std::cout << std::endl << std::setw(50) << "	Please make a choice" << std::endl;
	std::cin >> move;

	while(move < 1 || move > 4)
	{
		std::cout << std::setw(50) << "		Invalid choice. Please choose again." << std::endl;
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

//INDICATE MOVEMENT TO THE NEW ROOM, SET CHANGE TO THE NEW ROOM
		if(move == 1)
		{
			std::cout << std::setw(50) << "	 Entering the " << ptr->link->getRoomName() << std::endl << std::endl << std::endl;
			change = ptr->link;
		}
		else if(move == 2)
			{
				std::cout << std::setw(50) << "	 Entering the " << ptr->link->getRoomName() << std::endl << std::endl << std::endl;
				change = ptr->link;
			}
		else if(move == 3)
			{
				std::cout << std::setw(50) << "	Entering the " << ptr->link->getRoomName() << std::endl << std::endl << std::endl;
				change = ptr->link;
			}
		else if(move == 4)
			{
				std::cout <<std::setw(50) << "	Entering the " << ptr->link->getRoomName() << std::endl << std::endl << std::endl;
				change = ptr->link;
			}

//BLANK LINES		
	for(int x=0; x<8; x++)
		{std::cout << std:: endl;}
}