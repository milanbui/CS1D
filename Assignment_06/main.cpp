/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #6: Hashing
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 11 March 2019
 * SCORE        : 6/10
 ******************************************************************************/
#include "doubleHashMap.h"
#include "quadHashMap.h"
#include "printHeader.h"
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
	// DECLARE VARIABLES
	DoubleHashMap map1;// IN/OUT - first map implemented with double hashing
	QuadHashMap   map2;// IN/OUT - second map implemented with quadratic hashing

	// OUTPUT -- outputs class header and program description
	cout << printHeader("Hashing", 6);

	cout << "THIS PROGRAM WILL:" << endl;
	cout << "1. Create two map objects. One implemented with double hashing and"
			"\n   the other implemented with quadratic hashing using an array"
		 << endl;
	cout << "2. Insert values and keys into the maps"<< endl;
	cout << "3. Delete entries by key" << endl;
	cout << "4. Display the map after each change" << endl << endl << endl;

    /***************************************************************************
     *
     * DOUBLE HASHING IMPLEMENTATION
     *
     **************************************************************************/

	cout << left << setw(75) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');
	cout << "PART 1 - DOUBLE HASHING" << endl;
	cout << "         DATA STRUCTURE - ARRAY" << endl << endl;
	cout << left << setw(75) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');

	// INPUT -- inserts entries
	map1.put(18,"Laguna Niguel");
	map1.put(41,"Mission Viejo");
	map1.put(22,"San Clemente");
	map1.put(44,"Irvine");

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 41 from map
	map1.erase(41);

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map1.put(58,"Lake Forest");
	map1.put(32,"San Diego");
	map1.put(49,"Anaheim");

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 58 from map
	map1.erase(58);

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map1.put(31,"Los Angeles");
	map1.put(17,"Orange");
	map1.put(72,"Palms Spring");
	map1.put(41,"Riverside");

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 72 from map
	map1.erase(72);

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map1.put(19,"Brea");
	map1.put(60,"Santa Ana");
	map1.put(35,"Tustin");
	map1.put(103,"Oceanside");
	map1.put(11,"La Jolla");
	map1.put(18,"Del Mar");
	map1.put(22,"Aliso Viejo");
	map1.put(49,"Laguna Beach");

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 41 from map
	map1.erase(41);

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map1.put(42,"Vista");
	map1.put(49,"San Diego");
	map1.put(99,"San Juan");
	map1.put(29,"Dana Point");
	map1.put(88,"El Segundo");
	map1.put(41,"San Clemente");
	map1.put(62,"Laguna Hills");

	// OUTPUT -- displays map
	map1.displayMap();
	cout << endl << endl;




    /***************************************************************************
     *
     * QUADRATIC HASHING IMPLEMENTATION
     *
     **************************************************************************/

	cout << left << setw(75) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');
	cout << "PART 1 - QUADRATIC HASHING" << endl;
	cout << "         DATA STRUCTURE - ARRAY" << endl << endl;
	cout << left << setw(75) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');

	// INPUT -- inserts entries
	map2.put(18,"Laguna Niguel");
	map2.put(41,"Mission Viejo");
	map2.put(22,"San Clemente");
	map2.put(44,"Irvine");

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 41 from map
	map2.erase(41);

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map2.put(58,"Lake Forest");
	map2.put(32,"San Diego");
	map2.put(49,"Anaheim");

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 58 from map
	map2.erase(58);

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map2.put(31,"Los Angeles");
	map2.put(17,"Orange");
	map2.put(72,"Palms Spring");
	map2.put(41,"Riverside");

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 72 from map
	map2.erase(72);

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map2.put(19,"Brea");
	map2.put(60,"Santa Ana");
	map2.put(35,"Tustin");
	map2.put(103,"Oceanside");
	map2.put(11,"La Jolla");
	map2.put(18,"Del Mar");
	map2.put(22,"Aliso Viejo");
	map2.put(49,"Laguna Beach");

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// PROCESSING -- deletes entry with key 41 from map
	map2.erase(41);

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	// INPUT -- inserts entries
	map2.put(42,"Vista");
	map2.put(49,"San Diego");
	map2.put(99,"San Juan");
	map2.put(29,"Dana Point");
	map2.put(88,"El Segundo");
	map2.put(41,"San Clemente");
	map2.put(62,"Laguna Hills");

	// OUTPUT -- displays map
	map2.displayMap();
	cout << endl << endl;

	return 0;
}

