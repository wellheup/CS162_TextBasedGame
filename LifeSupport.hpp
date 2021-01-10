/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the LifeSupport struct header and Space 
** derived class
*********************************************************************/
#ifndef LIFESUPPORT_HPP
#define LIFESUPPORT_HPP

class LifeSupport : public Space {
protected:
	bool _isLifeSupportFixed;
public:
	LifeSupport(Space* north, Space* east, Space* south, Space* west);
	~LifeSupport();

	void initSpace() override;

	bool getIsFixed() override;
	void updateRoom(Inventory *playerInventoryIn, bool isLifesupportFixed) override;
};
#endif