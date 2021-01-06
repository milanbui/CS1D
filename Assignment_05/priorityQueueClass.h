/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #5: Priority Queues
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 27 February 2019
 ******************************************************************************/
#ifndef PRIORITYQUEUECLASS_H_
#define PRIORITYQUEUECLASS_H_

#include"VectorTreeClass.h"
using namespace std;

/*******************************************************************************
 * Time Class
 * 	 This class represents a Time object. It manages two attribute: hours and
 * 	 minutes
 *******************************************************************************/
template<typename E, typename C>
class PriorityQueue
{
public:
	/***************
	 ** MUTATORS **
	 ***************/
	void insert(const E& e);        // Insert element
	void removeMax();               // Remove maximum

	/***************
	 ** ACCESSORS **
	 ***************/
	int size()const;                // Number of elements
	bool empty()const;              // Is queue empty?
	const E& max();                 // Max element
private:
	VectorCompleteTree<E> T;        // Priority queue contents
	C isGreater;                    // greater-than comparator

	// Shortcut for tree position
	typedef typename VectorCompleteTree<E>::Position Position;
};

/*******************************************************************************
 * size()const;
 * 	 Accessor; Returns size of queue (number of elements in queue)
 * 	 Parameters: none
 * 	 Return: T.size()
 *******************************************************************************/
template <typename E, typename C>
int PriorityQueue<E,C>::size()const
{
	return (T.size());
}

/*******************************************************************************
 * empty()const;
 * 	 Accessot; Checks if queue is empty or not
 * 	 Parameters: none
 * 	 Return: true or false
 *******************************************************************************/
template <typename E, typename C>
bool PriorityQueue<E,C>::empty()const
{
	return (size() == 0);
}

/*******************************************************************************
 * max()const;
 * 	 Accessor; Returns the maximum element (element with longest wait time)
 * 	 Parameters: none
 * 	 Return: *(T.root())
 *******************************************************************************/
template <typename E, typename C>
const E& PriorityQueue<E,C>::max()
{
	return *(T.root());
}

/*******************************************************************************
 * insert(const E& e));
 * 	 Mutator; Inserts element e into queue
 * 	 Parameters: e (E) // IN - element being added
 * 	 Return: none
 *******************************************************************************/
template <typename E, typename C>
void PriorityQueue<E,C>::insert(const E& e)  // IN - element being added
{
	// INPUT -- add element to back of queue
	T.addLast(e);

	// Sets position v to the position of the last element (element just added)
	Position v = T.last();

	// While v is not the root
	while(!T.isRoot(v))
	{
		// Sets position u to the position of v's parent
		Position u = T.parent(v);

		// If value of v is not greater than the value of u
		if(!isGreater(*v, *u))
		{
			// In order so break
			break;
		}
		// If value of v is greater than value of u
		else
		{
			// Swap v and u
			T.swap(v, u);

			// Sets position v to be position u
			v = u;
		}
	}
}

/*******************************************************************************
 * removeMax();
 * 	 Mutator; Removes max element (element with highest wait time)
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template <typename E, typename C>
void PriorityQueue<E,C>::removeMax()
{
	// If there is only one element in queue
	if(size() == 1)
	{
		// Remove last element
		T.removeLast();
	}
	else
	{
		// Set position u to be position of root
		Position u = T.root();

		// Swaps u and the last element
		T.swap(u, T.last());

		// Remove the last element
		T.removeLast();

		// While u has as left child
		while(T.hasLeft(u))
		{
			// Set position v to position of u's left child
			Position v = T.left(u);

			// If u has a right child and the value of u's right child is
			// greater than v
			if(T.hasRight(u) && isGreater(*(T.right(u)), *v))
			{
				// Set position v to position of u's right
				v = T.right(u);
			}

			// If value of v is greater than value of u
			if(isGreater(*v, *u))
			{
				// Swaps u with v (values)
				T.swap(u, v);

				// Sets position of u to position of v
				u = v;
			}
			else
			{
				// If sorted, break
				break;
			}
		}
	}
}

#endif /* PRIORITYQUEUECLASS_H_ */
