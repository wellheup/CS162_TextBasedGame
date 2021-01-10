/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Escape Pods struct header and Space 
** derived class
*********************************************************************/
#ifndef ESCAPEPODS_HPP
#define ESCAPEPODS_HPP

class EscapePods : public Space {
protected:
	bool _escapePodIsFixed;
public:

	EscapePods(Space* north, Space* east, Space* south, Space* west);
	~EscapePods();

	void initSpace() override;

	bool getIsFixed() override;
	void updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) override;
};
#endif