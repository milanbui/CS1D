/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #7: Dictionary - Skip List
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 25 March 2019
 ******************************************************************************/
#ifndef SKIPLISTCLASS_H_
#define SKIPLISTCLASS_H_


#include<iostream>
#include<iomanip>
#include<sstream>
#include<time.h>
#include"skipListNodeClass.h"
using namespace std;

/*******************************************************************************
 * SkipList Class
 * 	 This class represents a SkipList object. It manages six attributes:
 * 	 p, level, position, maxLevel, _size, header.
 *******************************************************************************/
class SkipList
{
public:
	/*****************
	 ** CONSTRUCTOR **
	 *****************/
	SkipList(int maxLvl, float _p);

	/**************
	 ** MUTATORS **
	 **************/
	SkipListNode* createNode(int _key, string _value, int level, int _pos);
	void insert(int _key, string _value);
	void erase(int _key);
	void erase(SkipListNode* position);

	/***************
	 ** ACCESSORS **
	 ***************/
	int randomLevel()const;
	bool isFound(int _key, SkipListNode*& _pos)const;
	SkipListNode* find(int _key)const;
	void findAll(int _key, int& posFirst, int& posLast)const;
	const SkipListNode* begin();
	SkipListNode* end()const;
	int size()const;
	bool empty()const;
	void printSkipList()const;
private:
	float p;              // P is the fraction of the nodes with level i
	                      // pointers also having level i+1 pointers
	int level;            // Current level of skip list
	int position;         // Position of entry
	int maxLevel;         // Max level for the skip list
	int _size;            // Size of skip list (num of entries)
	SkipListNode* header; // Pointer to header node
};

/*******************************************************************************
 * SkipList(int maxLvl, float _p);
 * 	 Constructor; Initializes variables
 * 	 Parameters: maxLvl (int) - max level of skip list
 * 	             _p (float)   - P is the fraction of the nodes with level i
	                            pointers also having level i+1 pointers
 * 	 Return: none
 *******************************************************************************/
SkipList::SkipList(int maxLvl, // IN - max level of skip list
		           float _p)   // IN - P is the fraction of the nodes with level i
                               //      pointers also having level i+1 pointers
{
	this->maxLevel = maxLvl;
	this->p = _p;
	level = 0;
	_size = 0;
	position = 0;

    // Creates header node and initialize key to -1
	header = new SkipListNode(-1, maxLvl, 0);
}

/*******************************************************************************
 * randomLevel()const;
 * 	 Accessor; Creates/gets random level for node
 * 	 Parameters: none
 * 	 Return: lvl (int) - level for node
 *******************************************************************************/
int SkipList::randomLevel()const
{
	// Declare variables
	float r = (float)rand()/RAND_MAX; // CALC - random number
	int lvl = 0;                      // CAlC - level for node

	while(r < p && lvl < maxLevel)
	{
		lvl++;
		r = (float)rand()/RAND_MAX;
	}

	return lvl;
}

/*******************************************************************************
 * createNode(int _key, string _value, int level, int _pos);
 * 	 Mutator; Creates node for skip list
 * 	 Parameters: _key   (int)    // IN - key of entry   (node)
 * 	             _value (string) // IN - value of entry (node)
 * 	             level  (int)    // IN - level of node
 * 	             _pos   (int)    // IN - position of node
 * 	 Return: n (SkipListNode) - node for skip list
 *******************************************************************************/
SkipListNode* SkipList::createNode(int _key,      // IN - key of entry   (node)
		                           string _value, // IN - value of entry (node)
								   int level,     // IN - level of node
								   int _pos)      // IN - position of node
{
	SkipListNode* n = new SkipListNode(_key, _value, level, _pos);
	return n;
}

/*******************************************************************************
 * insert(int _key, string _value);
 * 	 Mutator; Inserts node in skip list
 * 	 Parameters: _key   (int)    // IN - key of entry   (node)
 * 	             _value (string) // IN - value of entry (node)
 * 	 Return: none
 *******************************************************************************/
