#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Vertex {
	friend class Graph;
	friend void breadthFirstSearch(Graph &g);
private:
	char label = '\0';
	bool visited = false;
public:
	Vertex() = default;
	Vertex(char Label) : label(Label), visited(false) {}

};
class Graph {
	friend void breadthFirstSearch(Graph &g);
private:
	queue<size_t> vertexQueue;
	vector<vector<int>> adjMatrix;
	vector<Vertex> lstVertices;
public:
	void addVertex(char label);
	void addEdge(size_t start, size_t end);
	void displayVertex(size_t vertexIndex);
	size_t getAdjUnvisitedVertex(size_t vertexIndex);
	void initAdjMatrix();
	Graph() = default;
};
void breadthFirstSearch(Graph &g);
#endif // !_GRAPH_H
