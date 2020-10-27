/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #2: Stacks, Queues, and Deques
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 4 February 2019
 ******************************************************************************/
#include <iostream>
#include "stackClass.h"
using namespace std;

/******************************************************************************
 * FUNCTION checkPair
 * ____________________________________________________________________________
 *
 * This function checks if the opening and closing statements match and returns
 * true if they do and false if they don't
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *     opening - opening statement
 *     closing - closing statement
 *
 *
 * POST-CONDITIONS:
 *      returns true or false
 ******************************************************************************/
bool checkPair(char opening, char closing)
{
	// If the statements match, return true
	if((opening == '{') && (closing == '}'))
	{
		return true;
	}
	else if((opening == '[') && (closing == ']'))
	{
		return true;
	}
	else if((opening == '(') && (closing == ')'))
	{
		return true;
	}

	// return false if they don't match
	return false;
}


/******************************************************************************
 * FUNCTION parenMatch
 * ____________________________________________________________________________
 *
 * This function checks if the opening and closing statements in a string
 * match and returns true if they do and false if they don't
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *     statement - a string of a mathematical statement
 *
 * POST-CONDITIONS:
 *      returns true or false
 ******************************************************************************/
bool parenMatch(string statement)
{
	// Declare variables
	Stack<char> parenthesesAlg; // PROC - a stack to hold the parentheses
	int length;                 // PROC - length of statement

	// PROC - sets length to the length f the satement
	length = statement.length();

	// For all characters in the the statements
	for(int i = 0; i < length; i++)
	{
		// If character is an opening statement, add to stack
		if((statement[i] == '{') || (statement[i] == '[') || (statement[i] == '('))
		{
			parenthesesAlg.push(statement[i]);
		}
		// If character is closing statement
		else if((statement[i] == '}') || (statement[i] == ']') || (statement[i] == ')'))
		{
			// If doesn't have a matching opening statement, return false
			if(parenthesesAlg.isEmpty() || !checkPair(parenthesesAlg.peek(),statement[i]))
			{
				return false;
			}
			else
			{
				// If has a matching opening statement, pop opening statement from stack
				parenthesesAlg.pop();
			}
		}
	}

	// If stack is empty in end return true
	if(parenthesesAlg.isEmpty())
	{
		return true;
	}
	else
	{
		// If stack not empty (means no matching statement found) return false
		return false;
	}
}

