/********************************************************
* PROGRAM FILENAME: ITEM.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE PROVIDES THE IMPLEMENTATION FOR 
*	THE ITEM CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/

#include "Item.hpp"
#include <string>
#include <iostream>

Item::Item()
{
	name = "x";
	desc = "x";
}

Item::Item(std::string nameIn, std::string descIn)
{
	name = nameIn;
	desc = descIn;

}

/*********************************************************************  
** Function:  GET NAME
** Description:  RETURNS THE ITEM NAME
** Parameters:  NONE
** Pre-Conditions:  NONE
** Post-Conditions:  NONE
*********************************************************************/
std::string Item::getName()
{
	return name;
}

/*********************************************************************  
** Function:  GET DESCRIPTION
** Description:  RETURNS THE ITEM DESCRIPTION
** Parameters:  NONE
** Pre-Conditions:  NONE
** Post-Conditions:  NONE
*********************************************************************/
std::string Item::getDesc()
{
	return desc;
}



Log::Log()
{
	name = "Captains Log";
	desc = "There are pages torn out. Looks like they were from the day before the accident.";
}

Arrow::Arrow()
{
	name = "Broken Arrow";
	desc = "Why would someone need a bow and arrow up here?";
}

Residue::Residue()
{
	name = "Black residue";
	desc = "This black residue looks familiar. Could be ink of some sort.";
}









