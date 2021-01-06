/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #5: Priority Queues
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 27 February 2019
 ******************************************************************************/
#ifndef VECTORTREECLASS_H_
#define VECTORTREECLASS_H_


#include<vector>
using namespace std;

/*******************************************************************************
 * VectorCompleteTree Class
 * 	 This class represents a VectorCompleteTree object. It manages one
 * 	 attribute: V
 *******************************************************************************/
template<typename E>
class VectorCompleteTree
{
private:
	vector<E> V;                          // Tree contents
public:
	// A position in the tree
	typedef typename vector<E>::iterator Position;
protected:
	// Map an index to a position
	Position pos(int i)                   {return (V.begin()+ i);}

	// Map a position to an index
	int index(const Position& p)const     {return (p - V.begin());}
public:
	VectorCompleteTree() : V(1) {}        // Constructor

	// Size of tree
	int size()const                       {return (V.size()-1);}

	// Get position of left child of p
	Position left(const Position& p)      {return (pos(2*index(p)));}

	// Get position of right child of p
	Position right(const Position& p)     {return (pos(2*index(p)+1));}

	// Get position of parent of p
	Position parent(const Position &p)    {return (pos(index(p)/2));}

	// Checks if p has a left child
	bool hasLeft(const Position& p)const  {return ((2*index(p)) <= size());}

	// Checks if p has a right child
	bool hasRight(const Position& p)const {return ((2*index(p) + 1) <= size());}

	// Checks if p is the root
	bool isRoot(const Position& p)const   {return (index(p) == 1);}

	// Get position of root
	Position root()                       {return (pos(1));}

	// Get position of last element
	Position last()                       {return (pos(size()));}

	// Add e to the back of the queue
	void addLast(const E& e)              {V.push_back(e);}

	// Remove last element from queue
	void removeLast()                     {V.pop_back();}

	// Swap elements (sorts the queue)
	void swap(const Position& p, const Position &q) {E e = *q; *q = *p; *p = e;}

};
#endif /* VECTORTREECLASS_H_ */
