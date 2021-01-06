/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #7: Dictionary - Skip List
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 25 March 2019
 * SCORE        : 6/10
 ******************************************************************************/
#include"skipListClass.h"
#include"printHeader.h"
using namespace std;
/*******************************************************************************
 * DOUBLE HASHING AND QUADRATIC HASHING
 * _____________________________________________________________________________
 *
 * This program will create two map objects. One implements a map using double
 * hashing and the other uses quadratic hashing. Both are stored in arrays. The
 * program inserts entries with their keys and values (cities) and deletes
 * entries by their key. The program also displays the map after changes.
 * _____________________________________________________________________________
 * INPUT:
 *	    DoubleHashMap map1 - first map implemented with double hashing
 *	    QuadHashMap   map2 - second map implemented with quadratic hashing
 *
 * OUTPUT:
 *	    DoubleHashMap map1 - first map implemented with double hashing
 *	    QuadHashMap   map2 - second map implemented with quadratic hashing
 *
 ******************************************************************************/
int main()
{
	srand((unsigned)time(0));

	SkipList skipList(3, 0.5);
	int first;
	int last;

	cout << printHeader("Dictionary - Skip List", 7);

	cout << "THIS PROGRAM WILL:" << endl;
	cout << "1. Make a dictionary using a skip list. "
		 << endl;
	cout << "2. Test all dictionary methods (insert, size, empty, find, findAll,"
			"\n   erase(k), erase(p), begin, and end"<< endl;
	cout << "3. Display the dictionary after changes" << endl << endl << endl;

	cout << "DICTIONARY SIZE IS " << skipList.size() << endl << endl;

	if(skipList.empty())
	{
		cout << "DICTIONARY IS EMPTY" << endl << endl;
	}
	else
	{
		cout << "DICTIONARY IS NOT EMPTY" << endl << endl;
	}

	skipList.insert(18, "Laguna Niguel");
	skipList.insert(41, "Mission Viejo");
	skipList.insert(22, "San Clemente");
	skipList.insert(44, "Irvine");

	skipList.printSkipList();


	skipList.erase(41);
	skipList.erase(42);

	skipList.printSkipList();

	skipList.insert(58, "Lake Forest");
	skipList.insert(32, "San Diego");
	skipList.insert(49, "Anaheim");

	skipList.printSkipList();

	skipList.erase(58);

	skipList.printSkipList();

	skipList.insert(31, "Los Angeles");
	skipList.insert(17, "Orange");
	skipList.insert(72, "Palms Springs");
	skipList.insert(41, "Riverside");

	skipList.printSkipList();

	skipList.erase(72);

	skipList.printSkipList();

	skipList.insert(19, "Brea");
	skipList.insert(60, "Santa Ana");
	skipList.insert(35, "Tustin");
	skipList.insert(103, "Oceanside");
	skipList.insert(11, "La Jolla");
	skipList.insert(18, "Del Mar");
	skipList.insert(22, "Aliso Viejo");
	skipList.insert(49, "Laguna Beach");

	skipList.printSkipList();

	skipList.erase(41);

	skipList.printSkipList();

	skipList.insert(42, "Vista");
	skipList.insert(49, "San Diego");
	skipList.insert(99, "San Juan");
	skipList.insert(29, "Dana Point");
	skipList.insert(88, "El Segundo");
	skipList.insert(41, "San Clemente");
	skipList.insert(62, "Laguna Hills");

	skipList.printSkipList();

	cout << "DICTIONARY SIZE IS " << skipList.size() << endl << endl;

	if(skipList.empty())
	{
		cout << "DICTIONARY IS EMPTY" << endl << endl;
	}
	else
	{
		cout << "DICTIONARY IS NOT EMPTY" << endl << endl;
	}


	cout << "First item in the skip list is KEY: " << skipList.begin()->key
		 << " VALUE: " << skipList.begin()->value << endl << endl;

	skipList.findAll(11,first,last);

	cout << "Positions of all entries with KEY 11 are (P" << first << ", P"
		 << last << ")" << endl << endl;

	skipList.erase(skipList.find(42));

	skipList.printSkipList();

	skipList.find(100);

	return 0;
}
