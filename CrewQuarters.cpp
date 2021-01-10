/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for CrewQuarters class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Space.hpp"
#include "CrewQuarters.hpp"
#include "menuShell.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

CrewQuarters::CrewQuarters(Space* north, Space* east, Space* south, Space* west) {
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

CrewQuarters::~CrewQuarters() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
}

void CrewQuarters::initSpace() {
	_strSpaceName = "Crew Quarters";
	_strSpaceDesc = "[Crew Quarters] The Crew Quarters are in disarray but you are unharmed. The last thing you remember is shouting over the intercom, "
		"the ship jolting violently, and hitting your head. Red lights flash, a siren blares, and the ship's AI shouts alternating alerts, "
		"\"An asteroid collision event has catastrophically damaged the ship, please proceed to the the emergency "
		"escape pods!\" and \"Security lockdown in effect until further notice\"";
	_strSpaceInspect = "[Crew Quarters] You were very lucky to have your space suit on when the asteroid shower hit. It looks like everyone who survived here, "
		"suffocated shortly thereafter.The bodies of your crewmates are strewn about the cabin. You only have a small amount of oxygen "
		"remaining in your suit but it might be enough to get to an Escape Pod. Clearly the security lockdown is malfunctioning, because, "
		"most of the doors are still opening here, except the captains quarters, which requires Level 2 Security Access anyway. "
		"(Get to the escape pods with supplies to escape)\n";
	_isSealed = true;
	_kindOfSpace = CREW_QUARTERS;
	_spaceInventory = new Inventory(100);
	_lvl3ClearanceIsAdded = false;
	_spaceInventory->addItem(new Item(NOTE_TO_SELF));
}

/*********************************************************************
** Description: Give the player access the a level 3 clearance card
** automatically if they enter the room with level 2 access card
*********************************************************************/
void CrewQuarters::updateRoom(Inventory * playerInventoryIn, bool isLifesupportOn) {
	if (playerInventoryIn->checkForItem(LVL2_CLEARANCE) == true && _lvl3ClearanceIsAdded == false) {
		std::cout << "**Your Level 2 Clearance opens up the captain's quarters where you find her extra Level 3 Clearance card**" << std::endl;
		_spaceInventory->addItem(new Item(LVL3_CLEARANCE));
		_strSpaceInspect = "[Crew Quarters] You were very lucky to have your space suit on when the asteroid shower hit. It looks like everyone who survived here, "
			"suffocated shortly thereafter.The bodies of your crewmates are strewn about the cabin. Now that you have Level 2 Clearance, the Captain's "
			"Quarters are open to you.";
	}
}

