/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for Item class. Item is used for 
** creating different items to be used in the game.
*********************************************************************/
#include <iostream>
#include "Item.hpp"

/*********************************************************************
** Description: creates an item with the specified strings based on the
** parameter ItemKind enum passed in
*********************************************************************/
Item::Item(ItemKind setKindTo) { 
	this->_itemKindIs = setKindTo;
	if (_itemKindIs==EXTRA_O2) {
		_itemName = "Extra O2 Cannister";
		_itemDescription = "\"Extra Oxygen for your space suit (about 3 steps worth).\"";
	}
	else if (_itemKindIs == RESEARCH_DATA) {
		_itemName = "Research Data";
		_itemDescription = "\"Your expedtion's valuable data, integral to the advancement of human kind (win condition).\"";
	}
	else if (_itemKindIs == LVL2_CLEARANCE) {
		_itemName = "Level 2 Clearance Card";
		_itemDescription = "\"Level 2 clearance will permit access to some locked doors.\"";
	}
	else if (_itemKindIs == LVL3_CLEARANCE) {
		_itemName = "Level 3 Clearance Card";
		_itemDescription = "\"Level 3 clearance will permit access to all locked doors and overrides except depressurized areas."
			"This must be the captain's extra card.\"";
	}
	else if (_itemKindIs == REPAIR_KIT) {
		_itemName = "Repair Kit";
		_itemDescription = "\"Standard repair kits have enough supplies to fix most things on the ship, most you'd know how to fix, at any rate (win condition)\"";
	}
	else if (_itemKindIs == FOOD) {
		_itemName = "Survival Rations";
		_itemDescription = "\"Survival rations should help you last longer in an escape pod while you wait for rescue, a necessity in deep space (win condition)\"";
	}
	else if (_itemKindIs == FIRE_EXTINGUISHER) {
		_itemName = "Fire Extinguisher";
		_itemDescription = "\"Extinguishes fires. Also good for hitting things in a pinch.\"";
	}
	else if (_itemKindIs == CROBAR) {
		_itemName = "Crobar";
		_itemDescription = "\"Good for prying open stuck things. Probably even better than a fire extinguisher for hitting things.\"";
	}
	else if (_itemKindIs == EXPLOSIVES) {
		_itemName = "Improvised Explosives";
		_itemDescription = "\"Homemade explosives. You're no demolitions expert, but you do know your chemistry. They might come in handy, should explode pretty well \"";
	}
	else if (_itemKindIs == DISTRESS_SIGNAL) {
		_itemName = "Distress Beacon";
		_itemDescription = "\"Calls for help so you don't have to; every castaway needs one (win condition).\"";
	}
	else if (_itemKindIs == NOTE_TO_SELF) {
		_itemName = "Note To Self";
		_itemDescription = "\"Reads: Escape pods are under routine tune-up. In the event of catastrophic failure make sure yours has the following:\n"
			"\t1) Backup Research Data (It's imperative that our efforts are not in vain)\n"
			"\t2) Survival Rations (We're in deep space, it'll take a bit for anyone to find us)\n"
			"\t3) Distress Beacon ('Why in God's name are they so easily broken?' Spares are in the Cargo Bay)\n"
			"\t4) Repair Kit (Escape Pods are made for escaping emergencies, not surviving emergencies on their own...)\"\n";
	}
	else {
		std::cout << "Error creating Item" << std::endl;
	}
}

Item::~Item() {

}

std::string Item::getItemName() {
	return this->_itemName;
}

std::string Item::getItemDesc() {
	return this->_itemDescription;
}

ItemKind Item::getItemKind() {
	return this->_itemKindIs;
}
