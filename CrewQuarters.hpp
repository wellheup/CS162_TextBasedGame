/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the CrewQuarters struct header and Space 
** derived class
*********************************************************************/
#ifndef CREWQUARTERS_HPP
#define CREWQUARTERS_HPP

class CrewQuarters : public Space {
protected:
	bool _lvl3ClearanceIsAdded;
public:
	CrewQuarters(Space* north, Space* east, Space* south, Space* west);
	~CrewQuarters();

	void initSpace() override;

	void updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) override;
};
#endif