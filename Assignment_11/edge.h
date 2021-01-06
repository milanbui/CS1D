/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen & Riley Bradt
 * #
 * ASSIGNMENT #11 : BFS & DFS Directed Edges
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 22 April 2019
 ******************************************************************************/
#ifndef EDGE_H_
#define EDGE_H_

#include <iostream>
#include "vertex.h"
using namespace std;


enum EdgeType
{
	UNEXPLORED, // Unexplored edge
	DISCOVERY,  // Discovery edge (edge leading to a new/unvisited vertex)
	CROSS,       // Cross edge (edge leading to an already visited vertex)
	BACK,
	FORWARD
};


/*******************************************************************************
 * class Edge
 * 	 This class represents a Edge object. It manages four attributes: weight,
 * 	 origin, destination, type
 *******************************************************************************/
class Edge
{
public:
	/*****************
	 ** CONSTRUCTOR **
	 *****************/
	Edge();
	Edge(int _weight, int _destination, int _origin);


	/***************
	 ** MUTATORS **
	 ***************/
	void changeVertexType(bool _visited);
	void changeEdgeType(EdgeType _type);

	/***************
	 ** ACCESSORS **
	 ***************/
	bool isVisited()const;
	EdgeType edgeType()const;
	int getDistance()const;
	int getDestination()const;
	int getOrigin()const;

private:
	int      weight;      // distance between two vertices/weight of the edge
	Vertex   origin;      // the city of origin/start vertex
	Vertex   destination; // the destination city/opposite vertex
	EdgeType type;        // the edge type -> unexplored, discovery, or cross
};


/*******************************************************************************
 * Edge();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * Edge(int _weight, int _destination, int _origin);
 * 	 Constructor; Initializes attributes
 * 	 Parameters: _weight      (int) - distance between two vertices
 * 	             _destination (int) - the destination city/opposite vertex
 * 	             _origin      (int) - the city of origin/start vertex
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * changeVertexType(bool _visited);
 * 	 Mutator; Changes the vertex type (whether it's been visited or not)
 * 	 Parameters: _visited (bool) - whether the vertex has been visited or not
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * changeEdgeType(EdgeType _type);
 * 	 Mutator; Changes the edge type (unexplored, discovery, or cross)
 * 	 Parameters: _type (EdgeType) - if edge is unexplored, discovery, or cross
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * isVisited()const;
 * 	 Accessor; Returns whether or not the vertex (destination) has been visited
 * 	 Parameters: none
 * 	 Return: bool (true or false)
 *******************************************************************************/

/*******************************************************************************
 * edgeType()const;
 * 	 Accessor; Returns the edge type (unexplored, discovery, cross)
 * 	 Parameters: none
 * 	 Return: type (EdgeType)
 *******************************************************************************/

/*******************************************************************************
 * getDistance()const;
 * 	 Accessor; Returns the weight of the edge
 * 	 Parameters: none
 * 	 Return: weight (int)
 *******************************************************************************/

/*******************************************************************************
 * getDestination()const;
 * 	 Accessor; Returns the destination, the opposite vertex
 * 	 Parameters: none
 * 	 Return: destination (int)
 *******************************************************************************/

/*******************************************************************************
 * getOrigin()const;
 * 	 Accessor; Returns the origin
 * 	 Parameters: none
 * 	 Return: origin (int)
 *******************************************************************************/

#endif /* EDGE_H_ */
