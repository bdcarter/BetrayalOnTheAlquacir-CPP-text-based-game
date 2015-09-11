/********************************************************
* PROGRAM FILENAME: PLAYER.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE PROVIDES THE IMPLEMENTATION FOR 
*	THE PLAYER CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
* 	THIS CLASS CREATES THE PLAYER OBJECT, INTRODUCES 
*	THE GAME TO THE USER, KEEPS TRACK OF THE ITEMS THE 
*	USER FINDS, CHECKS IF THE ITEM IS ALREADY FOUND, 
*	ADDS IT TO THE SACK IF NOT, AND DISPLAYS THE 
*	CONTENTS.
* INPUT: NONE
* OUTPUT: THE TEXT INTRODUCTION OF THE GAME, CONTENTS OF
*	THE USER'S SACK.
***********************************************************/


#include "Player.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>



Player::Player()
{
	name = "Glingaerwen";
	itemCount = 0;

}

/*********************************************************************  
** Function:  INTRODUCTION
** Description:  GIVES THE BACKSTORY OF THE GAME AND TELLS THE USER
**	WHAT THE GOAL IS.
** Parameters:  NONE
** Pre-Conditions:  THE PLAYER MUST CHOOSE TO START THE GAME
** Post-Conditions:  THE USER MUST CHOOSE TO CONTINUE
*********************************************************************/
void Player::introduction()
{
	char ch;
	std::cin.ignore();
	for(int x = 0; x<17; x++)
		{std::cout << std::endl;}
	std::cout << std::setw(65) << "BETRAYAL ON THE ALQUACIR" << std::endl;
	std::cout << std::setw(62) << "BY BRIANNA CARTER" << std::endl << std::endl;

	std::cout << std::setw(25)<< "			You are an elf named " << getName() << ". Your father was Aglaron, the " << std::endl;
	std::cout << std::setw(50)<< "		greatest captain your people have ever known. He had won many battles and" << std::endl;
	std::cout << std::setw(50)<< " 		sailed across the earth. You were raised on the sea and there is no better" << std::endl;
	std::cout << std::setw(50)<< " 		home than Alquacir. You crave the ocean breeze and the adventure of the open water." << std::endl << std::endl;
	std::cout << std::setw(50)<< "		Two days ago there was a terrible storm and tragedy struck the Alquacir when your " << std::endl;
	std::cout << std::setw(50)<< "		father fell overboard. Or at least that is what you were led to believe." << std::endl << std::endl;
	std::cout << std::setw(50)<< "		Over the past few weeks you noticed new tension between some of the crew and your " << std::endl;
	std::cout << std::setw(50)<< "		father. He never spoke of it to you but you knew trouble was brewing. You suspect" << std::endl;
	std::cout << std::setw(50)<< " 		someone was angry and used the storm as cover to murder your father." << std::endl << std::endl;
	std::cout << std::setw(50)<< "		Now you must search the ship for clues and find the responsible party." << std::endl;
	std::cout << std::setw(50)<< "		Use caution, the killer suspects your suspicions and another storm could " << std::endl;
	std::cout << std::setw(50)<< "		rage any day, and you don't want to take any chances." << std::endl << std::endl;
	std::cout << std::setw(50)<< "		You will need to search the ship and find three clues and speak with other " << std::endl;
	std::cout << std::setw(50)<< "		crew members to solve the mystery. When the three objects are found, you will " << std::endl;
	std::cout << std::setw(50)<< "		accuse the killer. Be careful, if you're wrong the crew will turn against you." << std::endl << std::endl;
	std::cout << std::setw(50)<< "			You begin in the hallway." << std::endl << std::endl << std::endl;
	std::cout << std::setw(50) << "		Press enter to begin..." << std::endl;
	std::cin.get(ch);
		for(int x = 0; x<5; x++)
		{std::cout << std::endl;}
}


/*********************************************************************  
** Function:  GET ITEM COUNT
** Description:  RETURNS THE NUMBER OF ITEMS THE USER HAS FOUND
** Parameters:  NONE
** Pre-Conditions:  NONE
** Post-Conditions:  NONE
*********************************************************************/

int Player::getItemCount()
{return itemCount;}


/*********************************************************************  
** Function:  ADD INK
** Description:  CHECKS THE VECTOR FOR THE INK ITEM, IF IT ISN'T FOUND
**	INK IS ADDED TO THE VECTOR, LETS THE USER KNOW IT WAS ADDED, AND 
**	INCREASES THE ITEM COUNT
** Parameters:  NONE
** Pre-Conditions:  AFTER THE USER CHANGES ROOMS, IF THE INK SMUDGE 
**	WAS FOUND, THIS FUNCTION IS CALLED.
** Post-Conditions:  IF THE INK SMUDGE WAS ALREADY FOUND, NOTHING 
**	HAPPENS. IF THE INK SMUDGE WASN'T ALREADY FOUND, IT IS ADDED 
**	TO THE SACK AND THE ITEM COUNT IS INCREASED.
*********************************************************************/
void Player::addInk()
{

//BOOL TO INDICATE IF THE ITEM IS PRESENT
	bool present = false;

//SEARCH THE VECTOR FOR THE ITEM, IF FOUND SET PRESENT TO TRUE
	for(int x=0; x<sack.size(); x++)
	{
		if(sack[x].getName() == ink.getName())
		{present = true;}
	}

//IF THE ITEM WASN'T FOUND, ADD IT TO THE VECTOR, STATE THAT IT WAS ADDED, INCREASE THE ITEM COUNT
	if(present == false)
	{
		sack.push_back(ink);
		std::cout << "		Added " << ink.getName() << " to your sack." << std::endl;
		itemCount++;
	}	
	
}


