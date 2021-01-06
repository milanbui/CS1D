/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen & Riley Bradt
 * #
 * ASSIGNMENT #11 : BFS & DFS Directed Edges
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 22 April 2019
 ******************************************************************************/
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
	Graph(vector<Edge> &edges, int size,vector<Edge> &edges2);

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
Graph::Graph(vector<Edge> &edges, // IN - edges in the graph
		     int size,
			 vector<Edge> &edges2)            // IN - size of matrix (num of vertices)
{
	// Initializes variables
	this->size = size;

	// Creates  dynamic array of pointers
	adjMatrix = new Edge* [size];
	adjMatrixPrime = new Edge* [size];

	// Creates a row for every pointer
	for(int  i = 0; i < size; i++)
	{
		adjMatrix[i] = new Edge[size];
		adjMatrixPrime[i] = new Edge[size];

		// Initializes all entries to 0 to indicate no edge between the two
		// vertices
		memset(adjMatrix[i], 0, size*sizeof(Edge));
		memset(adjMatrixPrime[i], 0, size*sizeof(Edge));
	}

	// Inserts all the edges into the matrix
	for(auto &edge : edges)
	{
		int origin = edge.getOrigin();
		int destination = edge.getDestination();

		adjMatrix[origin][destination] = edge;
	}

	for(auto &edge1 : edges2)
	{
		Edge temp(edge1.getDistance(), edge1.getOrigin(), edge1.getDestination());
		int origin = temp.getOrigin();
		int destination = temp.getDestination();


		adjMatrixPrime[origin][destination] = temp;
	}
}

/*******************************************************************************
 * printGraph()const;
 * 	 Accessor; Displays the adjacency matrix
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void Graph::printGraph()const
{
	// OUTPUT -- displays the column header city names for the matrix
	cout << left << setw(21) << " ";

	for(int i = 0; i < size; i++)
	{
		cout << originNames[i].substr(0,3) << "...   ";
	}

	cout << endl;
	cout << endl;

	// OUTPUT -- displays the matrices
	for(int row = 0; row < size; row++)
	{
		// Displays the row header city names for matrix
		cout << right << setw(16) << originNames[row] << "     ";

		for(int col = 0; col < size; col++)
		{
			cout << left << setw(9) << adjMatrix[row][col].getDistance();
		}

		cout << endl;
		cout << endl;
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
void Graph::DFS(int start, bool prime)// IN - the integer of the city to start from
{
	// Declaring & Initializing variables
	int current = start; // IN   - starting index
	int distance = 0;    // CALC - the distance traveled on the discovery edges
	vector<Pair> route;  // IN   - the order of the cities traveled in the BFS


	DFS_Utility(current, route, distance, prime);

	// Displays the results of the DFS
	cout << endl << endl;
	cout << "DFS Starting from " << originNames[start] << ":" << endl;
	cout << originNames[start] << " -> ";

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
 * BFS(int start);
 * 	 Mutator; Performs the breadth first search starting from a certain city
 * 	          and displays the discovery edged, cross edges, the total distance
 * 	          traveled on the discovery edges, and the order of the traversal
 * 	 Parameters: start (int) - starting city index
 * 	 Return: none
 *******************************************************************************/
