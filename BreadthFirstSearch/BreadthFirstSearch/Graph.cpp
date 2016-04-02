#include "Graph.h"

void Graph::addVertex(char label)
{
	Vertex vertex(label);
	lstVertices.push_back(vertex);
}

void Graph::addEdge(size_t start, size_t end)
{
	adjMatrix[start][end] = adjMatrix[end][start] = 1;
}

void Graph::displayVertex(size_t vertexIndex)
{
	cout << lstVertices[vertexIndex].label << ' ';
}

size_t Graph::getAdjUnvisitedVertex(size_t vertexIndex)
{
	for (size_t i = 0; i < lstVertices.size(); ++i)
		if (adjMatrix[vertexIndex][i] == 1 && !(lstVertices[i].visited))
			return i;
	return -1;
}

void Graph::initAdjMatrix()
{
	for (size_t i = 0; i != lstVertices.size(); ++i)
		adjMatrix.push_back(vector<int>(lstVertices.size(), 0));
}

