/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the CargoBay struct header and Space 
** derived class
*********************************************************************/
#ifndef CARGOBAY_HPP
#define CARGOBAY_HPP

class CargoBay : public Space {
protected:
	bool _cargoHasBeenAccessed;
public:

	CargoBay(Space* north, Space* east, Space* south, Space* west);
	~CargoBay();

	void initSpace() override;

	void updateRoom(Inventory *playerInventoryIn, bool isLifesupportOn) override;
};
#endif