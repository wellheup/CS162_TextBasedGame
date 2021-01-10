/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Inventory class header. Inventory is used for 
** creating inventory containers for the game. 
*********************************************************************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <vector>
class Item;

class Inventory {
private:
	std::vector<Item*> _inventoryContents;
	unsigned int _inventoryLimit;

public:
	Inventory(int inventoryLimit);
	~Inventory();

	void displayInventory(Inventory* spaceInventory);
	bool addItem(Item* addThis);
	void removeItem(Inventory* spaceInventory);
	void deleteItem(int deleteThis);
	bool checkForItem(int lookForThis);

};
#endif