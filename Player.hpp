/********************************************************
* PROGRAM FILENAME: PLAYER.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE IS THE HEADER FILE FOR THE PLAYER 
*	CLASS FOR THE GAME "BETRAYAL ON THE ALQUACIR"
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Item.hpp"
#include <vector>
#include <iostream>
#include <string>

class Player
{
protected:
	std::string name;
	std::vector<Item> sack;

public:
		Player();
		void introduction();
		void listSack();
		void addInk();
		void addLog();
		void addArrow();
		void removeItem(Item f);
		std::string getName(){return name;}
		int itemCount;
		int getItemCount();
		
//CREATE THE 3 ITEM OBJECTS
		Log cLog;
		Arrow bArrow;
		Residue ink;
};
#endif