/********************************************************
* PROGRAM FILENAME: MAIN.CPP
* AUTHOR: BRIANNA CARTER
* DATE: 6/5/15
* DESCRIPTION: THIS FILE PROVIDES THE MAIN FUNCTION 
*	FOR THE GAME "BETRAYAL ON THE ALQUACIR"
* INPUT: THE USER CHOOSES WHETHER TO SEE THE SOLUTION
*	OR GO STRAIGHT TO THE GAME. THE USER WILL CHOOSE 
*	WHERE TO MOVE AND WHAT ACTIONS TO TAKE.
* OUTPUT: THE TEXT DESCRIPTION OF EACH ROOM AND THE CHOICES 
*	FOR WHERE THE USER CAN NAVIGATE OR HOW THEY CAN INTERACT. 
*	WHEN THE USER FINDS ALL OF THE OBJECTS, A MENU IS DISPLAYED 
*	SO THE USER CAN CHOOSE THIER ANSWER.
***********************************************************/



#include "Ship.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>

int main()
{

//INITIATE SHIP OBJECT
	Ship puzzle;
	int view;

//CLEAR SCREEN
	for(int x = 0; x<14; x++)
	{std::cout << std::endl;}

//DISPLAY THE ANSWER IF YOU NEED HELP
		std::cout << "			Welcome! Enter 1 to start the game. " << std::endl;
		std::cout << "				Enter 2 to see the solution. " << std::endl;
		std::cin >> view;
		std::cout << std::endl << std::endl;

	if (view == 2)
		{puzzle.answer();}


//CREATE THE ROOMS
	puzzle.createRooms();

//INITIATE THE PLAYER
	Player p;

//INTRODUCE THE GAME 
	
	p.introduction();

//WHILE THE USER IS SEARCHING FOR THE 3 ITEMS, CONTINUE TO CHANGE ROOMS
do
{
//DISPLAY CURRENT ROOM
	std::cout << "	Current room: " << puzzle.getCurrentRoomName() << std::endl;

//CALL THE FUNCTION THAT NAVIGATES THROUGH THE ROOM
	puzzle.getCurrentRoom();	

///CHECK IF THE USER FOUND AN ITEM AND ADD IT TO THE SACK
	if(puzzle.getInk())
		{p.addInk();}
	if(puzzle.getA())
		{p.addArrow();}
	if(puzzle.getBook())
		{p.addLog();}

//LIST THE ITEMS IN THE SACK
	p.listSack();

}while(p.getItemCount() != 3);

//WHEN THE USER FINDS ALL 3 ITEMS, CALL THE SOLVE FUNCTION
	puzzle.solve();

return 0;

}
