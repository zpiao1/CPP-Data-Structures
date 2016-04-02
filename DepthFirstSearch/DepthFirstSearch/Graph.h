#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H
#include <stack>
#include <iostream>
#include <vector>
class Vertex {
	friend class Graph;
private:
	char label = '\0';
	bool visited = false;
public:
	Vertex() = default;
	Vertex(char Label) :
		label(Label), visited(false) {}
};
class Graph {
private:
	std::stack<size_t> vertexStack;
	std::vector<Vertex> lstVertices;
	std::vector<std::vector<int>> adjMatrix;
public:
	Graph() = default;
	void addVertex(char label);
	void addEdge(size_t start, size_t end);
	void displayVertex(size_t vertexIndex);
	size_t getAdjUnvisitedVertex(size_t vertexIndex);
	void depthFirstSearch();
	void initAdjMatrix();
};
#endif
