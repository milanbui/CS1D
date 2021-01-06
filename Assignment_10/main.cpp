/*******************************************************************************
 * AUTHOR		  : Milan Bui & Hai-Tran Nguyen
 * #
 * ASSIGNMENT #10A: DFS
 * CLASS		  : CS 1D
 * SECTION		  : MW: 2:30p - 4:50p
 * DUE DATE		  : 17 April 2019
 ******************************************************************************/
#include "graph.h"
#include "printHeader.h"

int main()
{
	const int NUM = 12;

	vector<Edge> edges =
	{
			{0, 1, 807}, {0, 2, 1331}, {0, 3, 2097}, {1, 4, 381}, {4, 2, 1015},
			{4, 5, 1663}, {4, 6, 1435}, {1, 2, 1267}, {2, 3, 1003}, {3, 5, 533},
			{5, 2, 599}, {5, 6, 496}, {6, 7, 239}, {6, 9, 781}, {5, 9, 864},
			{5, 10, 1260}, {3, 10, 787}, {3, 11, 983}, {7, 9, 810}, {7, 8, 1187},
			{8, 9, 661}, {9, 10, 888}, {10, 11, 214}
	};

	Graph graph(edges, NUM);

	cout << printHeader("Hai-Trang Nguyen", "DFS", 'A', 10);
	cout << endl;
	cout << "This program will:" << endl;
	cout << "1. Store a set of vertices which create edges and their weights in"
			"\n   an adjacent list structure." << endl;
	cout << "2. Displays the vertices with their adjacent vertices in the adjacent"
			"\n   list." << endl;
	cout << "3. Perform a depth first search (BFS) starting from Dallas, choosing"
			"\n   the edge with the shortest distance." << endl;
	cout << "4. Displays the result of the DFS (discovery and back edges) and the"
			"\n   total miles traveled on the discovery edges" << endl << endl << endl;

	cout << left << setw(125) << setfill('*') << "*" << endl;
	cout << setfill(' ');


	cout << "Adjacent List Structure:" << endl;
	cout << left << setw(125) << setfill('-') << "-" << endl;
	cout << setfill(' ');
	graph.printGraph(NUM);
	cout << endl << endl;

	cout << left << setw(125) << setfill('*') << "*" << endl;
	cout << setfill(' ');

	cout << "DFS Edges" << endl;
	cout << left << setw(125) << setfill('-') << "-" << endl;
	cout << setfill(' ');
	graph.DFS(NUM, 6);
}


