/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Item class header. Item is used for 
** creating different items to be used in the game. 
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
enum ItemKind {
	EXTRA_O2,
	RESEARCH_DATA,
	LVL2_CLEARANCE,
	LVL3_CLEARANCE,
	REPAIR_KIT, 
	FOOD,
	FIRE_EXTINGUISHER,
	CROBAR,
	EXPLOSIVES,
	DISTRESS_SIGNAL,
	NOTE_TO_SELF,
	LIFE_SUPPORT_KEY
};

class Item {
protected:
	std::string _itemName,
		_itemDescription;
	ItemKind _itemKindIs;
public:
	Item(ItemKind setKindTo);
	~Item();

	std::string getItemName();
	std::string getItemDesc();
	ItemKind getItemKind();
};
#endif