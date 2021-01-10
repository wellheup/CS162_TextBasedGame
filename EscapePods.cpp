/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for EscapePods class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "EscapePods.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

EscapePods::EscapePods(Space* north, Space* east, Space* south, Space* west) {
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

EscapePods::~EscapePods() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
}

void EscapePods::initSpace() {
	_strSpaceName = "Escape Pods";
	_strSpaceDesc = "[Escape Pods] One escape pod remains in functional condition. However, the launch activation panel has seen better days, and its "
		"Distress Beacon is missing.";
	_strSpaceInspect = "[Escape Pods] Disaster struck at the worst possible time. Only one escape pod remains as its launch activation panel was "
		"damaged in the storm, but on top of that, all of the pods had their Distress Beacons removed for repairs and updates and "
		"are nowhere to be found. Not to mention that none of them were stocked for the extended wait you'll suffer in a deep space rescue "
		"(retrieve a Distress Beacon and a Repair Kit from the Cargo Bay)\n";
	_isSealed = false;
	_escapePodIsFixed = false;
	_kindOfSpace = ESCAPE_PODS;
	_spaceInventory = new Inventory(100);
}

bool EscapePods::getIsFixed() {
	return this->_escapePodIsFixed;
}

/*********************************************************************
** Description: If the player enters the room with a Distress Beacon
** and a repair kit, the escape pod will automatically be repaired
*********************************************************************/
void EscapePods::updateRoom(Inventory * playerInventoryIn, bool isLifesupportOn) {
	if (_escapePodIsFixed == false) {
		if (playerInventoryIn->checkForItem(REPAIR_KIT) == true && playerInventoryIn->checkForItem(DISTRESS_SIGNAL) == true) {
			std::cout << "**You fix the Escape Pod with your Repair Kit and the Spare Distres Beacon**" << std::endl;
			_escapePodIsFixed = true;
			_strSpaceInspect = "[Escape Pods] Disaster struck at the worst possible time. Only one escape pod remains, but thanks to you, it should "
				"be operational, however none of them were stocked for the extended wait you'll suffer in a deep space rescue."
				"(retrieve a Distress Beacon and a Repair Kit from the Cargo Bay)\n";
		}
	}
}

