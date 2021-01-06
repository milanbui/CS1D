/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #7: Dictionary - Skip List
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 25 March 2019
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
/*******************************************************************************
 * FUNCTION printHeader
 * _____________________________________________________________________________
 *
 * This function returns a header including the lab name, lab number, the
 * programmer's name, the class name, and the section time as a string
 * _____________________________________________________________________________
 * PRE-CONDITIONS:
 *     labName - Name of the lab. The labName should be previously
 *               defined
 *     labNumber - Number of the lab. The labNumber should be
 *                 previously defined
 *
 * POST-CONDITIONS:
 *      returns header as string
 ******************************************************************************/
string printHeader(string labName,         //OUT - name of lab
		           int labNumber)          //OUT - the lab number
{
	// Declare variables
	ostringstream output; // OUT - output stream

	//  OUTPUT - Class Heading
	output << left;
	output << setw(75) << setfill('*') << "*";
	output << setfill(' ');
	output << "\n*	PROGRAMMED BY : " << "Milan Bui";
	output << "\n*	" << setw(14) << "CLASS" << ": " << "CS1D";
	output << "\n*	" << setw(14) << "SECTION" << ": "
		   << "MW: 2:30p - 4:50p";
	output << "\n*	ASSIGNMENT #" << setw(2) << labNumber << ": "
		   << labName;
	output << "\n";
	output << setw(75) << setfill('*') << "*";
	output << setfill(' ');
	output << "\n\n";
	output << right;
	//  OUTPUT - return class heading as string
	return output.str();

}
