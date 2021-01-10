/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Specifies the World class header.  World is 
** used for setting up the environment for the game
*********************************************************************/
#ifndef WORLD_HPP
#define WORLD_HPP
class Space;

class World {
protected:
	std::vector<Space*> _shipSpaces;
	Space *_bridge, 
		*_engines,
		*_outerSpace,
		*_crewQuarters,
		*_lifeSupport,
		*_escapePods;
	std::string _spaceDesc;

public:
	World();
	~World();

	void populateWorld();
	void connectWorld();
	Space* getCrewQuarters();
	Space* getOuterSpace();
	bool getLifeSupportIsFixed();
	bool getEnginesIsFixed();
	bool getEscapePodsIsFixed();
	Space* enterFromOuterSpace();
};
#endif