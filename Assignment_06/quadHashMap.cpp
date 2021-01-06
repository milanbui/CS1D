/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #6: Hashing
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 11 March 2019
 ******************************************************************************/
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
	Entry1 array[31];  // Array of entries
};

/*******************************************************************************
 * QuadHashMap();
 * 	 Constructor; Initializes variables
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
QuadHashMap::QuadHashMap()
{
	num = 0;

	for(int i = 0; i < 31; i++)
	{
		array[i].key = -1;
		array[i].city = "";
	}
}

/*******************************************************************************
 * ~QuadHashMap();
 * 	 Destructor;
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
QuadHashMap::~QuadHashMap()
{

}

/*******************************************************************************
 * size()const;
 * 	 Accessor; Gets the size of the map (how many entries)
 * 	 Parameters: none
 * 	 Return: num (number of entries)
 *******************************************************************************/
int QuadHashMap::size()const
{
	return num;
}

/*******************************************************************************
 * empty()const;
 * 	 Accessor; Checks if map is empty or not (if there are no entries)
 * 	 Parameters: none
 * 	 Return: true (if empty) or false (if not empty)
 *******************************************************************************/
bool QuadHashMap::empty()const
{
	return (num == 0);
}

/*******************************************************************************
 * put(const int& k, const string& v);
 * 	 Mutator; If key is found in map, changes the value; otherwise, inputs entry
 * 	          with key k and value v into an empty bucket
 * 	 Parameters: k (int)    // IN - entry key
 * 	             v (string) // IN - entry value
 * 	 Return: none
 *******************************************************************************/
void QuadHashMap::put(const int& k,    // IN - entry key
		              const string& v) // IN - entry value
{
	// DECLARE VARIABLES
	int position;    // PROC - position of where to put entry in array

	// PROC -- calculate position
	position = quadraticHash(k);

	cout << "Inputting entry with KEY " << k << " and VALUE " << v << endl;
	cout << endl << endl;

	// If position is empty
	if(array[position].key == -1)
	{
		array[position].key = k;
		array[position].city = v;

		num++;
	}
	// If position already has a value for that key
	else if(array[position].key == k)
	{
		array[position].city = v;
	}

}

/*******************************************************************************
 * find(const int& k)const;
 * 	 Accessor; Finds index (location) of entry with key k
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: index (location in array)
 *******************************************************************************/
int QuadHashMap::find(const int& k)const
{
	// DECLARE VARIABLES
	int first;  // PROC - hash value
	int index;  // PROC - position in array to put entry

	// PROC -- calculate hash value
	first = k % 31;

	index = first;

	// If key at the index matches key being found
	if((array[index].key == k))
	{
		return index;
	}
	else
	{
		int j = 1;
		while((j <= 31) && (array[index].key != k))
		{
			index = (first + j*j) % 31;

			j++;
		}

		return index;
	}
}

/*******************************************************************************
 * erase(const int& k);
 * 	 Mutator; Erases entry with key k from map
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: none
 *******************************************************************************/
void QuadHashMap::erase(const int& k)
{
	// DECLARE VARIABLES
	int position; // PROC - position of where to put entry in array

	// Finds position of entry with key k
	position = find(k);

	cout << "Deleting entry with key " << k << "..." << endl;
	cout << endl << endl;

	// If map is empty(there are no entries)
	if(empty())
	{
		cout << "Cannot erase from an empty array." << endl;
		cout << endl << endl;
	}
	// If position is empty
	else if(array[position].key == k)
	{
		array[position].key = -1;
		array[position].city = "";

		num--;
	}
	else
	{
		cout << "Key does not exist." << endl;
		cout << endl << endl;
	}

}


/*******************************************************************************
 * quadraticHash(const int& k);
 * 	 Mutator; Finds index (position in array) to input entry
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: index (location in array)
 *******************************************************************************/
int QuadHashMap::quadraticHash(const int& k)const
{
	// DECLARE VARIABLES
	int first;  // PROC - hash value
	int index;  // PROC - position in array to put entry

	// PROC -- calculate hash value
	first = k % 31;

	index = first;

	// If key at the index matches key being found
	if(array[index].key == -1)
	{
		return index;
	}
	else if(array[index].key == k)
	{
		return index;
	}
	else
	{
		int j = 1;
		while((j <= 31) && ((array[index].key != -1)&&(array[index].key != k)))
		{
			index = (first + j*j) % 31;

			j++;
		}

		return index;
	}

}

/*******************************************************************************
 * displayMap()const;
 * 	 Accessor; Displays entries in map
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void QuadHashMap::displayMap()const
{
	cout << left << setw(7) << "INDEX";
	cout << left << setw(5) << "KEY";
	cout << left << "CITY" << endl;

	cout << left << setw(28) << setfill('-') << "-" << endl;
	cout << setfill(' ');

	// OUTPUT -- displays the index, key, and value of each entry
	for(int i = 0; i < 31; i++)
	{
		if(array[i].key != -1)
		{
			cout << left << setw(7) << i;
			cout << left << setw(5) << array[i].key;
			cout << left << array[i].city << endl;
		}
	}
}
