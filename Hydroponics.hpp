/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Hyrdoponics struct header and Space 
** derived class
*********************************************************************/
#ifndef HYDROPONICS_HPP
#define HYDROPONICS_HPP

class Hydroponics : public Space {
protected:
	bool _isFireExtinguished,
		_isFirePatched,
		_hasAddedFood;
public:

	Hydroponics(Space* north, Space* east, Space* south, Space* west);
	~Hydroponics();

	void initSpace() override;

	void updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) override;
};
#endif