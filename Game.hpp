/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies Game class which will run the game using 
** World, Item, Space and Space derived classes
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include "World.hpp"//class World;
#include "Space.hpp"//class Space;
class Item;



class Game {
private:
	Inventory* myInventory;
	World* myShip;
	int currentPlayerSteps,
		startingSteps;
	bool gameOver;
	std::string map,
		directions;
protected:

public:
	Space* currentSpace;

	Game();

	//destructor
	~Game();

	void initValues();
	void runGame();
	void setStartingSpace();
	void incrementSteps();
	void runCurrentSpace();
	void checkLoseConditions();
	void checkWinConditions();
	void initMap();
	void initDirections();
	void printMap();
	std::string checkCurrentLifeSupport();
};
#endif
