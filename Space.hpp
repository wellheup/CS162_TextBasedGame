/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Space struct header. 
** Space is used for creating each space in the game world. 
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
enum SpaceKind {
	BRIDGE,
	CREW_QUARTERS,
	CARGO_BAY,
	ESCAPE_PODS,
	HYDROPONICS,
	LABORATORIES,
	LIFE_SUPPORT,
	ENGINES,
	OUTER_SPACE,
	BASE_SPACE
};

class Inventory;

class Space {
protected:
	
public:
	Space *_ptrNorthSpace, 
		*_ptrEastSpace, 
		*_ptrSouthSpace, 
		*_ptrWestSpace;
	std::string _strSpaceDesc,
		_strSpaceInspect,
		_strSpaceName,
		_strNorthDoor,
		_strEastDoor,
		_strSouthDoor,
		_strWestDoor;
	Inventory * _spaceInventory;
	SpaceKind _kindOfSpace;
	bool _isSealed;

	Space();
	Space(Space* north, Space* east, Space* south, Space* west);
	virtual ~Space();

	//getters and setters	
	Space* getNorth();
	Space* getEast();
	Space* getSouth();
	Space* getWest();
	bool getIsSealed();
	virtual bool getIsFixed();
	void setNorth(Space* pointTo);
	void setEast(Space* pointTo);
	void setSouth(Space* pointTo);
	void setWest(Space* pointTo);

	virtual void initSpace() = 0;

	void setCardinalDirections(Space* north = nullptr, Space* east = nullptr, Space* south = nullptr, Space* west = nullptr);
	virtual void setExtraDirections();
	virtual Space* displaySpaceOptions(Inventory *playerInventory);
	virtual void displaySpaceParticulars(Inventory *playerInventoryIn);
	virtual void setDoorStatus();
	virtual void updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn);
	SpaceKind getSpaceKind();
	std::string getSpaceName();

};
#endif