/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for Engines class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include "menuShell.hpp"
#include "Space.hpp"
#include "Engines.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

Engines::Engines(Space* north, Space* east, Space* south, Space* west) {
  north = nullptr;
  east = nullptr;
  south = nullptr;
  west = nullptr;
  this->_ptrNorthSpace = north;
	this->_ptrEastSpace = east;
	this->_ptrSouthSpace = south;
	this->_ptrWestSpace = west;
	initSpace();
}

Engines::~Engines() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
	this->_ptrEast2Space = nullptr;
	if (_spaceInventory != nullptr) {
		delete _spaceInventory;
		_spaceInventory = nullptr;
	}

}

void Engines::initSpace() {
	_strSpaceName = "Engines";
	_strSpaceDesc = "[Engines] The Engine Room, though it is dark, seems to have suffered minimal damage from the asteroids, most of which has been "
		"contained by emergency contingencies. Everything seems to be operating, and the ship has not lost power.";
	_strSpaceInspect = "[Engines] There are obvious signs of the storm here, but fortunately everything is in working order thanks to emergency "
		"contingencies.\n";
	_isSealed = true;
	_kindOfSpace = ENGINES;
	_spaceInventory = new Inventory(100);
	_spaceInventory->addItem(new Item(REPAIR_KIT));
	_spaceInventory->addItem(new Item(FIRE_EXTINGUISHER));
	_spaceInventory->addItem(new Item(CROBAR));
}

void Engines::setExtraDirections() {
	this->_ptrEast2Space = this->_ptrEastSpace->getSouth();
}

/*********************************************************************
** Description: Overrides base's method, to add an extra string
*********************************************************************/
void Engines::setDoorStatus() {
	_strNorthDoor = "To " + _ptrNorthSpace->getSpaceName();
	_strEastDoor = "To " + _ptrEastSpace->getSpaceName();
	_strSouthDoor = "To " + _ptrSouthSpace->getSpaceName();
	_strWestDoor = "To " + _ptrWestSpace->getSpaceName();
	_strEast2Door = "To " + _ptrEast2Space->getSpaceName();
}

/*********************************************************************
** Description: Overrides base's method, to add an extra option to 
** the Engine room exits
*********************************************************************/
Space * Engines::displaySpaceOptions(Inventory * playerInventoryIn) {
	std::vector<std::string> chooseOptions;
	chooseOptions.push_back(_strSpaceDesc);
	chooseOptions.push_back("\t1. Check inventory");
	chooseOptions.push_back("\t2. Take the North door: " + _strNorthDoor);
	chooseOptions.push_back("\t3. Take the East door: " + _strEastDoor);
	chooseOptions.push_back("\t4. Take the East door: " + _strEast2Door);
	chooseOptions.push_back("\t5. Take the South door: " + _strSouthDoor);
	chooseOptions.push_back("\t6. Take the West door: " + _strWestDoor);
	chooseOptions.push_back("\t7. Inspect the room");

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
				tempSpace = this->_ptrEast2Space;
				choice = chooseOptions.size() - 1;
			break;
		case 5:
				tempSpace = this->getSouth();
				choice = chooseOptions.size() - 1;
			break;
		case 6:
				tempSpace = this->getWest();
				choice = chooseOptions.size() - 1;
			break;
		case 7:
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

bool Engines::getIsFixed() {
	return this->_enginesAreReset;
}

void Engines::updateRoom(Inventory * playerInventoryIn, bool isLifesupportOn) {
	//if (_enginesAreReset == false) {
	//	if (playerInventoryIn->checkForItem(EXPLOSIVES) == true || playerInventoryIn->checkForItem(LVL3_CLEARANCE)==false) {
	//		std::cout << "The improvised explosives are enough to reset the ship's security protocols. Thanks, chemistry." << std::endl;
	//		_enginesAreReset = true;
	//		_strSpaceInspect = "[Engines] There are obvious signs of the storm here, but fortunately, despite what you've put them through "
	//			"in addition to the asteroids, they're still powering the ship, and they're only a little bit on fire... the security system "
	//			"has been reset and any doors not leading to an unrecoverable part of the ship should be open to you now.\n";
	//	}
	//	else if(playerInventoryIn->checkForItem(LVL3_CLEARANCE) == true){
	//		std::cout << "Level 3 Clearance allows you to reset the engines with ease." << std::endl;
	//		_enginesAreReset = true;
	//		_strSpaceInspect = "[Engines] There are obvious signs of the storm here, but fortunately they're still powering the ship, "
	//			"and they probably won't blow up because you used Level 3 Clearance to reset them. The security system "
	//			"has been reset and any doors not leading to an unrecoverable part of the ship should be open to you now.\n";
	//	}
	//}
}
