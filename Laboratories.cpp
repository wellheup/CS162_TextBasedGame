/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for Labratories class header.
** Inherits from Space
*********************************************************************/
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Laboratories.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

Laboratories::Laboratories(Space* north, Space* east, Space* south, Space* west) {
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

Laboratories::~Laboratories() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
}

void Laboratories::initSpace() {
	_strSpaceName = "Laboratories";
	_strSpaceDesc = "[Laboratories] The Laboratories have a massive hole through them, but the computers are still intact. ";
	_strSpaceInspect = "[Laboratories] Your team has been off on an expedition to the distant reaches of explored space investigating new forms of plant "
		"life and how they might benefit humanity for several years and you've made many important discoveries. "
		"It is imperative that the research survives. The labs have taken the most damage and could not be sealed by emergency contingencies, "
		"so the doors have welded themselves shut, but the computers are, indeed, still intact. (enter through space to reach research data)\n";
	_isSealed = false;
	_kindOfSpace = LABORATORIES;
	_spaceInventory = new Inventory(100);
	_spaceInventory->addItem(new Item(RESEARCH_DATA));
	_spaceInventory->addItem(new Item(EXPLOSIVES));
}
