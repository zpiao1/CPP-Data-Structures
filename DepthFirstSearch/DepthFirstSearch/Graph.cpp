#include "Graph.h"

void Graph::addVertex(char label)
{
	Vertex vertex(label);
	lstVertices.push_back(vertex);
}

void Graph::addEdge(size_t start, size_t end)
{
	adjMatrix[start][end] = 1;
	adjMatrix[end][start] = 1;
}

void Graph::displayVertex(size_t vertexIndex)
{
	std::cout << lstVertices[vertexIndex].label << ' ';
}

size_t Graph::getAdjUnvisitedVertex(size_t vertexIndex)
{
	size_t i;
	for (i = 0; i < lstVertices.size(); ++i)
		if (adjMatrix[vertexIndex][i] == 1 && !lstVertices[i].visited)
			return i;
	return -1;
}

void Graph::depthFirstSearch()
{
	// mark first node as visited
	lstVertices[0].visited = true;
	// display the vertex;
	displayVertex(0);
	// push vertex index in stack
	vertexStack.push(0);

	while (!vertexStack.empty()) {
		// get the unvisited vertex of vertex which is at top of the stack
		auto unvisitedVertex = getAdjUnvisitedVertex(vertexStack.top());

		// no adjacent vertex found
		if (unvisitedVertex == -1)
			vertexStack.pop();
		else {
			lstVertices[unvisitedVertex].visited = true;
			displayVertex(unvisitedVertex);
			vertexStack.push(unvisitedVertex);
		}
	}
	// stack is empty, search is complete, reset the visited flag
	for (size_t i = 0; i < lstVertices.size(); ++i)
		lstVertices[i].visited = false;
}

void Graph::initAdjMatrix()
{
	for (size_t i = 0; i < lstVertices.size(); ++i)
		adjMatrix.push_back(std::vector<int>(lstVertices.size(), 0));
}
