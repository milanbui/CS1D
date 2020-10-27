/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #2: Stacks, Queues, and Deques
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 4 February 2019
 ******************************************************************************/
#ifndef FUNCTION_H_
#define FUNCTION_H_

// PREPROCESSING DIRECSTIVES
#include <iostream>
#include "stackClass.h"
using namespace std;

//GLOABAL CONSTANTS

//TYPE DEFINITIONS AND ENUMERATED TYPES

// PROTOTYPES
/******************************************************************************
 * FUNCTION checkPair
 * This function checks if the opening and closing statements match and returns
 * true if they do and false if they don't
 *      returns true or false
 ******************************************************************************/
bool checkPair(char opening, char closing);

/******************************************************************************
 * FUNCTION parenMatch
 * This function checks if the opening and closing statements in a string
 * match and returns true if they do and false if they don't
 *      returns true or false
 ******************************************************************************/
bool parenMatch(string statement);


#endif /* FUNCTION_H_ */
