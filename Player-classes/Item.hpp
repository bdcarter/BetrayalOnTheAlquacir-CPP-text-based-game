/********************************************************
* PROGRAM FILENAME: ITEM.HPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THE HEADER FILE FOR THE ITEM CLASS 
*	FOR THE GAME "BETRAYAL ON THE ALQUACIR"
* INPUT: NONE
* OUTPUT: NONE
***********************************************************/


#ifndef ITEM_CPP
#define ITEM_CPP
#include <string>

class Item
{
protected:
	std::string name, desc;

public:
	Item();
	Item(std::string, std::string);
	std::string getName();
	std::string getDesc();

};


/********************************************************
*CHILD CLASS LOG: CONSTRUCTS A LOG ITEM
**************************************************/
class Log : public Item
{
public:
	Log();
};

/********************************************************
*CHILD CLASS ARROW: CONSTRUCTS AN ARROW ITEM
**************************************************/
class Arrow : public Item
{
public:
	Arrow();
};


/********************************************************
*CHILD CLASS RESIDUE: CONSTRUCTS A RESIDUE ITEM
**************************************************/
class Residue : public Item
{
public:
	Residue();
};
#endif