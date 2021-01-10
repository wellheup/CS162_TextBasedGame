/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for Space class header. 
** Space is used for creating each space in the game world. 
*********************************************************************/
#include <iostream>
#include <string>
#include "menuShell.hpp"
#include "Space.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

Space::Space() {}

Space::Space(Space* north, Space* east, Space* south, Space* west) {
  north = nullptr;
  east = nullptr;
  south = nullptr;
  west = nullptr;
  _strSpaceDesc = "Error: base class should not exist here!";
	_strSpaceInspect = "Error: the base class should never be inspected!:";
	_strSpaceName = "Base Space";
	_isSealed = true;
	_kindOfSpace = BASE_SPACE;
	_spaceInventory = new Inventory(100);
}


Space::~Space() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
	if (_spaceInventory != nullptr) {
		delete _spaceInventory;
	}

}

Space * Space::getNorth() {
	return this->_ptrNorthSpace;
}

Space * Space::getEast() {
	return this->_ptrEastSpace;
}

Space * Space::getSouth() {
	return this->_ptrSouthSpace;
}

Space * Space::getWest() {
	return this->_ptrWestSpace;
}

bool Space::getIsSealed() {
	return this->_isSealed;
}

bool Space::getIsFixed() {
	return true;
}

void Space::setNorth(Space * pointTo) {
	this->_ptrNorthSpace = pointTo;
}

void Space::setEast(Space * pointTo) {
	this->_ptrEastSpace = pointTo;
}

void Space::setSouth(Space * pointTo) {
	this->_ptrSouthSpace = pointTo;
}

void Space::setWest(Space * pointTo) {
	this->_ptrWestSpace = pointTo;
}

/*********************************************************************
** Description: Sets the 4 primary pointers for a Space object
*********************************************************************/
void Space::setCardinalDirections(Space * north, Space * east, Space * south, Space * west) {
	this->_ptrNorthSpace = north;
	this->_ptrEastSpace = east;
	this->_ptrSouthSpace = south;
	this->_ptrWestSpace = west;
}

/*********************************************************************
** Description: used for setting extr pointers to spaces if a derived
** class needs to
*********************************************************************/
void Space::setExtraDirections() {}

/*********************************************************************
** Description: Manages actions while player is in the space by providing
** a list of options and reacting to the user's choice
*********************************************************************/
Space* Space::displaySpaceOptions(Inventory *playerInventoryIn) {
	std::vector<std::string> chooseOptions;
	chooseOptions.push_back("\n" +_strSpaceDesc);
	chooseOptions.push_back("\t1. Check inventory");
	chooseOptions.push_back("\t2. Take the North door: " + _strNorthDoor);
	chooseOptions.push_back("\t3. Take the East door: " + _strEastDoor);
	chooseOptions.push_back("\t4. Take the South door: " + _strSouthDoor);
	chooseOptions.push_back("\t5. Take the West door: " + _strWestDoor);
	chooseOptions.push_back("\t6. Inspect the room");

	Space* tempSpace = this;
	unsigned int choice = 0;
	while (choice != chooseOptions.size() - 1) {
		choice = choiceMenuMulti(&chooseOptions);
		switch (choice) {
		case 1:
			playerInventoryIn->displayInventory(_spaceInventory);
			choice = chooseOptions.size() - 1;
			break;
		case 2:
				tempSpace = this->getNorth();
				choice = chooseOptions.size() - 1;
			break;
		case 3: 
				tempSpace = this->getEast();
				choice = chooseOptions.size() - 1;
			break;
		case 4:
				tempSpace = this->getSouth();
				choice = chooseOptions.size() - 1;
			break;
		case 5:
				tempSpace = this->getWest();
				choice = chooseOptions.size() - 1;
			break;
		case 6:
			this->displaySpaceParticulars(playerInventoryIn);
			choice = chooseOptions.size() - 1;
			break;
		default:
			std::cout << "Error in choosing options" << std::endl;
			break;
		}
	}
	return tempSpace;
}

/*********************************************************************
** Description: describes the space further and then displays the 
** space's inventory
*********************************************************************/
void Space::displaySpaceParticulars(Inventory *playerInventoryIn) {
	std::cout << this->_strSpaceInspect << std::endl;;//deeper description
	this->_spaceInventory->displayInventory(playerInventoryIn);
}

/*********************************************************************
** Description: Sets strings to refer to the spaces in each direction
** from the current space
*********************************************************************/
void Space::setDoorStatus() {
	_strNorthDoor = "To " + _ptrNorthSpace->getSpaceName();
	_strEastDoor = "To " + _ptrEastSpace->getSpaceName();
	_strSouthDoor = "To " + _ptrSouthSpace->getSpaceName();
	_strWestDoor = "To " + _ptrWestSpace->getSpaceName();
}

/*********************************************************************
** Description: Allows for derived classes to update particular attributes
** based on whether LifeSupport has been fixed and the player's  inventory
*********************************************************************/
void Space::updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) {}

SpaceKind Space::getSpaceKind() {
	return this->_kindOfSpace;
}

std::string Space::getSpaceName() {
	return this->_strSpaceName;
}
