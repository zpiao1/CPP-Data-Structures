#include "Graph.h"
using namespace std;
int main()
{
	Graph g;
	g.addVertex('S');	// 0
	g.addVertex('A');	// 1
	g.addVertex('B');	// 2
	g.addVertex('C');	// 3
	g.addVertex('D');	// 4

	g.initAdjMatrix();
	g.addEdge(0, 1);	// S - A
	g.addEdge(0, 2);	// S - B
	g.addEdge(0, 3);	// S - C
	g.addEdge(1, 4);	// A - D
	g.addEdge(2, 4);	// B - D
	g.addEdge(3, 4);	// C - D

	cout << endl << "Breadth First Search: ";
	breadthFirstSearch(g);
	return 0;
}
void breadthFirstSearch(Graph &g)
{
	// mark first node as visited
	g.lstVertices[0].visited = true;
	// display the vertex
	g.displayVertex(0);
	// insert vertex index in queue
	g.vertexQueue.push(0);

	while (!g.vertexQueue.empty()) {
		// get the unvisited vertex which is at front of the queue
		int tempVertex = g.vertexQueue.front();
		g.vertexQueue.pop();
		size_t unvisitedVertex;
		// no adjacent vertex found
		while ((unvisitedVertex = g.getAdjUnvisitedVertex(tempVertex)) != -1)
		{
			g.lstVertices[unvisitedVertex].visited = true;
			g.displayVertex(unvisitedVertex);
			g.vertexQueue.push(unvisitedVertex);
		}
	}
	// queue is empty, search is complete, reset the visited flag
	for (auto &v : g.lstVertices)
		v.visited = false;
}