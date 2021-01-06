/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Trang Nguyen
 * #
 * ASSIGNMENT #10B: BFS
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 17 April 2019
 ******************************************************************************/
#include "graph.h"
#include "printHeader.h"
/*******************************************************************************
 * BREADTH FIRST SEARCH USING AN ADAJCENCY MATRIX
 * _____________________________________________________________________________
 *
 * This program will store a set of vertices which create edges and their
 * weights in an adjacent matrix structure. Displays the vertices with their
 * adjacent vertices in the adjacent matrix. Perform a breadth first search
 * (BFS) starting from Dallas, choosing the edge with the shortest distance.
 * Displays the result of the BFS (discovery and cross edges) and the total
 * miles traveled on the discovery edges
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
	Edge edge2(2097, 5 , 0);


	Edge edge3(807 , 0 , 1);
	Edge edge4(381 , 2 , 1);
	Edge edge5(1267, 3 , 1);


	Edge edge6(381 , 1 , 2);
	Edge edge7(1015, 3 , 2);
	Edge edge8(1663, 4 , 2);
	Edge edge9(1435, 10, 2);


	Edge edge10(1331, 0, 3);
	Edge edge11(1267, 1, 3);
	Edge edge12(1015, 2, 3);
	Edge edge13(599 , 4, 3);
	Edge edge14(1003, 5, 3);


	Edge edge15(1663, 2 , 4);
	Edge edge16(599 , 3 , 4);
	Edge edge17(533 , 5 , 4);
	Edge edge18(1260, 7 , 4);
	Edge edge19(864 , 8 , 4);
	Edge edge20(496 , 10, 4);

	Edge edge21(2097, 0, 5);
	Edge edge22(1003, 3, 5);
	Edge edge23(533 , 4, 5);
	Edge edge24(983 , 6, 5);
	Edge edge25(787 , 7, 5);


	Edge edge26(983 , 5, 6);
	Edge edge27(214 , 7, 6);


	Edge edge28(1260, 4, 7);
	Edge edge29(787 , 5, 7);
	Edge edge30(214 , 6, 7);
	Edge edge31(888 , 8, 7);


	Edge edge32(864, 4 , 8);
	Edge edge33(888, 7 , 8);
	Edge edge34(661, 9 , 8);
	Edge edge35(781, 10, 8);
	Edge edge36(810, 11, 8);


	Edge edge37(1187, 11, 9);
	Edge edge38(661, 8 , 9);


	Edge edge39(1435, 2, 10);
	Edge edge40(496 , 4, 10);
	Edge edge41(781 , 8, 10);
	Edge edge42(239 , 11, 10);


	Edge edge43(239 , 10, 11);
	Edge edge44(1187, 9 , 11);
	Edge edge45(810 , 8 , 11);


	// Vector of edge objects
	vector<Edge> edges =
	{
		edge0, edge1, edge2, edge3, edge4, edge5, edge6, edge7, edge8, edge9,
		edge10, edge11, edge12, edge13, edge14, edge15, edge16, edge17, edge18,
		edge19, edge20, edge21, edge22, edge23, edge24, edge25, edge26, edge27,
		edge28, edge29, edge30, edge31, edge32, edge33, edge34, edge35, edge36,
		edge37, edge38, edge39, edge40, edge41, edge42, edge43, edge44, edge45
	};


	// Adjacency matrix initialized with the vector of edges
	Graph graph(edges, 12);

	// OUTPUT -- class header and assignment description
	cout << printHeader("Hai-Trang Nguyen", "BFS", 'A', 10);
	cout << endl;
	cout << "This program will:" << endl;
	cout << "1. Store a set of vertices which create edges and their weights in"
			"\n   an adjacent matrix structure." << endl;
	cout << "2. Displays the vertices with their adjacent vertices in the adjacent"
			"\n   matrix." << endl;
	cout << "3. Perform a breadth first search (BFS) starting from Dallas, choosing"
			"\n   the edge with the shortest distance." << endl;
	cout << "4. Displays the result of the BFS (discovery and cross edges) and the"
			"\n   total miles traveled on the discovery edges" << endl << endl << endl;


	// OUTPUT -- displays the adjacency matrix
	cout << "ADJACENCY MATRIX:" << endl << endl;
	graph.printGraph();

	cout << endl << endl << endl;

	// PROCESSING & OUTPUT -- performs a breadth first search starting from
	//                        index 10 (Dallas) and displays the result as well
	//                        as the discovery and cross edges
	cout << "BREADTH FIRST SEARCH (BFS):" << endl << endl;
	graph.BFS(10);


	return 0;
}


