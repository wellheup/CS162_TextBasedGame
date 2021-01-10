/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Labratories struct header and Space 
** derived class
*********************************************************************/
#ifndef LABORATORIES_HPP
#define LABORATORIES_HPP

class Laboratories : public Space {
protected:

public:

	Laboratories(Space* north, Space* east, Space* south, Space* west);
	~Laboratories();

	void initSpace() override;

};
#endif