/*********************************************************************  
** Function:  ADD LOG
** Description:  CHECKS THE VECTOR FOR THE LOG ITEM, IF IT ISN'T FOUND
**	LOG IS ADDED TO THE VECTOR, LETS THE USER KNOW IT WAS ADDED, AND 
**	INCREASES THE ITEM COUNT
** Parameters:  NONE
** Pre-Conditions:  AFTER THE USER CHANGES ROOMS, IF THE LOG 
**	WAS FOUND, THIS FUNCTION IS CALLED.
** Post-Conditions:  IF THE LOG WAS ALREADY FOUND, NOTHING 
**	HAPPENS. IF THE LOG WASN'T ALREADY FOUND, IT IS ADDED 
**	TO THE SACK AND THE ITEM COUNT IS INCREASED.
*********************************************************************/

void Player::addLog()
{
//BOOL TO INDICATE IF THE ITEM IS PRESENT
	bool present = false;

//SEARCH THE VECTOR FOR THE ITEM, IF FOUND SET PRESENT TO TRUE
	for(int x = 0; x < sack.size(); x++)
	{
		if(sack[x].getName() == cLog.getName())
		{present = true;}
	}

//IF THE ITEM WASN'T FOUND, ADD IT TO THE VECTOR, STATE THAT IT WAS ADDED, INCREASE THE ITEM COUNT
	if(present == false)
	{
		sack.push_back(cLog);
		std::cout << "		Added " << cLog.getName() << " to your sack." << std::endl;
		itemCount++;
	}	
	
}

/*********************************************************************  
** Function:  ADD ARROW
** Description:  CHECKS THE VECTOR FOR THE ARROW ITEM, IF IT ISN'T FOUND
**	ARROW IS ADDED TO THE VECTOR, LETS THE USER KNOW IT WAS ADDED, AND 
**	INCREASES THE ITEM COUNT
** Parameters:  NONE
** Pre-Conditions:  AFTER THE USER CHANGES ROOMS, IF THE ARROW 
**	WAS FOUND, THIS FUNCTION IS CALLED.
** Post-Conditions:  IF THE ARROW WAS ALREADY FOUND, NOTHING 
**	HAPPENS. IF THE ARROW WASN'T ALREADY FOUND, IT IS ADDED 
**	TO THE SACK AND THE ITEM COUNT IS INCREASED.
*********************************************************************/
void Player::addArrow()
{
//BOOL TO INDICATE IF THE ITEM IS PRESENT
	bool present = false;

//SEARCH THE VECTOR FOR THE ITEM, IF FOUND SET PRESENT TO TRUE
	for(int x= 0; x<sack.size(); x++)
	{
		if(sack[x].getName() == bArrow.getName())
			{present = true;}
	}

//IF THE ITEM WASN'T FOUND, ADD IT TO THE VECTOR, STATE THAT IT WAS ADDED, INCREASE THE ITEM COUNT
	if(present == false)
	{
		sack.push_back(bArrow);
		std::cout << "	Added " << bArrow.getName() << " to your sack." << std::endl;
		itemCount++;
	}	
	
}


/*********************************************************************  
** Function:  REMOVE ITEM
** Description:  REMOVES AN ITEM FROM THE SACK
** Parameters:  ITEM
** Pre-Conditions:  NONE
** Post-Conditions:  IF THE ITEM IS IN THE VECTOR, IT WILL BE DELETED
*********************************************************************/
void Player::removeItem(Item f)
{
//LIST THROUGH ALL OF THE VECTOR ELEMENTS
	for(int x = 0; x < sack.size(); x++)
	{
//IF THEY ARE THE SAME, ERASE THE ITEM
		if(sack[x].getName() == f.getName())
		{
			sack.erase(sack.begin() + x);
		}
	}

}

/*********************************************************************  
** Function:  LIST SACK
** Description:  LISTS ALL OF THE ELEMENTS IN THE SACK
** Parameters:  NONE
** Pre-Conditions:  NONE
** Post-Conditions:  DISPLAYS THE NAMES AND DESCRIPTIONS OF ALL VECTOR ITEMS
*********************************************************************/

void Player::listSack()
{
//IF THE VECTOR IS EMPTY
	if(sack.size() == 0)
		{std::cout << "	Your sack is empty." << std::endl << std::endl;}

//LOOP THROUGH THE VECTOR AND DISPLAY THE NAME AND DESCRIPTION
	else
	{	std::cout << "	Your sack contains: " << std::endl;
		for(int x = 0; x < sack.size(); x++)
		{
		std::cout << "	" << sack[x].getName() << std::endl;
		std::cout << "	" << sack[x].getDesc() << std::endl;
		std::cout << std::endl << std::endl;
		}
	}
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	
}

