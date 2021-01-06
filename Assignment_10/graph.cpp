/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Tran Nguyen
 * #
 * ASSIGNMENT #10A: DFS
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 17 April 2019
 ******************************************************************************/
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
 * class Graph
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
Graph::Graph(vector<Edge> &edges, // IN - Edges in the graph
		     int num)             // IN - number of vertices in the graph
{
	// Resizes the vector to num number of elements of type vector<Pair>
	adjList.resize(num);

	// Adds edges to the graph
	for(auto &edge : edges)
	{
		int origin = edge.origin;
		int destination = edge.destination;
		int distance = edge.distance;

		adjList[origin].push_back(make_pair(destination, distance));
		adjList[destination].push_back(make_pair(origin, distance));

	}
}

/*******************************************************************************
 * printGraph(int num)const;
 * 	 Accessor; Displays the graph as and Adjacent List
 * 	 Parameters: num (integer) - number of vertices in the graph
 * 	 Return: none
 * 	         -> outputs the values in the adjacent list
 *******************************************************************************/
void Graph::printGraph(int num)const // IN - number of vertices in the graph
{
	for(int i = 0; i < num; i++)
	{
		cout << originNames[i];

		// Prints all adjacent vertices of the given vertex
		for(Pair x : adjList[i])
		{
			cout << " -> " << originNames[x.first] << " (" << x.second << ")";
		}
		cout << endl << endl;
	}
}

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
void Graph::DFS(int num,      // IN - number of vertices in the graph
		        int startFrom)// IN - the integer of the city to start from
{
	// Declare variables
	int current = startFrom;  // Current index
	int distance = 0;         // Distance
	vector<Pair> route;       // Vector to hold route of DFS

	// Initializes boolean vector
	vector<bool> visited(num, false);

	// Calls recursive function for DFS
	DFS_Utility(current, visited, route, distance);

	// Displays the results of the DFS
	cout << endl << endl;
	cout << "DFS Starting from " << originNames[startFrom] << ":" << endl;
	cout << originNames[startFrom] << " -> ";

	for(unsigned i = 0; i < route.size(); i++)
	{
		cout << originNames[route[i].first];

		if(i < route.size() - 1)
		{
			cout << " -> ";
		}
	}
	cout << endl << endl;

	cout << "MILES OF DISCOVERY EDGES: " << distance << endl;
}

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
void Graph::DFS_Utility(int current,           // Current index
		                vector<bool> &visited, // vector keeping track of what has been
						                       // visited and what has not
						vector<Pair> &route,   // vector keeping track of the route
						int &dist)             // total distance traveled on discovery
                                               // edges
{
	// Declare variables
	vector<Pair>::iterator it;  // Iterator
	vector<Pair> path;          // Vector to hold adjacent vertices/edges
	unsigned i;                 // Loop control variable
	int temp;                   // Temporary variable to change data

	// Initialize variables
	visited[current] = true;

	// Puts unvisited adjacent vertices and their weights into a vector to be sorted
	for(it = adjList[current].begin(); it != adjList[current].end(); it++)
	{
		if(!visited[(*it).first])
		{
			// Inserts as a pair (distance, destination)
			path.push_back(Pair((*it).second, (*it).first));
		}
	}

	// Sorts by distance shortest to longest
	sort(path.begin(), path.end());


	// Loops through entire thing -> goes to every adjacent vertex
	for(i = 0; i < path.size(); i++)
	{
		// If this vertex has been visited
		if(visited[path[i].second])
		{
			// Set as back edge
			cout << left << setw(10) << "Back" << "Edge: "
				 << originNames[current] << " -> "
				 << originNames[path[i].second] << endl;
		}

		// If this vertex has yet to be visited
		if(!visited[path[i].second])
		{
			// Adds new vertex/edge to route
			route.push_back(Pair(path[i].second, path[i].first));

			// Adds distance to overall distance bc found new vertex
			dist += path[i].first;

			// Sets visited to true for this vertex
			visited[path[i].second] = true;

			// Sets as discovery edge because new vertex found on edge
			cout << left << setw(10) << "Discovery" << "Edge: "
				 << originNames[current] << " -> "
				 << originNames[path[i].second]
				 << "(" << path[i].first << ")" << endl;

			// Sets current to this new vertex found
			current = path[i].second;

			// Recursive call for DFS function
			DFS_Utility(current, visited, route, dist);
		}

		// If the vertex has been visited
		if(visited[current] && current != route[0].first)
		{

			// Move back one. -> backtrack
			for(unsigned j = 0; j < route.size(); j++)
			{
				if(route[j].first == current)
				{
					temp = j-1;
				}
			}

			current = route[temp].first;
		}
	}
}

