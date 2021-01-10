/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Engines struct header and Space 
** derived class
*********************************************************************/
#ifndef ENGINES_HPP
#define ENGINES_HPP

class Engines : public Space {
protected:
	Space *_ptrEast2Space;
	std::string	_strEast2Door;
	bool _enginesAreReset;
public:

	Engines(Space* north, Space* east, Space* south, Space* west);
	~Engines() override;

	void initSpace() override;

	//void setDoorStatus() override;
	void setExtraDirections() override;
	void setDoorStatus() override;
	Space* displaySpaceOptions(Inventory * playerInventoryIn) override;
	bool getIsFixed() override;
	void updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) override;
};
#endif