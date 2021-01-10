/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for Hydroponics class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Hydroponics.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

Hydroponics::Hydroponics(Space* north, Space* east, Space* south, Space* west) {
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

Hydroponics::~Hydroponics() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
}

void Hydroponics::initSpace() {
	_strSpaceName = "Hydroponics";
	_strSpaceDesc = "[Hydroponics] The ship's Hydroponics deck is where all of the food comes from. Most of the food plants are contained and intact, but "
		"there is an recurring fire hindering your traversal of the deck when life support is active.";
	_strSpaceInspect = "[Hydroponics] The Hydroponics systems have suffered minimal damage compared to the rest of the ship, "
		"but between the oxygen reserves collected from the plants and the special fertilizers used on them, "
		"large fires have broken out and the plants cannot be reached. Unfortunately you'll want some of those for your escape pod... "
		"(turn off Life Support or bring a Fire Extinguisher to put out fires)\n";
	_isSealed = true;
	_isFireExtinguished = false;
	_isFirePatched = false;
	_hasAddedFood = false;
	_kindOfSpace = HYDROPONICS;
	_spaceInventory = new Inventory(100);
}

/*********************************************************************
** Description: If the player is able to put out the fire in 
** Hydroponics by entering with a fire extinguisher or by not having 
** repaired Life Support yet, food will be made available to the 
** player. If the player has a repair kit, the damage will also be 
** repaired
*********************************************************************/
void Hydroponics::updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) {
	if (isLifesupportOn == true && _isFirePatched == false) {
		if (playerInventoryIn->checkForItem(FIRE_EXTINGUISHER) == true) {
			std::cout << "**The fire is temporarily quelled by the Fire Extinguisher**" << std::endl;
			_isFireExtinguished = true;
			_spaceInventory->addItem(new Item(FOOD));
			if (playerInventoryIn->checkForItem(REPAIR_KIT) == true) {
				std::cout << "**You patch the source of the fire with your Repair Kit**" << std::endl;
				_isFirePatched = true;
				_strSpaceInspect = "[Hydroponics] The Hydroponics systems have suffered minimal damage compared to the rest of the ship, "
					"but now that you've patched things up, it's not so bad in here.\n";
			}
		}
		else {
			_isFireExtinguished = false;
		}
	}
	else if (isLifesupportOn == false) {
		_isFireExtinguished = true;
		_spaceInventory->addItem(new Item(FOOD));
		_hasAddedFood = true;
		if (_isFirePatched == false && playerInventoryIn->checkForItem(REPAIR_KIT) == true) {
			std::cout << "**You patch the source of the fire with your Repair Kit**" << std::endl;
			_isFirePatched = true;
			_strSpaceDesc = "[Hydroponics] The ship's Hydroponics deck is where all of the food comes from. Most of the food plants are contained and intact, and "
				"now that the fires are out it seems quite tranquil in here";
			_strSpaceInspect = "[Hydroponics] The Hydroponics systems have suffered minimal damage compared to the rest of the ship, "
				"but now that you've patched things up, it's not so bad in here.\n";
		}
	}
	else if (_isFirePatched == true) {
		_isFireExtinguished = true;
		_spaceInventory->addItem(new Item(FOOD));
		_hasAddedFood = true;
	}
	else {
		std::cout << "Error: Unexpected state of fires" << std::endl;
	}

}
