/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Bridge struct header and Space 
** derived class
*********************************************************************/
#ifndef BRIDGE_HPP
#define BRIDGE_HPP

class Bridge : public Space {
protected:
	Space* _ptrWest2Space;
	std::string	_strWest2Door;
public:

	Bridge(Space* north, Space* east, Space* south, Space* west);
	~Bridge() override;

	void initSpace() override;

	void setExtraDirections() override;
	void setDoorStatus() override;
	Space* displaySpaceOptions(Inventory * playerInventoryIn) override;
	void updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) override;
};
#endif