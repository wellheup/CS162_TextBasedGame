/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/19/19
** Description: Implements source code for Outer Space class header. 
** Outer Space is derived from Space
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Space.hpp"
#include "OuterSpace.hpp"
#include "menuShell.hpp"
#include "Item.hpp"
#include "Inventory.hpp"

OuterSpace::OuterSpace() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
	initSpace();
}

OuterSpace::~OuterSpace() {
	this->_ptrNorthSpace = nullptr;
	this->_ptrEastSpace = nullptr;
	this->_ptrSouthSpace = nullptr;
	this->_ptrWestSpace = nullptr;
}

void OuterSpace::initSpace() {
	_strSpaceName = "Outer Space";
	_strSpaceDesc = "Outer Space should never display its description";
	_kindOfSpace = OUTER_SPACE;
	_isSealed = false;
	_spaceInventory = new Inventory(100);
}