void SkipList::insert(int _key,      // IN - key of entry   (node)
		              string _value) // IN - value of entry (node)
{
	// Tracks current position
	SkipListNode *current = header;

	// Create update array and initializes update array
	SkipListNode *update[maxLevel+1];
	memset(update, 0, sizeof(SkipListNode*)*(maxLevel+1));

	// PROCESSING --
	// Starts from the highest level of the skip list and moves the current
	// pointer forwards and moves one level down while key of node next to the
	// current node is less than the key of the node being input
	for(int i = level; i >= 0; i--)
	{
		while(current->forwards[i] != NULL && current->forwards[i]->key < _key)
		{
			current = current->forwards[i];
		}

		update[i] = current;
	}

	// Moves to level 0 and forward pointer to the right to insert
	current = current->forwards[0];

	// If current is NULL (end of level reached) or current key is not equal to
	// key of node being input.
	if(current == NULL || current->key != _key)
	{
		// Random number generator for level of node
		int randLvl = randomLevel();

		// If random level is greater than current amount of levels with nodes
		if(randLvl > level)
		{
			for(int i = level+1; i < randLvl+1; i++)
			{
				update[i] = header;
			}

			cout << "Pseudo Random Number Generator: TRUE" << endl << endl;

			// Updates the current list level
			level = randLvl;
		}
		else
		{
			cout << "Pseudo Random Number Generator: FALSE" << endl << endl;
		}

		// Creates a new node with the randomly generated level
		SkipListNode* node = createNode(_key, _value, level, ++position);

		// INPUT -- Inserts node
		for(int i = 0; i <= randLvl; i++)
		{
			node->forwards[i] = update[i]->forwards[i];
			update[i]->forwards[i] = node;
		}

		cout << "INSERTING KEY " << _key << " AND VALUE " << _value << "..."
			 << endl << endl;
		_size++;
	}
}

/*******************************************************************************
 * erase(int _key);
 * 	 Mutator; Deletes node with given key from skip list
 * 	 Parameters: _key   (int)    // IN - key of entry   (node)
 * 	 Return: none
 *******************************************************************************/
void SkipList::erase(int _key) // IN - key of entry   (node)
{
	// Declare variables/initializing variables
	SkipListNode *current = header;   // PROC - pointer tracking current node
	SkipListNode *update[maxLevel+1]; // PROC - update array
	SkipListNode* temp = NULL;        // PROC - temp node

	// Initializes update array
	memset(update, 0, sizeof(SkipListNode*)*(maxLevel+1));

	// If key is found in skip list
	if(isFound(_key, temp))
	{
		cout << "DELETING KEY " << _key << "..." << endl << endl;
		_size--;

		// PROCESSING --
		// Starts from the highest level of the skip list and moves the current
		// pointer forwards and moves one level down while key of node next to the
		// current node is less than the key of the node being input
		for(int i = level; i >= 0; i--)
		{
			while(current->forwards[i] != NULL
				  && current->forwards[i]->key < _key)
			{
				current = current->forwards[i];
			}

			update[i] = current;
		}

		// Moves to level 0 and forward pointer to the right to insert
		current = current->forwards[0];

		// If current node is the node wanting to be erased
		if(current != NULL || current->key == _key)
		{
			// Starts from the lowest level and rearranges node to remove node
			for(int i = 0; i <= level; i++)
			{
				// If at the next node on level i is not the target node, breaks
				// loop
				if(update[i]->forwards[i] != current)
				{
					break;
				}


				update[i]->forwards[i] = current->forwards[i];
			}

			// Removes levels having no elements
			while(level > 0 && header->forwards[level] == 0)
			{
				level--;
			}
		}
	}
	else
	{
		cout << "CANNOT DELETE - KEY " << _key << " DOES NOT EXIST" << endl
			 << endl;
	}
}

/*******************************************************************************
 * erase(SkipListNode* _pos);
 * 	 Mutator; Deletes node with given key from skip list
 * 	 Parameters: _pos (SkipListNode*) // IN - node with position want to delete
 * 	 Return: none
 *******************************************************************************/
