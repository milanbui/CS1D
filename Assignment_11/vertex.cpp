/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen & Riley Bradt
 * #
 * ASSIGNMENT #11 : BFS & DFS Directed Edges
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 22 April 2019
 ******************************************************************************/
#include <iostream>
using namespace std;

/*******************************************************************************
 * class Vertex
 * 	 This class represents a Vertex object. It manages two attributes: vertex,
 * 	 visited
 *******************************************************************************/
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
Vertex::Vertex()
{
	vertex = 0;
	visited = false;
}

/*******************************************************************************
 * setVertex();
 * 	 Mutator; Sets the vertex
 * 	 Parameters: _vertex (int) - vertex in the graph
 * 	 Return: none
 *******************************************************************************/
void Vertex::setVertex(int _vertex) // IN - vertex in the graph
{
	vertex = _vertex;
}

/*******************************************************************************
 * changeVertexType(bool _visited);
 * 	 Mutator; Changes the vertex type
 * 	 Parameters: _visited (bool) - whether or not the vertex has been visited
 * 	 Return: none
 *******************************************************************************/
void Vertex::changeVertexType(bool _visited) // IN - whether or not the vertex
                                             //      has been visited
{
	visited = _visited;
}

/*******************************************************************************
 * isVisited()const;
 * 	 Accessor; Returns whether or not the vertex has been visited
 * 	 Parameters: none
 * 	 Return: visited (bool)
 *******************************************************************************/
bool Vertex::isVisited()const
{
	return visited;
}

/*******************************************************************************
 * getVertex()const;
 * 	 Accessor; Returns the vertex
 * 	 Parameters: none
 * 	 Return: vertex (int)
 *******************************************************************************/
int Vertex::getVertex()const
{
	return vertex;
}
