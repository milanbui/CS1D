/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen & Riley Bradt
 * #
 * ASSIGNMENT #11 : BFS & DFS Directed Edges
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 22 April 2019
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

/*******************************************************************************
 * FUNCTION PrintHeader
 * _____________________________________________________________________________
 *
 * This function returns a header including the lab name, lab number,
 * the programmer's name, the class name, and the section time
 * as a string
 * _____________________________________________________________________________
 * PRE-CONDITIONS:
 *     	  name  :  name of student(s)
 *     	  asName:  Assignment Name
 * 	   	  asType:  Assignment Type
 * 	   	  asNum :  Assignment Number
 *
 * POST-CONDITIONS:
 *      returns header as string
 ******************************************************************************/
string printHeader(string name,    // IN - name of student(s)
                   string labName, // IN - assignment Name
                   char   type,    // IN - assignment type
                                   //    - (LAB or ASSIGNMENT)
                   int    labNum)  // IN - assignment number
{
    ostringstream outStr; // OUT -  the header output

    outStr  << left << setw(125) << setfill('*')
    		<< "*" << endl << setfill (' ')
			<< "*  PROGRAMMED BY  : "  << "Milan Bui & " << name << endl
			<< "*  "       << setw(15) << "CLASS"  << ": CS1D"    << endl
			<< "*  "       << setw(15) << "SECTION"<< ": MW 2:30 - 4:50\n"
			<< "*  ";


    // PROCESSING - This will adjust setws and format appropriately
    //                based on if this is a lab 'L' or assignment

    if (toupper(type) == 'L')
    {
        outStr << "LAB #" << setw(10);
    }
    else
    {
        outStr << "ASSIGNMENT #" << setw(3);
    }

    outStr << labNum << ": " << labName << endl
    	   << left << setw(125) << setfill('*')
   		   << "*" << endl << endl << setfill (' ')
		   << right;

    return outStr.str();
}
