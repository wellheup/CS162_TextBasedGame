/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements Game class which will run the game using 
** World, Item, Space and Space derived classes
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "menuShell.hpp"
#include "Item.hpp"
#include "Space.hpp"
#include "World.hpp"
#include "Game.hpp"
#include "Inventory.hpp"

Game::Game(){
	initValues();
}

//destructor
Game::~Game(){
	if (myInventory != nullptr) {
		delete myInventory;
	}
	if (myShip != nullptr) {
		delete myShip;
	}
}

/*********************************************************************
** Description: menthod used to initialize values and startup attributes
*********************************************************************/
void Game::initValues() {
	startingSteps = 25;
	currentPlayerSteps = startingSteps;
	gameOver = false;
	myInventory = new Inventory(8);
	myShip = new World;
	initMap();
	initDirections();
}

/*********************************************************************
** Description: runs all primary game functions and game loop
*********************************************************************/
void Game::runGame() {
	std::cout << directions << std::endl;
	setStartingSpace();
	gameOver = false;
	while (gameOver == false) {
		std::cout << map << std::endl;
		std::cout << "-----" << currentPlayerSteps * 10 << " minutes of Oxygen remaining (" << currentPlayerSteps << " steps)"
			<< "-----" << checkCurrentLifeSupport() << "-----" << std::endl;
		incrementSteps();
		if (gameOver == false) {
			runCurrentSpace();
			checkLoseConditions();
		}
	}
	std::cout << "Press Enter to Exit";
	std::cin.ignore();
}

/*********************************************************************
** Description: sets the starting space for the player
*********************************************************************/
void Game::setStartingSpace() {
	this->currentSpace = myShip->getCrewQuarters();
}

/*********************************************************************
** Description: manages the number of steps the player has remaining
** adding an extra step in spaces with atmosphere and subtracting 
** an extra step for those without atmosphere
*********************************************************************/
void Game::incrementSteps() {
	if (currentSpace->getIsSealed() == true && myShip->getLifeSupportIsFixed() == true) {
		currentPlayerSteps -= 1;
	}
	else if (currentSpace->getIsSealed() == false) {
		currentPlayerSteps -= 2;
	}
	else if (currentSpace->getSpaceKind() == OUTER_SPACE) {
		currentPlayerSteps -= 3;
	}
	if (currentPlayerSteps <= 0 && myInventory->checkForItem(EXTRA_O2) == true) {
		myInventory->deleteItem(EXTRA_O2);
		currentPlayerSteps += 4;
		std::cout << "**Extra Oxygen Tank used to replenish 4 steps of Oxygen**";
	}
}

/*********************************************************************
** Description: calls updatespace for the current space and checks to 
** see if the player has met victory conditions. If the current space 
** is in Outer Space, then extra steps are subtracted and a special 
** interaction menu is run from World
*********************************************************************/
void Game::runCurrentSpace() {
	currentSpace->updateRoom(myInventory, myShip->getLifeSupportIsFixed());
	checkWinConditions();
	if (gameOver == false) {
		if (currentSpace->getSpaceKind() == OUTER_SPACE) {
			currentSpace = myShip->enterFromOuterSpace();
		}
		else {
			currentSpace = currentSpace->displaySpaceOptions(myInventory);
		}
	}
}

/*********************************************************************
** Description: checks for lose conditions and ends the game if they
** are met
*********************************************************************/
void Game::checkLoseConditions() {
	if (currentPlayerSteps <= 0) {
		std::cout << "You are dead. You suffocated before reaching the safety of your Escape Pod." << std::endl;
		gameOver = true;
	}
}

/*********************************************************************
** Description: checks for win conditions and ends game if they are met
*********************************************************************/
void Game::checkWinConditions() {
	if (currentSpace->getSpaceKind() == ESCAPE_PODS) {
		if (myInventory->checkForItem(FOOD) == true && myInventory->checkForItem(RESEARCH_DATA)) {
			if (myShip->getEscapePodsIsFixed() == true) {
				std::cout << "!*!*!*!*!*!*nCongratulations! You've escaped with your life and the data!!*!*!*!*!*!*\n\n\n" << std::endl;
				gameOver = true;
			}
			else if (myInventory->checkForItem(REPAIR_KIT) == true && myInventory->checkForItem(DISTRESS_SIGNAL)) {
				std::cout << "!*!*!*!*!*!*nCongratulations! You've escaped with your life and the data!!*!*!*!*!*!*\n\n\n" << std::endl;
				gameOver = true;
			}
		}
	}
}

/*********************************************************************
** Description: creates a map string for player reference 
*********************************************************************/
void Game::initMap() {
	map =
		"\tMap:            U.N.S.S. Labby McLabface\n"
		"\n"
		"\t-----][--------][---------][---------][--------][------\n"
		"\t|         |  Life    |          |  Hydro-  |          |\n"
		"\t|         = Support  =   Labs   =  ponics  =          |\n"
		"\t| Engines |----------|----------|----------| Command  |\n"
		"\t|         =  Escape  =  Cargo   =   Crew   =  Bridge  |\n"
		"\t|         |   Pods   |   Bay    | Quarters |          |\n"
		"\t-----][--------][---------][---------][--------][------\n"
		"\t*Note*: All cabins/decks have airlock exits to space\n";
}

void Game::initDirections() {
	directions = "Notes/Directions:\n"
		/*********************************************************************/
		"1. Though assignment criteria are met, the game may seem incomplete \n"
		"   because some features were cut.\n"
		"2. If you travel through spaces without oxygen or through outer \n"
		"   space, steps (minutes of oxygen) will be lost at an accelerated rate \n"
		"   however, traveling through oxygenated spaces will slowly replenish \n"
		"   oxygen and if you're carrying an O2 cannister when reaching 0 steps \n"
		"   it will be removed in exchange for 4 extra steps. *Note that \n"
			"checking your inventory will consume a step and reduce steps*\n"
		"3. In order to move items between a space and your inventory, you \n"
		"   must elect to \"Move Items\" from the menu\n"
		"4. You must have items in your inventory for them the be utilized and \n"
		"   items will automatically be used if the criteria is met for their use \n"
		"   in a space just entered.\n"
		"5. **To win, you must reach the Escape Pods with Research Data, a Repair \n"
		"   Kit, Survival Rations, and a Distress Beacon before running out of Oxygen.\n\n";
}

void Game::printMap() {
	std::cout << map << std::endl;
}

/*********************************************************************
** Description: updates the message string for the status of the 
** oxygen in the space if it is or is not sealed
*********************************************************************/
std::string Game::checkCurrentLifeSupport() {
	if (currentSpace->getIsSealed() == true && myShip->getLifeSupportIsFixed() == true) {
		return "space has Oxygen";
	}
	else {
		return "space has no Oxygen";
	}
}
