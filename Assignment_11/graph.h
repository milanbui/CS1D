/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen & Riley Bradt
 * #
 * ASSIGNMENT #11 : BFS & DFS Directed Edges
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 22 April 2019
 ******************************************************************************/
#ifndef GRAPH_H_
#define GRAPH_H_
#include <iomanip>
#include <vector>
#include <queue>
#include <cstring>   // memset
#include <algorithm> // sort
#include "edge.h"

// City names
const string originNames[] =
{
		"Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas City",
		"Chicago", "Boston", "New York", "Atlanta", "Miami", "Dallas",
		"Houston"
};

typedef pair<int, int> Pair;

/*******************************************************************************
 * class Graph
 * 	 This class represents a Graph object. It manages two attributes: size,
 * 	 adjMatrix
 *******************************************************************************/
class Graph
{
public:
	/*****************
	 ** CONSTRUCTOR **
	 *****************/
	Graph(vector<Edge> &edges, int size, vector<Edge> &edges2);

	/***************
	 ** MUTATORS **
	 ***************/
	void BFS(int start);
	void DFS(int start, bool prime);

	/***************
	 ** ACCESSORS **
	 ***************/
	void printGraph()const;
	bool strongConnectivity(int start);
private:
	int size;         // Size of matrix (num of vertices)
	Edge **adjMatrix; // Adjacency Matrix
	Edge **adjMatrixPrime;

	void BFS_Utility(int current, vector<Pair> &route, int &distance);
	void DFS_Utility(int current, vector<Pair> &route, int &distance, bool prime);
	void DFS_Utility_Prime(int current, vector<Pair> &route, int &distance);
};


/*******************************************************************************
 * Graph(vector<Edge> &edges, int size);
 * 	 Constructor; Initializes attributes
 * 	 Parameters: edges (vector<Edge>) - edges in the graph
 * 	             size - size of matrix (num of vertices)
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * printGraph()const;
 * 	 Accessor; Displays the adjacency matrix
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * BFS(int start);
 * 	 Mutator; Performs the breadth first search starting from a certain city
 * 	          and displays the discovery edged, cross edges, the total distance
 * 	          traveled on the discovery edges, and the order of the traversal
 * 	 Parameters: start (int) - starting city index
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * BFS_Utility(int current, vector<Pair> &route, int &distance);
 * 	 Mutator; Performs the breadth first search starting from a certain city
 * 	          and displays the discovery edged & cross edges
 * 	 Parameters: current (int)          - origin city index
 * 	             route   (vector<Pair>) - path traveled in bfs
 * 	             distance(int)          - distance traveled on discovery edges
 * 	 Return: none
 *******************************************************************************/


#endif /* GRAPH_H_ */
