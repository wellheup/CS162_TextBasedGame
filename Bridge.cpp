/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for Bridge class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include "menuShell.hpp"
#include "Space.hpp"
#include "Bridge.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

Bridge::Bridge(Space* north, Space* east, Space* south, Space* west) {
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

Bridge::~Bridge() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
	this->_ptrWest2Space = nullptr;
	if (_spaceInventory != nullptr) {
		delete _spaceInventory;
		_spaceInventory = nullptr;
	}

}

void Bridge::initSpace() {
	_strSpaceName = "Command Bridge";
	_strSpaceDesc = "[Command Bridge] The Command Bridge has been irreparably damaged, but some of the systems still work. ";
	_strSpaceInspect = "[Command Bridge] The bodies of several of your crewmates are strewn about the cabin. There's no way they're still alive. Despite a "
		"large asteroid being wedged into the cabin, it is surprisingly well sealed, however this ship will not be functioning again any "
		"time soon. Oh, look, First Officer Susan is wedged under the asteroids\n";
	_isSealed = false;
	_kindOfSpace = BRIDGE;
	_spaceInventory = new Inventory(100);
	_spaceInventory->addItem(new Item(LVL2_CLEARANCE));
}

void Bridge::setExtraDirections() {
	this->_ptrWest2Space = this->_ptrWestSpace->getNorth();
}

/*********************************************************************
** Description: Overrides base's method, to add an extra string
*********************************************************************/
void Bridge::setDoorStatus() {
	_strNorthDoor = "To " + _ptrNorthSpace->getSpaceName();
	_strEastDoor = "To " + _ptrEastSpace->getSpaceName();
	_strSouthDoor = "To " + _ptrSouthSpace->getSpaceName();
	_strWestDoor = "To " + _ptrWestSpace->getSpaceName();
	_strWest2Door = "To " + _ptrWest2Space->getSpaceName();
}

/*********************************************************************
** Description: Overrides base's method, to add an extra option to
** the Bridge room exits
*********************************************************************/
Space* Bridge::displaySpaceOptions(Inventory *playerInventoryIn) {
	std::vector<std::string> chooseOptions;
	chooseOptions.push_back(_strSpaceDesc);
	chooseOptions.push_back("\t1. Check inventory");
	chooseOptions.push_back("\t2. Take the North door: " + _strNorthDoor);
	chooseOptions.push_back("\t3. Take the East door: " + _strEastDoor);
	chooseOptions.push_back("\t4. Take the South door: " + _strSouthDoor);
	chooseOptions.push_back("\t5. Take the West door: " + _strWestDoor);
	chooseOptions.push_back("\t6. Take the West door: " + _strWest2Door);
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
				tempSpace = this->getSouth();
				choice = chooseOptions.size() - 1;
			break;
		case 5:
				tempSpace = this->getWest();
				choice = chooseOptions.size() - 1;
			break;
		case 6:
				tempSpace = this->_ptrWest2Space;
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

void Bridge::updateRoom(Inventory * playerInventoryIn, bool isLifesupportOn) {}
