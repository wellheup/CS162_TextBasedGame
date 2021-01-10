/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements source code for the World class. World is 
** used for setting up the environment for the game
*********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <string>
#include "menuShell.hpp"
#include "World.hpp"
#include "Space.hpp"
#include "CrewQuarters.hpp"
#include "Bridge.hpp"
#include "CargoBay.hpp"
#include "Engines.hpp"
#include "EscapePods.hpp"
#include "Hydroponics.hpp"
#include "Laboratories.hpp"
#include "LifeSupport.hpp"
#include "OuterSpace.hpp"

World::World() { 
	populateWorld();
	connectWorld();
	_spaceDesc = "You're in space, you're losing oxygen quickly, but a lot of the air locks are intact, "
		"which room do you want to re-enter the ship through?";
}

World::~World() {
	for (unsigned int i = 0; i < _shipSpaces.size(); i++) {
		if (_shipSpaces[i] != nullptr) {
			delete _shipSpaces[i];
			_shipSpaces[i] = nullptr;
		}
	}
	if (_outerSpace) {
		delete _outerSpace;
		_outerSpace = nullptr;
	}
}

/*********************************************************************
** Description: allocates a pointerw to new space inherited objects
** into the _shipSpaces vector
*********************************************************************/
void World::populateWorld() {
	_shipSpaces.resize(8, nullptr);
	_outerSpace = new OuterSpace;

	_shipSpaces[BRIDGE] = new Bridge(_outerSpace, _outerSpace, _outerSpace, _outerSpace);//this will be the bridge
	_bridge = _shipSpaces[BRIDGE];
	
	_shipSpaces[CREW_QUARTERS] = new CrewQuarters(_outerSpace, _outerSpace, _outerSpace, _outerSpace);
	_crewQuarters = _shipSpaces[CREW_QUARTERS];

	_shipSpaces[CARGO_BAY] = new CargoBay(_outerSpace, _outerSpace, _outerSpace, _outerSpace);

	_shipSpaces[ESCAPE_PODS] = new EscapePods(_outerSpace, _outerSpace, _outerSpace, _outerSpace);
	_escapePods = _shipSpaces[ESCAPE_PODS];

	_shipSpaces[HYDROPONICS] = new Hydroponics(_outerSpace, _outerSpace, _outerSpace, _outerSpace);

	_shipSpaces[LABORATORIES] = new Laboratories(_outerSpace, _outerSpace, _outerSpace, _outerSpace);

	_shipSpaces[LIFE_SUPPORT] = new LifeSupport(_outerSpace, _outerSpace, _outerSpace, _outerSpace);
	_lifeSupport = _shipSpaces[LIFE_SUPPORT];

	_shipSpaces[ENGINES] = new Engines(_outerSpace, _outerSpace, _outerSpace, _outerSpace);//this will be the engine room
	_engines = _shipSpaces[ENGINES];
}

/*********************************************************************
** Description: manually sets up all of the pointers for each of the 
** different exits on each room in the world
*********************************************************************/
void World::connectWorld() {
	_shipSpaces[BRIDGE]->setCardinalDirections(_outerSpace, _outerSpace, _outerSpace, _shipSpaces[1]);

	_shipSpaces[CREW_QUARTERS]->setCardinalDirections(_shipSpaces[4], _shipSpaces[0], _outerSpace, _shipSpaces[2]);

	_shipSpaces[CARGO_BAY]->setCardinalDirections(_shipSpaces[5], _shipSpaces[1], _outerSpace, _shipSpaces[3]);
		
	_shipSpaces[ESCAPE_PODS]->setCardinalDirections(_shipSpaces[6], _shipSpaces[2], _outerSpace, _shipSpaces[7]);

	_shipSpaces[HYDROPONICS]->setCardinalDirections(_outerSpace, _shipSpaces[0], _shipSpaces[1], _shipSpaces[5]);

	_shipSpaces[LABORATORIES]->setCardinalDirections(_outerSpace, _shipSpaces[4], _shipSpaces[2], _shipSpaces[6]);

	_shipSpaces[LIFE_SUPPORT]->setCardinalDirections(_outerSpace, _shipSpaces[5], _shipSpaces[3], _shipSpaces[7]);

	_shipSpaces[ENGINES]->setCardinalDirections(_outerSpace, _shipSpaces[6], _outerSpace, _outerSpace);

	for (unsigned int i = 0; i < _shipSpaces.size(); i++) {
		_shipSpaces[i]->setExtraDirections();
		_shipSpaces[i]->setDoorStatus();
	}
}

Space* World::getCrewQuarters() {
	return this->_crewQuarters;
}

Space* World::getOuterSpace() {
	return this->_outerSpace;
}

bool World::getLifeSupportIsFixed() {
	return _lifeSupport->getIsFixed();
}

bool World::getEnginesIsFixed() {
	return _engines->getIsFixed();
}

bool World::getEscapePodsIsFixed() {
	return _escapePods->getIsFixed();
}

/*********************************************************************
** Description: manages the special circumstance of the player being 
** in an OuterSpace space
*********************************************************************/
Space* World::enterFromOuterSpace() {
	std::vector<std::string> chooseOptions;
	chooseOptions.push_back(_spaceDesc);
	for (unsigned int i = 0; i < _shipSpaces.size(); i++) {
		chooseOptions.push_back("\t"+ std::to_string(i+1)+". Enter " + _shipSpaces[i]->getSpaceName());
	}

	Space* tempSpace = this->getOuterSpace();
	unsigned int choice = 0;
	while (choice != chooseOptions.size() - 1) {
		choice = choiceMenuMulti(&chooseOptions);
		switch (choice) {
		case 1:
			tempSpace = _shipSpaces[0];
			choice = chooseOptions.size() - 1;
			break;
		case 2:
			tempSpace = _shipSpaces[1];
			choice = chooseOptions.size() - 1;
			break;
		case 3:
			tempSpace = _shipSpaces[2];
			choice = chooseOptions.size() - 1;
			break;
		case 4:
			tempSpace = _shipSpaces[3];
			choice = chooseOptions.size() - 1;
			break;
		case 5:
			tempSpace = _shipSpaces[4];
			choice = chooseOptions.size() - 1;
			break;
		case 6:
			tempSpace = _shipSpaces[5];
			choice = chooseOptions.size() - 1;
			break;
		case 7:
			tempSpace = _shipSpaces[6];
			choice = chooseOptions.size() - 1;
			break;
		case 8:
			tempSpace = _shipSpaces[7];
			choice = chooseOptions.size() - 1;
			break;
		default:
			std::cout << "Error in choosing options" << std::endl;
			break;
		}
	}
	return tempSpace;
}



