/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 6/12/19
** Description: Prototypes several functions useful for displaying
** menus with choice selection to users and utilizes input validation
** to make sure that the user's choices are valid selections for 
** the context of the menu.
*********************************************************************/
#ifndef MENUSHELL_HPP
#define MENUSHELL_HPP
#include <vector>

/*********************************************************************
** Description: initMenu() takes in a string for the name of a program
** and asks the player if they'd like to run that program. Y will
** return a 1 and N will return an 2
*********************************************************************/
int initMenu(std::string programName);

/*********************************************************************
** Description: initMenuSOrQ() uses the first parameter to prompt the
** user then the second to define the first selection as opposed to
** a "Quit" option and returns a 1 or a 2
*********************************************************************/
int initMenuSOrQ(std::string startPrompt, std::string text1);

/*********************************************************************
** Description: choiceMenuMulti() expects an array of strings and the
** length of that array. It prints out every element of the array and
** returns a valid corresponding integer input from the user. The first
** entry in the array should be the prompt to the rest options.
*********************************************************************/
int choiceMenuMulti(std::vector<std::string> *stringVector);

/*********************************************************************
** Description: chooseIntInRange() compares user input to make sure
** it is an int between the low and high values provided (inclusive)
*********************************************************************/
int chooseIntInRange(int low, int high);

/*********************************************************************
** Description: chooseIntInRange() prompts the user with the first
** parameter then compares user input to make sure it is an int
** between the low and high values provided
*********************************************************************/
int chooseIntInRange(std::string startPrompt, int low, int high);

/*********************************************************************
** Description: chooseIntInRange() prompts the user with the first
** parameter then compares user input to make sure it is an int
** between the low and high values provided
*********************************************************************/
double chooseDoubleInRange(std::string startPrompt, double low, double high);

/*********************************************************************
** Description: enterStringWithinRange() prompts the user with the first
** parameter then compares user input to make sure it is a string
** of length between the low and high values provided
*********************************************************************/
std::string enterStringWithinRange(std::string startPrompt, int low, int high);

/*********************************************************************
** Description: enterTxtFileWithinRange() prompts the user with the first
** parameter then compares user input to make sure it is a string
** of length between the low and high values provided and then makes
** sure that it ends in .txt
*********************************************************************/
std::string enterTxtFileWithinRange(std::string startPrompt, int low, int high);

//std::string chooseTextFileName();

#endif