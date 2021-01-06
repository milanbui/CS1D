/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #6: Hashing
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 11 March 2019
 ******************************************************************************/
#ifndef QUADHASHMAP_H_
#define QUADHASHMAP_H_

#include <iostream>
#include <iomanip>
using namespace std;

struct Entry1
{
	int key;     // Key
	string city; // Value (city)
};

/*******************************************************************************
 * QuadHashMap Class
 * 	 This class represents a QuadHashMap object. It manages two attributes:
 * 	 num and array[].
 *******************************************************************************/
class QuadHashMap
{
public:
	/********************************
	 ** CONSTRUCTORS & DESTRUCTORS **
	 ********************************/
	QuadHashMap();
	~QuadHashMap();


	/**************
	 ** MUTATORS **
	 **************/
	void put(const int& k, const string& v);
	void erase(const int& k);

	/***************
	 ** ACCESSORS **
	 ***************/
	int size()const;
	bool empty()const;
	int find(const int& k)const;
	int quadraticHash(const int& k)const;
	void displayMap()const;
private:
	int num;          // Number of entries
	Entry array[31];  // Array of entries
};

/*******************************************************************************
 * QuadHashMap();
 * 	 Constructor; Initializes variables
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * ~QuadHashMap();
 * 	 Destructor;
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * size()const;
 * 	 Accessor; Gets the size of the map (how many entries)
 * 	 Parameters: none
 * 	 Return: num (number of entries)
 *******************************************************************************/

/*******************************************************************************
 * empty()const;
 * 	 Accessor; Checks if map is empty or not (if there are no entries)
 * 	 Parameters: none
 * 	 Return: true (if empty) or false (if not empty)
 *******************************************************************************/

/*******************************************************************************
 * find(const int& k)const;
 * 	 Accessor; Finds index (location) of entry with key k
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: index (location in array)
 *******************************************************************************/

/*******************************************************************************
 * put(const int& k, const string& v);
 * 	 Mutator; If key is found in map, changes the value; otherwise, inputs entry
 * 	          with key k and value v into an empty bucket
 * 	 Parameters: k (int)    // IN - entry key
 * 	             v (string) // IN - entry value
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * erase(const int& k);
 * 	 Mutator; Erases entry with key k from map
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * quadraticHash(const int& k);
 * 	 Mutator; Finds index (position in array) to input entry
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: index (location in array)
 *******************************************************************************/

/*******************************************************************************
 * displayMap()const;
 * 	 Accessor; Displays entries in map
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

#endif /* QUADHASHMAP_H_ */
