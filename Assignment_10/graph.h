/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Tran Nguyen
 * #
 * ASSIGNMENT #10A: DFS
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 17 April 2019
 ******************************************************************************/
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;


struct Edge
{
	int origin;       // Origin city (starting vertex)
	int destination;  // Destination city (ending vertex)
	int distance;     // Distance between the two cities
};

typedef pair<int, int> Pair;

// City names
const string originNames[] =
{
		"Seattle", "San Francisco", "Denver", "Chicago", "Los Angeles",
		"Kansas City", "Dallas", "Houston", "Miami", "Atlanta", "New York",
		"Boston"
};


/*******************************************************************************
 * Deque Graph
 * 	 This class represents a Graph object. It manages one attributes: adjList
 *******************************************************************************/
class Graph
{
public:
	/*****************
	 ** CONSTRUCTOR **
	 *****************/
	Graph(vector<Edge> &edges, int num);


	void DFS(int num, int startFrom);
	void printGraph(int num)const;
private:
	vector< vector<Pair> > adjList;   // Adjacent List

	// Recursive functions for DFS with weights
	void DFS_Utility(int current, vector<bool> &visited, vector<Pair> &route, int &dist);
};

/*******************************************************************************
 * Graph();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: edges (vector<Edge>) - Edges in the graph
 * 	             num   (integer)      - number of vertices in the graph
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * printGraph(int num)const;
 * 	 Accessor; Displays the graph as and Adjacent List
 * 	 Parameters: num (integer) - number of vertices in the graph
 * 	 Return: none
 * 	         -> outputs the values in the adjacent list
 *******************************************************************************/

/*******************************************************************************
 * DFS(int num, int startFrom);
 * 	 Mutator; Performs the depth first search of the graph using a recursive
 * 	          function, displays the type of edges, the result, and the total
 * 	          miles traveled on the discovery edges.
 * 	 Parameters: num (integer) - number of vertices in the graph
 * 	             startFrom (integer) - the integer of the city to start from
 * 	 Return: none
 * 	         -> displays the traversal
 *******************************************************************************/


/*******************************************************************************
 * DFS_Utility(int current, vector<bool> &visited, vector<Pair> &route, int &dist);
 * 	 Mutator; Performs the depth first search of the graph using a recursive
 * 	          function, displays the type of edges, the result, and the total
 * 	          miles traveled on the discovery edges.
 * 	 Parameters: current (integer)     - current index
 * 	             visited (vector<boo>) - vector keeping track of what has been
 * 	                                     visited and what has not
 * 	             route   (vector<Pair>)- vector keeping track of the route
 * 	             dist    (integer)     - total distance traveled on discovery
 * 	                                     edges
 * 	 Return: none
 * 	         -> displays the traversal
 *******************************************************************************/





#endif /* GRAPH_H_ */