void Graph::BFS(int start) // IN - starting city index
{
	// Declaring & Initializing variables
	int current = start; // IN   - starting index
	int distance = 0;    // CALC - the distance traveled on the discovery edges
	vector<Pair> route;  // IN   - the order of the cities traveled in the BFS

	BFS_Utility(current, route, distance);

	// Displays the results of the DFS
	cout << endl << endl;
	cout << "BFS Starting from " << originNames[start] << ":" << endl;
	cout << originNames[start] << " -> ";

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
 * BFS_Utility(int current, vector<Pair> &route, int &distance);
 * 	 Mutator; Performs the breadth first search starting from a certain city
 * 	          and displays the discovery edged & cross edges
 * 	 Parameters: current (int)          - origin city index
 * 	             route   (vector<Pair>) - path traveled in bfs
 * 	             distance(int)          - distance traveled on discovery edges
 * 	 Return: none
 *******************************************************************************/
void Graph::BFS_Utility(int current,         // PROC - origin city index
		                vector<Pair> &route, // PROC - path traveled in bfs
						int &distance)       // PROC - distance traveled on
                                             //        discovery edges
{
	// Declaring variables
	vector<Pair> path;   // PROC - contains the adjacent vertices to sort them
	queue<int> vertices; // PROC - contains the vertices in the order visited

	// PROCESSING - setting the current vertex to be visited
	for(int i = 0; i < size; i++)
	{

		adjMatrix[i][current].changeVertexType(true);

	}

	// Loops while all vertices have not been visited yet
	do
	{
		// INPUT -- inserts the adjacent vertices in path as a pair
		//          (distance, destination)
		for(int col = 0; col < size; col++)
		{
			if(adjMatrix[current][col].getDistance() != 0)
			{
				path.push_back(Pair(adjMatrix[current][col].getDistance(),
									 adjMatrix[current][col].getDestination()));
			}
		}

		// PROCESSING -- sorts the vertices by their distance in ascending order
		//               (shortest to longest distance)
		sort(path.begin(), path.end());

		// Loops for all the adjacent vertices
		for(unsigned col = 0; col < path.size(); col++)
		{
			// If the adjacent vertex has yet to be visited
			if(!adjMatrix[current][path[col].second].isVisited())
			{
				// INPUT -- adds the new visited edge/vertex to the route
				route.push_back(Pair(path[col].second, path[col].first));

				// INPUT -- adds the new vertex to the vertices visited
				vertices.push(path[col].second);

				// PROCESSING -- adds the distance of the edge to the total
				//               distance traveled
				distance += path[col].first;

				// PROCESSING -- sets the vertex to visited
				for(int i = 0; i < size; i++)
				{

					adjMatrix[i][path[col].second].changeVertexType(true);

				}

				// PROCESSING -- sets edge to discovery from unexplored
				adjMatrix[current]
						 [path[col].second].changeEdgeType(DISCOVERY);


				// OUTPUT -- displays the information of the discovery edge
				cout << left << setw(10) << "Discovery" << "Edge: "
					 << originNames[current] << " -> "
					 << originNames[path[col].second]
					 << "(" << path[col].first << ")" << endl;
			}
			// If the vertex has been visited and the edge is unexplored
			else if(adjMatrix[current][path[col].second].edgeType() == UNEXPLORED)
			{
				// PROCESSING -- sets edge to cross
				adjMatrix[current][path[col].second].changeEdgeType(CROSS);


				// OUTPUT -- displays the information of the cross edge
				cout << left << setw(10) << "Cross" << "Edge: "
					 << originNames[current] << " -> "
					 << originNames[path[col].second] << endl;
			}
		}
		// Sets the current vertex to the first vertex from the given level
		current = vertices.front();

		// Deletes that vertex from the queue to indicate it has been used
		vertices.pop();

		// PROC -- empties the vector that holds the adjacent vertices of the
		//         previous vertex
		while(!path.empty())
		{
			path.pop_back();
		}
	}while(!vertices.empty());

}

/*******************************************************************************
 * BFS_Utility(int current, vector<Pair> &route, int &distance);
 * 	 Mutator; Performs the breadth first search starting from a certain city
 * 	          and displays the discovery edged & cross edges
 * 	 Parameters: current (int)          - origin city index
 * 	             route   (vector<Pair>) - path traveled in bfs
 * 	             distance(int)          - distance traveled on discovery edges
 * 	 Return: none
 *******************************************************************************/
void Graph::DFS_Utility(int current,         // PROC - origin city index
		                vector<Pair> &route, // PROC - path traveled in bfs
						int &distance, bool prime)       // PROC - distance traveled on
                                             //        discovery edges
{
	// Declaring variables
	vector<Pair> path;   // PROC - contains the adjacent vertices to sort them
	queue<int> vertices; // PROC - contains the vertices in the order visited


	// PROCESSING - setting the current vertex to be visited
	for(int i = 0; i < size; i++)
	{

		adjMatrix[i][current].changeVertexType(true);

	}


	// INPUT -- inserts the adjacent vertices in path as a pair
	//          (distance, destination)
	for(int col = 0; col < size; col++)
	{
		if(adjMatrix[current][col].getDistance() != 0)
		{
			path.push_back(Pair(adjMatrix[current][col].getDistance(),
								 adjMatrix[current][col].getDestination()));
		}
	}

	// PROCESSING -- sorts the vertices by their distance in ascending order
	//               (shortest to longest distance)
	sort(path.begin(), path.end());

	// Loops for all the adjacent vertices
	for(unsigned col = 0; col < path.size(); col++)
	{
		// If the adjacent vertex has yet to be visited
		if(!adjMatrix[current][path[col].second].isVisited())
		{
			// INPUT -- adds the new visited edge/vertex to the route
			route.push_back(Pair(path[col].second, path[col].first));

			// INPUT -- adds the new vertex to the vertices visited
			vertices.push(path[col].second);

			// PROCESSING -- adds the distance of the edge to the total
			//               distance traveled
			distance += path[col].first;

			// PROCESSING -- sets the vertex to visited
			for(int i = 0; i < size; i++)
			{

				adjMatrix[i][path[col].second].changeVertexType(true);

			}

			// PROCESSING -- sets edge to discovery from unexplored
			adjMatrix[current]
					 [path[col].second].changeEdgeType(DISCOVERY);

			if(!prime)
			{
				// OUTPUT -- displays the information of the discovery edge
				cout << left << setw(10) << "Discovery" << "Edge: "
					 << originNames[current] << " -> "
					 << originNames[path[col].second]
					 << "(" << path[col].first << ")" << endl;
			}
			// Sets the current vertex to the first vertex from the given level
			current = vertices.front();

			// Deletes that vertex from the queue to indicate it has been used
			vertices.pop();


			// Recursive call for DFS function
			DFS_Utility(current, route, distance, prime);
		}
		// If the vertex has been visited and the edge is unexplored
		else if(adjMatrix[current][path[col].second].edgeType() == UNEXPLORED)
		{
			// PROCESSING -- sets edge to cross
			adjMatrix[current][path[col].second].changeEdgeType(BACK);

			if(!prime)
			{
				// OUTPUT -- displays the information of the cross edge
				cout << left << setw(10) << "Back" << "Edge: "
					 << originNames[current] << " -> "
					 << originNames[path[col].second] << endl;
			}
		}
	}
}


/*******************************************************************************
 * BFS_Utility(int current, vector<Pair> &route, int &distance);
 * 	 Mutator; Performs the breadth first search starting from a certain city
 * 	          and displays the discovery edged & cross edges
 * 	 Parameters: current (int)          - origin city index
 * 	             route   (vector<Pair>) - path traveled in bfs
 * 	             distance(int)          - distance traveled on discovery edges
 * 	 Return: none
 *******************************************************************************/
void Graph::DFS_Utility_Prime(int current,         // PROC - origin city index
		                      vector<Pair> &route, // PROC - path traveled in bfs
					          int &distance)       // PROC - distance traveled on
                                                   //        discovery edges
{
	// Declaring variables
	vector<Pair> path;   // PROC - contains the adjacent vertices to sort them
	queue<int> vertices; // PROC - contains the vertices in the order visited


	// PROCESSING - setting the current vertex to be visited
	for(int i = 0; i < size; i++)
	{

		adjMatrixPrime[i][current].changeVertexType(true);

	}


	// INPUT -- inserts the adjacent vertices in path as a pair
	//          (distance, destination)
	for(int col = 0; col < size; col++)
	{
		if(adjMatrixPrime[current][col].getDistance() != 0)
		{
			path.push_back(Pair(adjMatrixPrime[current][col].getDistance(),
					            adjMatrixPrime[current][col].getDestination()));
		}
	}

	// PROCESSING -- sorts the vertices by their distance in ascending order
	//               (shortest to longest distance)
	sort(path.begin(), path.end());

	// Loops for all the adjacent vertices
	for(unsigned col = 0; col < path.size(); col++)
	{
		// If the adjacent vertex has yet to be visited
		if(!adjMatrixPrime[current][path[col].second].isVisited())
		{
			// INPUT -- adds the new visited edge/vertex to the route
			route.push_back(Pair(path[col].second, path[col].first));

			// INPUT -- adds the new vertex to the vertices visited
			vertices.push(path[col].second);

			// PROCESSING -- adds the distance of the edge to the total
			//               distance traveled
			distance += path[col].first;

			// PROCESSING -- sets the vertex to visited
			for(int i = 0; i < size; i++)
			{

				adjMatrixPrime[i][path[col].second].changeVertexType(true);

			}

			// PROCESSING -- sets edge to discovery from unexplored
			adjMatrixPrime[current]
					      [path[col].second].changeEdgeType(DISCOVERY);

			// Sets the current vertex to the first vertex from the given level
			current = vertices.front();

			// Deletes that vertex from the queue to indicate it has been used
			vertices.pop();


			// Recursive call for DFS function
			DFS_Utility_Prime(current, route, distance);
		}
		// If the vertex has been visited and the edge is unexplored
		else if(adjMatrixPrime[current][path[col].second].edgeType() == UNEXPLORED)
		{
			// PROCESSING -- sets edge to cross
			adjMatrixPrime[current][path[col].second].changeEdgeType(BACK);
		}
	}
}

bool Graph::strongConnectivity(int start)
{
	// Declaring & Initializing variables
	int current = start; // IN   - starting index
	int distance = 0;    // CALC - the distance traveled on the discovery edges
	vector<Pair> route;  // IN   - the order of the cities traveled in the BFS
	int distance2 = 0;    // CALC - the distance traveled on the discovery edges
	vector<Pair> route2;  // IN   - the order of the cities traveled in the BFS

	DFS_Utility(current, route, distance, true);

	for(int row = 0; row < size; row++)
	{
		for(int col = 0; col < size; col++)
		{
			if(!adjMatrix[row][col].isVisited())
			{
				return false;
			}
		}
	}

	DFS_Utility_Prime(start, route2, distance2);

	for(int row = 0; row < size; row++)
	{
		for(int col = 0; col < size; col++)
		{
			if(!adjMatrixPrime[row][col].isVisited())
			{
				return false;
			}
		}
	}


	cout << endl << endl;
	return true;
}
