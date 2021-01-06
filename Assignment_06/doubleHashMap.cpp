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

struct Entry
{
	int key;     // Key
	string city; // Value (city)
};

/*******************************************************************************
 * DoubleHashMap Class
 * 	 This class represents a DoubleHashMap object. It manages two attributes:
 * 	 num and array[].
 *******************************************************************************/
class DoubleHashMap
{
public:
	/********************************
	 ** CONSTRUCTORS & DESTRUCTORS **
	 ********************************/
	DoubleHashMap();
	~DoubleHashMap();


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
	int doubleHash(const int& k)const;
	void displayMap()const;
private:
	int num;          // Number of entries
	Entry array[31];  // Array of entries
};

/*******************************************************************************
 * DoubleHashMap();
 * 	 Constructor; Initializes variables
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
DoubleHashMap::DoubleHashMap()
{
	num = 0;

	for(int i = 0; i < 31; i++)
	{
		array[i].key = -1;
		array[i].city = "";
	}
}

/*******************************************************************************
 * ~DoubleHashMap();
 * 	 Destructor;
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
DoubleHashMap::~DoubleHashMap()
{

}

/*******************************************************************************
 * size()const;
 * 	 Accessor; Gets the size of the map (how many entries)
 * 	 Parameters: none
 * 	 Return: num (number of entries)
 *******************************************************************************/
int DoubleHashMap::size()const
{
	return num;
}

/*******************************************************************************
 * empty()const;
 * 	 Accessor; Checks if map is empty or not (if there are no entries)
 * 	 Parameters: none
 * 	 Return: true (if empty) or false (if not empty)
 *******************************************************************************/
bool DoubleHashMap::empty()const
{
	return (num == 0);
}

/*******************************************************************************
 * find(const int& k)const;
 * 	 Accessor; Finds index (location) of entry with key k
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: index (location in array)
 *******************************************************************************/
int DoubleHashMap::find(const int& k)const // IN - entry key
{
	// Declare variables
	int first;  // PROC - result of hash function
	int second; // PROC - result of prime hash function
	int index;  // PROC - hash value (index where entry with key k is found)

	// PROC -- performs first hash function
	first = k % 31;
	second = 17 - (k % 17);

	index = first;

	// If key is found at this index
	if((array[index].key == k))
	{
		return index;
	}
	// If key is not at that index
	else
	{
		// Loop control variable
		int j = 0;

		// While counter is less than the max map size and key not found
		while((j < 31) && (array[index].key != k))
		{
			index = (first + j*second) % 31;

			j++;
		}

		return index;
	}
}

/*******************************************************************************
 * put(const int& k, const string& v);
 * 	 Mutator; If key is found in map, changes the value; otherwise, inputs entry
 * 	          with key k and value v into an empty bucket
 * 	 Parameters: k (int)    // IN - entry key
 * 	             v (string) // IN - entry value
 * 	 Return: none
 *******************************************************************************/
void DoubleHashMap::put(const int& k,    // IN - entry key
		                const string& v) // IN - entry value
{
	// DECLARE VARIABLES
	int position;  // PROC - index (location in array) to put entry

	// PROCESSING -- finding index
	position = doubleHash(k);

	cout << "Inputting entry with KEY " << k << " and VALUE " << v << endl;
	cout << endl << endl;

	// If bucket is empty
	if(array[position].key == -1)
	{
		array[position].key = k;
		array[position].city = v;

		num++;
	}
	// If bucket contains element with that key
	else
	{
		array[position].city = v;
	}
}

/*******************************************************************************
 * erase(const int& k);
 * 	 Mutator; Erases entry with key k from map
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: none
 *******************************************************************************/
void DoubleHashMap::erase(const int& k) // IN - entry key
{
	// DECLARE VARIABLES
	int position;  // PROC - index (location in array) to put entry

	// PROC -- finds position of entry with key k
	position = find(k);

	cout << "Deleting entry with key " << k << "..." << endl;
	cout << endl << endl;

	// If map is empty
	if(empty())
	{
		cout << "Cannot erase from an empty array." << endl;
		cout << endl << endl;
	}
	// If key at found index matches key of entry to be deleted
	else if(array[position].key == k)
	{
		array[position].key = -1;
		array[position].city = "";

		num--;
	}
	// If key was not found
	else
	{
		cout << "Key " << k << " does not exist." << endl;
		cout << endl << endl;
	}

}

/*******************************************************************************
 * doubleHash(const int& k);
 * 	 Mutator; Finds index (position in array) to input entry
 * 	 Parameters: k (int) // IN - entry key
 * 	 Return: index (location in array)
 *******************************************************************************/
int DoubleHashMap::doubleHash(const int& k)const // IN - entry key
{
	// DELCARING VARIABLES
	int first;  // PROC - result of first hash function
	int second; // PROC - result of second hash function
	int index;  // PROC - index of where to put entry

	// PROCESSING -- calculating hash values
	first = k % 31;
	second = 17 - (k % 17);

	index = first;

	// If hash value (index) bucket is empty or if the key at that index matches
	// key being input
	if((array[index].key == k) || (array[index].key == -1))
	{
		return index;
	}
	// If bucket is not empty and key doesnt match key being added (find available
	// location)
	else
	{
		int j = 0;
		while((j < 31) && ((array[index].key != -1)&&(array[index].key != k)))
		{
			index = (first + j*second) % 31;

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
void DoubleHashMap::displayMap()const
{
	cout << left << setw(7) << "INDEX";
	cout << left << setw(5) << "KEY";
	cout << left << "CITY" << endl;

	cout << left << setw(28) << setfill('-') << "-" << endl;
	cout << setfill(' ');

	// OUTPUT -- outputs index, key, and value of entries
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
