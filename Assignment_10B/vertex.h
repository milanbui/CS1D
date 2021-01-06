/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen
 * #
 * ASSIGNMENT #10B: BFS
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 17 April 2019
 ******************************************************************************/
#ifndef VERTEX_H_
#define VERTEX_H_

#include <iostream>
using namespace std;

class Vertex
{
public:
	/*****************
	 ** CONSTRUCTOR **
	 *****************/
	Vertex();

	/***************
	 ** MUTATORS **
	 ***************/
	void setVertex(int _vertex);
	void changeVertexType(bool _visited);

	/***************
	 ** ACCESSORS **
	 ***************/
	bool isVisited()const;
	int getVertex()const;
private:
	int vertex;   // Vertex in the graph
	bool visited; // Whether or not the vertex has been visited
};

/*******************************************************************************
 * Vertex();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * setVertex();
 * 	 Mutator; Sets the vertex
 * 	 Parameters: _vertex (int) - vertex in the graph
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * changeVertexType(bool _visited);
 * 	 Mutator; Changes the vertex type
 * 	 Parameters: _visited (bool) - whether or not the vertex has been visited
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * isVisited()const;
 * 	 Accessor; Returns whether or not the vertex has been visited
 * 	 Parameters: none
 * 	 Return: visited (bool)
 *******************************************************************************/

/*******************************************************************************
 * getVertex()const;
 * 	 Accessor; Returns the vertex
 * 	 Parameters: none
 * 	 Return: vertex (int)
 *******************************************************************************/

#endif /* VERTEX_H_ */
