/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Tran Nguyen
 * #
 * ASSIGNMENT #10A: DFS
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 17 April 2019
 ******************************************************************************/
#ifndef PRINTHEADER_H_
#define PRINTHEADER_H_


// PREPROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

//GLOABAL CONSTANTS

//TYPE DEFINITIONS AND ENUMERATED TYPES

// PROTOTYPES
/*******************************************************************************
 * FUNCTION PrintHeader
 * _____________________________________________________________________________
 *
 * This function returns a header including the lab name, lab number,
 * the programmer's name, the class name, and the section time
 * as a string
 *      returns header as string
 ******************************************************************************/
string printHeader(string name,    // IN - name of student(s)
                   string labName, // IN - assignment Name
                   char   type,    // IN - assignment type
                                   //    - (LAB or ASSIGNMENT)
                   int    labNum); // IN - assignment number



#endif /* PRINTHEADER_H_ */
