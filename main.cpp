
/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/19/19
** Description: Creates a queue list and presents the user with
** several options for interaction
*********************************************************************/
#include <string>
#include <iostream>
#include "menuShell.hpp"
#include "Game.hpp"

int main() {
	std::vector<std::string> chooseOptions;
	chooseOptions.push_back("Welcome to Phillip Wellheuser's Final Project: Text-based Game");
	chooseOptions.push_back("\t1. Play the game");
	chooseOptions.push_back("\t2. Exit");

	unsigned int choice = 0;
	while (choice != chooseOptions.size() - 1) {
		choice = choiceMenuMulti(&chooseOptions);
		if (choice == 1) {
			Game myGame;
			myGame.runGame();
		}
		else if(choice ==2){
			std::cout << "Exiting program" << std::endl;
		}
		else {
			std::cout << "Error in choosing options" << std::endl;
		}
	}
	chooseOptions[0] = "\nWould you like to play again?";
	chooseOptions[1] = "\t1. Play again";

	return 0;
}