void SkipList::erase(SkipListNode* _pos)// IN - node with position want to delete
{
	// Declare variables/initializing variables
	SkipListNode *current = header;   // PROC - pointer tracking current node
	SkipListNode *update[maxLevel+1]; // PROC - update array
	memset(update, 0, sizeof(SkipListNode*)*(maxLevel+1));

	cout << "DELETING KEY AT POSITION " << _pos->position << "..." << endl
		 << endl;

	// If pointer points to NULL or position is less than zero
	if(_pos == NULL || _pos->position <= 0)
	{
		cout << "CANNOT DELETE - ENTRY WITH POSITION " << _pos->position
			 << " DOES NOT EXIST" << endl << endl;
	}
	else if(!empty())
	{
		_size--;

		// PROCESSING --
		// Starts from the highest level of the skip list and moves the current
		// pointer forwards and moves one level down while position of node next
		// to the current node is not equal to the position of the node being
		// input
		for(int i = level; i >= 0; i--)
		{
			while(current->forwards[i] != NULL
				  && current->forwards[i]->position != _pos->position)
			{
				current = current->forwards[i];
			}

			update[i] = current;
		}

		// Moves to level 0 and forward pointer to the right to insert
		current = current->forwards[0];

		// If current node is the node wanting to be erased
		if(current != NULL || current->position == _pos->position)
		{
			// Starts from the lowest level and rearranges node to remove node
			for(int i = 0; i <= level; i++)
			{
				// If next node on level i is not the desired node, breaks loop
				if(update[i]->forwards[i] != current)
				{
					break;
				}

				update[i]->forwards[i] = current->forwards[i];
			}

			// Removes levels with no elements
			while(level > 0 && header->forwards[level] == 0)
			{
				level--;
			}
		}
	}
	else
	{
		cout << "CANNOT DELETE - ENTRY WITH POSITION " << _pos->position
			 << " DOES NOT EXIST" << endl << endl;
	}
}

/*******************************************************************************
 * isFound(int _key, SkipListNode*& _pos)const;
 * 	 Accessor; Searches for node with given key
 * 	 Parameters: _key (int)            // IN - key of entry   (node)
 * 	             _pos (SkipListNode*&) // IN - node looking for
 * 	 Return: found (bool)
 * 	         _pos  (SkipListNode) - by reference
 *******************************************************************************/
bool SkipList::isFound(int _key,                 // IN - key of entry   (node)
		               SkipListNode*& _pos)const // IN - node looking for
{
	// Declare/Initialize variables
	SkipListNode* current = header; // CALC     - pointer tracking current node
	bool found = false;             // CALC/OUT - whether or not entry is found

	cout << "FINDING KEY " << _key << "..." << endl << endl;

	// PROCESSING --
	// Starts from the highest level of the skip list and moves the current
	// pointer forwards and moves one level down while key of node next to the
	// current node is less than the key of the node being input
	for(int i = level; i >= 0; i--)
	{
		while(current->forwards[i] != NULL && current->forwards[i]->key < _key)
		{
			current = current->forwards[i];
		}
	}

	// Moves to level 0 and moves pointer to the right
	current = current->forwards[0];

	// If current key matches key being searched
	if(current && current->key == _key)
	{
		found = true;

		cout << "KEY " << _key << " FOUND" << endl << endl;
	}
	else
	{
		cout << "KEY " << _key << " NOT FOUND" << endl << endl;
	}

	_pos = current;

	return found;

}

/*******************************************************************************
 * findAll(int _key, int& posFirst, int& posLast)const;
 * 	 Accessor; Searches for all nodes with given key
 * 	 Parameters: _key    (int) // IN - key of entry (node)
 * 	             posFirst(int&)// IN - position of first node w/ key
 * 	             posLast (int&)// IN - position of node after last node with key
 * 	 Return: posFirst(int&) - by reference
 * 	         posLast (int&) - by reference
 *******************************************************************************/
void SkipList::findAll(int _key,          // IN - key of entry (node)
		               int& posFirst,     // IN - position of first node w/ key
					   int& posLast)const // IN - position of node after last
                                          //      node with key
{
	// Declare/Initialize variables
	SkipListNode* current = header; // CALC - pointer tracking current node

	cout << "FINDING ALL WITH KEY " << _key << "..." << endl << endl;

	// PROCESSING --
	// Starts from the highest level of the skip list and moves the current
	// pointer forwards and moves one level down while key of node next to the
	// current node is less than the key of the node being input
	for(int i = level; i >= 0; i--)
	{
		while(current->forwards[i] != NULL && current->forwards[i]->key < _key)
		{
			current = current->forwards[i];
		}
	}

	// Moves to level 0 and move pointer to the right
	current = current->forwards[0];


	// If current key is key that wants to find
	if(current && current->key == _key)
	{
		cout << "KEY " << _key << " FOUND" << endl << endl;

		// Sets posFirst to the position of the current node
		posFirst = current->position;

		// Resets current to redo search to find position of last
		current = header;

		// PROCESSING --
		// Starts from the highest level of the skip list and moves the current
		// pointer forwards and moves one level down while key of node next to
		// the current node is less than or equal the key of the node being input
		for(int i = level; i >= 0; i--)
		{
			while(current->forwards[i] != NULL && current->forwards[i]->key <= _key)
			{
				current = current->forwards[i];
			}
		}

		// Moves to level 0 and moves pointer to the right
		current = current->forwards[0];

		// If current key is key that wants to find
		if(current && current->key > _key)
		{
			// Sets last position to the current position
			posLast = current->position;
		}
	}
	else
	{
		cout << "KEY " << _key << " NOT FOUND" << endl << endl;
	}
}

