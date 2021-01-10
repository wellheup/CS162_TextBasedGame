/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for LifeSupport class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "LifeSupport.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

LifeSupport::LifeSupport(Space* north, Space* east, Space* south, Space* west) {
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

LifeSupport::~LifeSupport() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
}

void LifeSupport::initSpace() {
	
	_strSpaceName = "LifeSupport";
	_strSpaceDesc = "[Life Support] The Life Support deck seems to be mostly unharmed, but its systems are not running. No air or gravity for you.";
	_strSpaceInspect = "[Life Support] All of the ship's artificial gravity and atmospheric needs are managed through the life support systems. "
		"Here, water and waste are also processed, but, as you'll soon be leaving, these are not of immediate concern. "
		"Unfortunately damage to the life support systems has caused a loss of atmosphere in all sealed cabins. "
		"If repaired, atmosphere will repressurize throughout sealed cabins and benefit you with just enough oxygen to "
		"make it a little further if your suit runs out. (repair to get extra steps and restored gravity in sealed cabins)\n";
	_isSealed = true;
	_isLifeSupportFixed = false;
	_kindOfSpace = LIFE_SUPPORT;
	_spaceInventory = new Inventory(100);
	_spaceInventory->addItem(new Item(EXTRA_O2));
}

bool LifeSupport::getIsFixed() {
	return this->_isLifeSupportFixed;
}

/*********************************************************************
** Description: If the player has a repair kit and life support is 
** not fixed yet, automatically fixes it when entering the room
*********************************************************************/
void LifeSupport::updateRoom(Inventory *playerInventoryIn, bool isLifesupportFixed) {
	if (_isLifeSupportFixed==false && playerInventoryIn->checkForItem(REPAIR_KIT) == true) {
		_isLifeSupportFixed = true;
		std::cout << "**You fix the Life Support with your Repair Kit**" << std::endl;	
		_strSpaceInspect = "[Life Support] All of the ship's artificial gravity and atmospheric needs are managed through the life support systems. "
			"Here, water and waste are also processed, but, as you'll soon be leaving, these are not of immediate concern. "
			"Now that you've repaired they systems, atmosphere will repressurize throughout sealed cabins and benefit you with just enough oxygen to "
			"make it a little further if your suit runs out. (repair to get extra steps and restored gravity in sealed cabins)\n";
	}	

}
