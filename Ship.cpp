/********************************************************
* PROGRAM FILENAME: PLAYER.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE IMPLEMENTATION FILE FOR THE PLAYER 
*	CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
*	THIS CLASS DISPLAYS THE ANSWER, CREATES THE ROOMS, KEEPS TRACK
*	OF THE CURRENT ROOM, DIPLAYS THE MENU FOR SOLVING
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/


#include "Ship.hpp"
#include <string>
#include <iostream>



Ship::Ship()
{
	name = "Alquacir";

}

/*********************************************************************  
** Function:  ANSWER
** Description:  DISPLAYS HOW TO SOLVE THE GAME
** Parameters:  NONE
** Pre-Conditions:  USER MUST CHOOSE TO DISPLAY THE ANSWER
** Post-Conditions:  USER MUST PRESS ENTER TO MOVE ON TO THE GAME
*********************************************************************/
void Ship::answer()
{
	char ch;

//CLEAR SOME OF THE SCREEN
	for(int x = 0; x<8; x++)
		{std::cout << std::endl;}

	std::cout << "		Gorfuinor is the killer." << std::endl; 
	std::cout << "		The items to collect: " << std::endl;
	std::cout << "			Captain's quarters: Captain's log has some pages torn and the ink is smudged. " << std::endl;
	std::cout << "			Bird's nest: Broken arrow. " << std::endl;
	std::cout << "			Navigation wheel: Black ink smudge near rigging leading to the Bird's nest. " << std::endl;
	std::cout << "		Other clues: " << std::endl;
	std::cout << "			In the holding cells, talk to the guard " << std::endl;
	std::cout << "			In the mess hall, talk to he cook and look at the poker game." << std::endl;
	std::cout << std::endl << "		You must collect all 3 items to be given the opportunity to solve. " << std::endl;

//MORE BLANK LINES
	for(int x = 0; x<8; x++)
		{std::cout << std::endl;}

//WAIT FOR THE USER TO PRESS ENTER TO CONTINUE

		std::cout << std::setw(50) << "		Press enter to continue..." << std::endl;
	std::cin.get(ch);
}


/*********************************************************************  
** Function:  CREATE ROOMS
** Description:  CALLS THE ADD FUNCTION FOR ALL OF THE ROOMS TO ADD 
**	ROOM POINTERS TO THEIR STRUCT
** Parameters:  NONE
** Pre-Conditions:  MUST HAVE 10 ROOMS AND 10 POINTERS TO ROOMS
** Post-Conditions:  ROOMS WILL HAVE THEIR NAV STRUCT SET UP
*********************************************************************/
void Ship::createRooms()
{

	
	hallptr = &hall;
	deckptr = &deck;
	storeptr = &storage;
	quarptr = &quarters;
	cellptr = &cell;
	nestptr = &nest;
	wheelptr = &wheel;
	messptr = &mess;
	bowptr = &bow;
	sternptr = &stern;
	interact = NULL;
	current = &hall;

	hall.add(deckptr, cellptr, storeptr, quarptr);
	deck.add(nestptr, hallptr, wheelptr, sternptr);
	cell.add(hallptr, interact, interact, interact);
	storage.add(interact, messptr, interact, hallptr);
	quarters.add(interact, interact, hallptr, interact);
	nest.add(interact, deckptr, interact, interact);
	wheel.add(bowptr, deckptr, interact, interact);
	mess.add(storeptr, interact, interact, interact);	
	bow.add(interact, wheelptr, interact, interact);
	stern.add(interact, interact, deckptr, interact);

}

/*********************************************************************  
** Function:  GET CURRENT ROOM
** Description:  CALL ROOM INFO FOR THE CURRENT ROOM, DECLARES A BOOL 
**	TO KEEP TRACK IF AN ITEM IS FOUND IN THAT ROOM
** Parameters:  NONE
** Pre-Conditions:  CURRENT MUST BE POINTING TO A ROOM
** Post-Conditions:  CURRENT WILL BE SET TO THE ROOM THE USER CHOOSES
*********************************************************************/
Room* Ship::getCurrentRoom()
{
	bool itemFound;
	current = current->getRoomInfo();

}

/*********************************************************************  
** Function:  SHOW LINKS
** Description:  CALLS DISPLAY LINKS FOR THE CURRENT ROOM
** Parameters:  NONE
** Pre-Conditions:  CURRENT MUST BE POINTING TO A ROOM
** Post-Conditions:  NONE
*********************************************************************/
void Ship::showLinks()
{
	std::cout << "You can travel to these rooms:" << std::endl;
	current->displayLinks();
}

/*********************************************************************  
** Function:  GET CURRENT ROOM NAME NAME
** Description:  RETURNS THE NAME OF THE CURRENT ROOM
** Parameters:  NONE
** Pre-Conditions:  CURRENT MUST BE POINTING TO A ROOM
** Post-Conditions:  NONE
*********************************************************************/
std::string Ship::getCurrentRoomName()
{	
	std::string currentName = current->getRoomName();
	return currentName;
}

/*********************************************************************  
** Function:  SOLVE
** Description:  DISPLAYS THE MENU OF CHOICES THE USER HAS TO SOLVE
**	THE MYSTERY. DISPLAYS A MESSAGE DEPENDING UPON THE ANSWER
** Parameters:  NONE
** Pre-Conditions:  USER MUST HAVE FOUND THE 3 ITEMS.
** Post-Conditions:  THE GAME ENDS
*********************************************************************/
void Ship::solve()
{
	int accuse;
	for(int x = 0; x<17; x++)
		{std::cout << std::endl;}
	std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "			You have found all of the clues! You must now confront the man who murdered your father." << std::endl;
	std::cout << std::endl << "			Was it: " << std::endl << std::endl;
	std::cout << "				1. Pengon, the only archer on the crew " << std::endl;
	std::cout << "				2. Gorfuinor, the lookout who was secretly learning archery " << std::endl;
	std::cout << "				3. Thannor, the seemingly loyal first mate" << std::endl;
	std::cout << "				4. Amathon, the guard with an obsession with weapons " << std::endl;
	std::cout << "				5. Maeasson, the cook" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cin >> accuse;
	
	for(int x = 0; x<17; x++)
		{std::cout << std::endl;}

	if(accuse < 1 || accuse > 5)
		{std::cout << "		Please make a correct choice. " << std::endl;
		std::cin >> accuse;}

	else if(accuse == 1 || accuse == 3 || accuse == 4 || accuse == 5)
	{
		std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "		You are wrong! You have accused the wrong person and now the crew is rising against you!" << std::endl;
		std::cout << "		The real murderer was Gorfuinor. He is a cheat and a scoundrel and  your father never trusted him. " << std::endl;
		std::cout << "		Gorfuinor resented your father and wanted to turn the crew against him. Now he may get his wish. " << std::endl;
		std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
			for(int x = 0; x<8; x++)
		{std::cout << std::endl;}
	}
	else if(accuse == 2)
	{
		std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "		Correct! The crew roars in outrage and throws Gorfuinor in the holding cell!" << std::endl;
		std::cout << "		He is a cheat and a scoundrel and your father never trusted him. " << std::endl;
		std::cout << "		Gorfuinor resented your father and wanted to turn the crew against him. " << std::endl;
		std::cout << "		Your father's goodness prevails and Gorfuinor will be brought to justice." << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
			for(int x = 0; x<8; x++)
		{std::cout << std::endl;}
	}

}