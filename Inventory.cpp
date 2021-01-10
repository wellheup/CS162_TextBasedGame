/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for Inventory class. Inventory 
**is used for creating inventory containers for the game. 
*********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "Item.hpp"
#include "Inventory.hpp"
#include "menuShell.hpp"

/*********************************************************************
** Description: Base constructor sets a size limit for each inventory
*********************************************************************/
Inventory::Inventory(int inventoryLimit) { 
	_inventoryLimit = inventoryLimit;
}

Inventory::~Inventory() {
	for (unsigned int i = 0; i < _inventoryContents.size(); i++) {
		if (_inventoryContents[i] != nullptr) {
			delete _inventoryContents[i];
			_inventoryContents[i] = nullptr;
		}	
	}
	_inventoryContents.clear();
}

/*********************************************************************
** Description: Displays the content of the inventory and allows movement
** of inventory items from this one to another one provided in a parameter
*********************************************************************/
void Inventory::displayInventory(Inventory* adjacentInventory) {
	if (_inventoryContents.size() == 0) {
		std::cout << "There's nothing worth looking at now...\n" << std::endl;
	}
	else {
		unsigned int choice = 0;
		while (choice != _inventoryContents.size() + 2) {
			std::cout << "\nYou find the following items; select an item to examine or elect to move items:" << std::endl;
			for (unsigned int i = 0; i < _inventoryContents.size(); i++) {
				std::cout << "\t" << std::to_string(i + 1) << ". "<< _inventoryContents[i]->getItemName() << std::endl;
			}
			std::cout << "\t" << std::to_string(_inventoryContents.size() + 1) << ". Move items" << std::endl;
			std::cout << "\t" << std::to_string(_inventoryContents.size() + 2) << ". Done Looking" << std::endl;
		
			choice = chooseIntInRange(1, _inventoryContents.size() + 2);
			if (choice >= 1 && choice <= _inventoryContents.size()) {
				std::cout << _inventoryContents[choice - 1]->getItemDesc() << std::endl;
			}
			else if (choice == _inventoryContents.size() + 1) {
				removeItem(adjacentInventory);//select items to pass to the adjacent inventory
			}
			else if (choice == _inventoryContents.size() + 2) {
				std::cout << "Back to business...\n" << std::endl;
			}
			else {
				std::cout << "Error while displaying inventory" << std::endl;
			}
		}
	}
}

/*********************************************************************
** Description: Adds items to the inventory if there is space
*********************************************************************/
bool Inventory::addItem(Item* addThis) {
	if (_inventoryContents.size() + 1 > _inventoryLimit) {
		std::cout << "No more room in inventory" << std::endl;
		return false;
	}
	else {
		_inventoryContents.push_back(addThis);
		return true;
	}
}

/*********************************************************************
** Description: Removes items from this object's inventory and places
** them into the inventory provided in the parameter
*********************************************************************/
void Inventory::removeItem(Inventory* adjacentInventory) {
	unsigned int choice = 0;
	while (choice != _inventoryContents.size() + 1) {
		std::cout << "What would you like to move?" << std::endl;
		for (unsigned int i = 0; i < _inventoryContents.size(); i++) {
			std::cout << "\t" << std::to_string(i + 1) << ". " << _inventoryContents[i]->getItemName() << std::endl;
		}
		std::cout << "\t" << std::to_string(_inventoryContents.size() + 1) << ". Done moving" << std::endl;
	
		choice = chooseIntInRange(1, _inventoryContents.size() + 1);
		if (choice >= 1 && choice <= _inventoryContents.size()) {
			if (adjacentInventory->addItem(_inventoryContents[choice - 1]) == true) {
				std::cout << "Moving " << _inventoryContents[choice - 1]->getItemName() << "..." << std::endl;
				_inventoryContents[choice - 1] = _inventoryContents.back();
				_inventoryContents.pop_back();//remove back 
			}
		}
		else if (choice == _inventoryContents.size() + 1) {
			std::cout << "Back to business...\n" << std::endl;
		}
		else {
			std::cout << "Error while dropping inventory" << std::endl;
		}
	}
}

/*********************************************************************
** Description: deletes a single instance of an item determined by the
** parameter passed as an ItemKind enum
*********************************************************************/
void Inventory::deleteItem(int deleteThis) {
	unsigned int i = 0;
	bool complete = false;
	while (i < _inventoryContents.size()&& complete == false) {
		if (_inventoryContents[i]->getItemKind() == deleteThis) {
			delete _inventoryContents[i];
			complete = true;
		}
		i++;
	}
}

/*********************************************************************
** Description: returns true if the item passed as an ItemKind enum
** in the parameter is present in the inventory
*********************************************************************/
bool Inventory::checkForItem(int lookForThis) {
	for (unsigned int i = 0; i < _inventoryContents.size(); i++) {
		if (_inventoryContents[i]->getItemKind() == lookForThis) {
			return true;
		}
	}
	return false;
}
