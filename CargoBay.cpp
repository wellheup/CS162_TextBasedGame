/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for CargoBay class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "CargoBay.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

CargoBay::CargoBay(Space* north, Space* east, Space* south, Space* west) {
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

CargoBay::~CargoBay() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
}

void CargoBay::initSpace() {
	_strSpaceName = "Cargo Bay";
	_strSpaceDesc = "[Cargo Bay] The Cargo Bay is a mess, and clearly damaged, but it seems that major leaks have been sealed by emergency contingencies "
		"and loose debris well enough to sustain life support.";
	_strSpaceInspect = "[Cargo Bay] The Cargo Bay should have most things you need for escaping. Unfortunately, due to the damages, everything you "
		"might need has come out of its containers and is very difficult to reach. (Turn off life support to access items stored here)\n";
	_isSealed = true;
	_cargoHasBeenAccessed = false;
	_kindOfSpace = CARGO_BAY;
	_spaceInventory = new Inventory(100);
}

/*********************************************************************
** Description: adds several items to the room for the player to pick 
** up if life support has been fixed
*********************************************************************/
void CargoBay::updateRoom(Inventory * playerInventoryIn, bool isLifesupportOn) {
	if (isLifesupportOn == true && _cargoHasBeenAccessed == false) {
		std::cout << "**Now that Life Support is working, it's easy to find some things that might be helpful in your escape**" << std::endl; 
		_spaceInventory->addItem(new Item(REPAIR_KIT));
		_spaceInventory->addItem(new Item(CROBAR));
		_spaceInventory->addItem(new Item(FIRE_EXTINGUISHER));
		_spaceInventory->addItem(new Item(DISTRESS_SIGNAL));
		_cargoHasBeenAccessed = true;
		_strSpaceInspect = "[Cargo Bay] The Cargo Bay should have most things you need for escaping. Unfortunately, due to the damages, everything you "
			"might need has come out of its containers but at least it's not floating now that Life Support is back on.\n";
	}
}
