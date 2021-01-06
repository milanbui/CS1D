/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen & Riley Bradt
 * #
 * ASSIGNMENT #11 : BFS & DFS Directed Edges
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 22 April 2019
 ******************************************************************************/
#include "graph.h"
#include "printHeader.h"
/*******************************************************************************
 * BFS AND DFS WITH ADJACENCY MATRIX FOR DIRECTED GRAPH
 * _____________________________________________________________________________
 *
 * This program will store a set of vertices which create edges and their
 * weights in an adjacent matrix structure. Displays the vertices with their
 * adjacent vertices in the adjacent matrix. Perform a breadth first search
 * (BFS) starting from Dallas, choosing the edge with the shortest distance.
 * Displays the result of the BFS (discovery and cross edges) and the total
 * miles traveled on the discovery edges. Perform a depth first search (DFS)
 * starting from Dallas, choosing the edge with the shortest distance. Displays
 * the result of the DFS (edges) and the total miles traveled on the discovery
 * edges. Check to see if the graph is strongly connected.
 * _____________________________________________________________________________
 * INPUT:
 *	    graph - adjacency matrix containing vertices, edges, and weights
 *
 * OUTPUT:
 *	    graph - adjacency matrix containing vertices, edges, and weights
 *
 ******************************************************************************/
int main()
{
	// Declaring & Initializing variables

	/* Edges being initialized (distance, destination, origin)
	 * 0 - Seattle     | 1 - San Francisco | 2  - Los Angeles | 3  - Denver
	 * 4 - Kansas City | 5 - Chicago       | 6  - Boston      | 7  - New York
	 * 8 - Atlanta     | 9 - Miami         | 10 - Dallas      | 11 - Houston
	 */
	Edge edge0(807 , 1 , 0);
	Edge edge1(1331, 3 , 0);

	Edge edge4(381 , 2 , 1);

	Edge edge7(1015, 3 , 2);

	Edge edge11(1267, 1, 3);
	Edge edge14(1003, 5, 3);

	Edge edge15(1663, 2 , 4);
	Edge edge16(599 , 3 , 4);
	Edge edge17(533 , 5 , 4);
	Edge edge18(1260, 7 , 4);
	Edge edge19(864 , 8 , 4);

	Edge edge21(2097, 0, 5);
	Edge edge24(983 , 6, 5);

	Edge edge27(214 , 7, 6);

	Edge edge29(787 , 5, 7);
	Edge edge31(888 , 8, 7);

	Edge edge34(661, 9 , 8);

	Edge edge37(1187, 11, 9);

	Edge edge39(1435, 2, 10);
	Edge edge40(496 , 4, 10);
	Edge edge41(781 , 8, 10);

	Edge edge43(239 , 10, 11);
	Edge edge45(810 , 8 , 11);

	// Vector of edge objects
	vector<Edge> edges =
	{
		edge0, edge1, edge4, edge7, edge11, edge14, edge15, edge16, edge17,
		edge18, edge19, edge21, edge24, edge27, edge29, edge31, edge34, edge37,
		edge39, edge40, edge41, edge43, edge45
	};

	// Adjacency matrix initialized with the vector of edges
	Graph graph (edges, 12, edges);
	Graph graph2(edges, 12, edges);
	Graph graph3(edges, 12, edges);

	// OUTPUT -- class header and assignment description
	cout << printHeader("Hai-Trang Nguyen & Riley Bradt", "BFS & DFS Directed Edges", 'A', 11);
	cout << endl;
	cout << "This program will:" << endl;
	cout << "1. Store a set of vertices which create edges and their weights in"
			"\n   an adjacent matrix structure." << endl;
	cout << "2. Displays the vertices with their adjacent vertices in the adjacent"
			"\n   matrix." << endl;
	cout << "3. Perform a breadth first search (BFS) starting from Dallas, choosing"
			"\n   the edge with the shortest distance." << endl;
	cout << "4. Displays the result of the BFS (edges) and the"
			"\n   total miles traveled on the discovery edges" << endl;
	cout << "5. Perform a depth first search (DFS) starting from Dallas, choosing"
	        "\n   the edge with the shortest distance." << endl;
	cout << "6. Displays the result of the DFS (edges) and the"
			"\n   total miles traveled on the discovery edges." << endl;
	cout << "7. Check to see if the graph is strongly connected."
		 << endl << endl << endl;


	// OUTPUT -- displays the adjacency matrix
	cout << "ADJACENCY MATRIX:" << endl << endl;
	graph.printGraph();

	cout << endl << endl << endl;

	// PROCESSING & OUTPUT -- performs a breadth first search starting from
	//                        index 10 (Dallas) and displays the result as well
	//                        as the discovery and cross edges
	cout << "BREADTH FIRST SEARCH (BFS):" << endl << endl;
	graph.BFS(10);

	cout << endl << endl;

	cout << "DEPTH FIRST SEARCH (DFS):" << endl << endl;
	graph2.DFS(10, false);

	if(graph3.strongConnectivity(10))
	{
		cout << "STRONG CONNECTIVITY: YES" << endl;
		cout << "There are no vertices that are not visited in the graph G"
				"\nand in graph G' (graph G with the edges reversed)."<< endl << endl;
	}
	else
	{
		cout << "STRONG CONNECTIVITY: NO" << endl;
		cout << "There are vertices that are not visited in the graph G"
				"\nor in graph G' (graph G with the edges reversed)."<< endl << endl;
	}


	return 0;
}