/*******************************************************************************
 * find(int _key)const;
 * 	 Accessor; Searches for node with given key
 * 	 Parameters: _key    (int) // IN - key of entry (node)
 * 	 Return: temp (SkipListNode*)
 *******************************************************************************/
SkipListNode* SkipList::find(int _key)const // IN - key of entry (node)
{
	// Declare/Initializes variables
	SkipListNode* temp; // CALC - temp variable to find node
	temp = NULL;

	if(isFound(_key, temp))
	{
		return temp;
	}
	else
	{
		return end();
	}
}

/*******************************************************************************
 * printSkipList()const;
 * 	 Accessor; Prints elements in skip list
 * 	 Parameters: none
 * 	 Return: none
 * 	          -> Displays dictionary
 *******************************************************************************/
void SkipList::printSkipList()const
{
	cout << endl << endl;
	cout << left << setw(38) << setfill('*') << "*" << endl;
	cout << setfill(' ');
	cout << "        DICTIONARY - SKIP LIST        " << endl;
	cout << left << setw(38) << setfill('*') << "*" << endl;
	cout << setfill(' ');

	for(int i = 0; i <= level; i++)
	{
		// Declare and initialize variable
		SkipListNode* temp = header->forwards[i];

		cout << "LEVEL " << i << ":" << endl;
		cout << left << setw(38) << setfill('-') << "-" << endl;
		cout << setfill(' ');

		while(temp != NULL)
		{
			cout << "P" << left << setw(3) << temp->position << "->  ";
			cout << "Key: " << left << setw(5) << temp->key;
			cout << "Value: " << temp->value << endl;
			temp = temp->forwards[i];
		}

		cout << endl << endl;
	}

	cout << endl;
}

/*******************************************************************************
 * size()const;
 * 	 Accessor; Returns size of skip list
 * 	 Parameters: none
 * 	 Return: _size (int)
 *******************************************************************************/
int SkipList::size()const
{
	return _size;
}

/*******************************************************************************
 * empty()const;
 * 	 Accessor; Returns whether or not skip list is empty
 * 	 Parameters: none
 * 	 Return: bool (true if empty, false if not)
 *******************************************************************************/
bool SkipList::empty()const
{
	return (_size == 0);
}

/*******************************************************************************
 * begin()const;
 * 	 Accessor; Returns node with position of first node
 * 	 Parameters: none
 * 	 Return: current (SkipListNode)
 *******************************************************************************/
const SkipListNode* SkipList::begin()
{
	// Declare/Initialize variables
	SkipListNode* current = header; // CALC - pointer tracking current node


	// PROCESSING --
	// Starts from the highest level of the skip list and moves the current
	// pointer forwards and moves one level down while key of node next to the
	// current node is less than the key of the node being input
	for(int i = level; i >= 0; i--)
	{
		while(current->forwards[i] != NULL
			  && current->forwards[i]->key < current->key)
		{
			current = current->forwards[i];
		}
	}

	// Moves to level 0 and moves pointer to the right
	current = current->forwards[0];

	return current;
}

/*******************************************************************************
 * end()const;
 * 	 Accessor; Returns NULL bc it is what the last entry points to
 * 	 Parameters: none
 * 	 Return: temp
 *******************************************************************************/
SkipListNode* SkipList::end()const
{
	SkipListNode* temp = NULL;

	cout << "END RETURNED" << endl << endl;
	return temp;
}

#endif /* SKIPLISTCLASS_H_ */
