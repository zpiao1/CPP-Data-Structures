#include "Graph.h"
using namespace std;
int main()
{
	Graph g;
	g.addVertex('S');	// 0
	g.addVertex('A');   // 1
	g.addVertex('B');   // 2
	g.addVertex('C');   // 3
	g.addVertex('D');   // 4

	g.initAdjMatrix();

	g.addEdge(0, 1);    // S - A
	g.addEdge(0, 2);    // S - B
	g.addEdge(0, 3);    // S - C
	g.addEdge(1, 4);    // A - D
	g.addEdge(2, 4);    // B - D
	g.addEdge(3, 4);    // C - D

	cout << "Depth First Traversal: ";
	g.depthFirstSearch();
	return 0;
}