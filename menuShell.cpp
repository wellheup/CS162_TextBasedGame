/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Implements several functions useful for displaying
** menus with choice selection to users and utilizes input validation
** to make sure that the user's choices are valid selections for 
** the context of the menu.
*********************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "menuShell.hpp"
#include "isValidInput.hpp"

/*********************************************************************
** Description: initMenu() takes in a string for the name of a program
** and asks the player if they'd like to run that program. Y will
** return a 1 and N will return an 2
*********************************************************************/
int initMenu(std::string programName) {
	int attempts = 0;
	bool validEntry = false;
	std::string userIn;
	std::cout << "Would you like to run "<< programName<< "? (Y/N)" << std::endl;
	while (validEntry == false) {
		if (attempts ==1) {
			std::cout << "Please enter Y or N to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isYesNo(userIn)) {
			validEntry = true;
		}
		attempts++;
	}
	if (userIn == "Y" || userIn == "y") {
		return 1;
	}
	else if (userIn == "N" || userIn == "n") {
		return 2;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: initMenuSOrQ() uses the first parameter to prompt the 
** user then the second to define the first selection as opposed to 
** a "Quit" option and returns a 1 or a 2
*********************************************************************/
int initMenuSOrQ(std::string startPrompt, std::string text1) {
	int attempts = 0, userChoice = 0;
	bool validEntry = false;
	std::string userIn;

	std::cout << startPrompt << std::endl;
	std::cout << text1 << std::endl;
	std::cout << "2. Quit." << std::endl;

	while (validEntry == false) {
		if (attempts ==1) {
			std::cout << "Please enter 1, or 2 to select a choice." << std::endl;
		}
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, 1, 2)) {
				validEntry = true;
			}
			else {
				std::cout << "Please use one of the options provided." << std::endl;
			}
		}
		else {
			std::cout << "Please enter an integer value." << std::endl;
		}
		attempts++;
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*EXAMPLE IMPLEMENTATION**********************************************
std::vector<std::string> chooseOptions;
chooseOptions.push_back("Welcome to Phillip Wellheuser's Final Project: Text-based Game");
chooseOptions.push_back("\t1. Play the game");
chooseOptions.push_back("\t2. Exit");

int choice = 0;
while (choice != chooseOptions.size()-1) {
	choice = choiceMenuMulti(&chooseOptions);
	switch (choice) {
	case 1:
		runGame();
		break;
	case 2:
		std::cout << "Exiting program" << std::endl;
		break;
	default:
		std::cout << "Error in choosing options" << std::endl;
		break;
	}
}
*********************************************************************/
/*********************************************************************
** Description: choiceMenuMulti() expects an array of strings and the 
** length of that array. It prints out every element of the array and 
** returns a valid corresponding integer input from the user. The first
** entry in the array should be the prompt to the rest options.
*********************************************************************/
int choiceMenuMulti(std::vector<std::string> *stringVector) {
	int userChoice = 0;
	bool validEntry = false;
	std::string userIn;

	for (unsigned int i = 0; i < stringVector->size(); i++) {
		if (i == 0) {
			std::cout << stringVector->at(i) << std::endl;
		}
		else{
			std::cout << "   " << stringVector->at(i) << std::endl;
		}
	}
	while (validEntry == false) {
		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, 1, stringVector->size() - 1)) {
				validEntry = true;
			}
			else {
				std::cout << "Please use one of the options provided." << std::endl;
			}
		}
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: chooseIntInRange() prompts the user with the first
** parameter then compares user input to make sure it is an int
** between the low and high values provided (inclusive)
*********************************************************************/
int chooseIntInRange(std::string startPrompt, int low, int high) {
	std::cout << startPrompt << std::endl;
	int userChoice = 0;
	bool validEntry = false;
	std::string userIn;

	while (validEntry == false) {

		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, low, high)) {
				validEntry = true;
			}
			else {
				std::cout << "Please enter an integer between " << low << " and " << high << "." << std::endl;
			}
		}
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: chooseIntInRange() compares user input to make sure 
** it is an int between the low and high values provided (inclusive)
*********************************************************************/
int chooseIntInRange(int low, int high) {
	int userChoice = 0;
	bool validEntry = false;
	std::string userIn;
	
	while (validEntry == false) {

		std::getline(std::cin, userIn);
		if (isInt(userIn)) {
			if (isIntInRange(userIn, low, high)) {
				validEntry = true;
			}
			else {
				std::cout << "Please enter an integer between " << low << " and " << high << "." << std::endl;
			}
		}
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1;
	}
}

/*********************************************************************
** Description: chooseDoubleInRange() prompts the user with the first
** parameter then compares user input to make sure it is a double
** between the low and high values provided (inclusive)
*********************************************************************/
double chooseDoubleInRange(std::string startPrompt, double low, double high) {
	std::cout << startPrompt << std::endl;
	double userChoice = 0.0;
	bool validEntry = false;
	std::string userIn;

	while (validEntry == false) {
		std::getline(std::cin, userIn);
		if (isDouble(userIn)) {
			if (isDoubleInRange(userIn, low, high)) {
				validEntry = true;
			}
			else {
				std::cout << "Please enter a double between " << low << " and " << high << "." << std::endl;
			}
		}
	}

	if (validEntry) {
		userChoice = stoi(userIn);
		return userChoice;
	}
	else {
		std::cout << "Error w/ user input: " << userIn << std::endl;
		return -1.0;
	}
}

/*********************************************************************
** Description: enterStringWithinRange() prompts the user with the first
** parameter then compares user input to make sure it is a string
** of length between the low and high values provided
*********************************************************************/
std::string enterStringWithinRange(std::string startPrompt, int low, int high) {
	std::cout << startPrompt << std::endl;
	bool validEntry = false;
	std::string userIn;

	while (validEntry == false) {

		std::getline(std::cin, userIn);
		if (isStringWithinRange(userIn, low, high)) {
			validEntry = true;
		}
		else {
			std::cout << "Please enter a string between " << low << " and " << high << " characters long." << std::endl;
		}
	}
	return userIn;
}

/*********************************************************************
** Description: enterTxtFileWithinRange() prompts the user with the first
** parameter then compares user input to make sure it is a string
** of length between the low and high values provided and then makes 
** sure that it ends in .txt
*********************************************************************/
std::string enterTxtFileWithinRange(std::string startPrompt, int low, int high) {
	std::cout << startPrompt << std::endl;
	bool validEntry = false;
	std::string userIn;

	while (validEntry == false) {

		std::getline(std::cin, userIn);
		if (isStringWithinRange(userIn, low, high)) {
			if (isTxtFile(userIn)) {
				validEntry = true;
			}
			else {
				std::cout << "Please enter a .txt file." << std::endl;
			}
		}
		else {
			std::cout << "Please enter a string between " << low << " and " << high << " characters long." << std::endl;
		}
	}
	return userIn;
}