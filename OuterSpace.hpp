/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the Outer Space struct header. 
** Outer Space is derived from Space
*********************************************************************/
#ifndef OUTERSPACE_HPP
#define OUTERSPACE_HPP


class OuterSpace : public Space {
protected:

public:
	OuterSpace();
	~OuterSpace();

	void initSpace();

};
#endif