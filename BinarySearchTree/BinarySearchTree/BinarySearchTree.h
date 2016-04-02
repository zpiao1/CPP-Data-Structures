#pragma once
#ifndef _BINARY_SEARCH_TREE_H
#include <iostream>
using namespace std;
class node {
	friend class BinarySearchTree;
private:
	int data = -1;
	node *left = nullptr;
	node *right = nullptr;
public:
	node() = default;
	node(int Data) :
		data(Data), left(nullptr), right(nullptr) {}
	int getData() const;
};
class BinarySearchTree {
private:
	node *root = nullptr;
	void recInsert(node **ptrRoot, int data);
	node *recSearch(node *root, int data);
	void recRemoveNode(node **ptrRoot, int data);
	void inOrderTraversal(node *root);
	node *findSuccessor(node *Node);
	node *recFindMin(node *root);
public:
	BinarySearchTree() = default;
	bool isEmpty() const;
	void insert(int data);
	void recInsert(int data);
	node *search(int data);
	node *recSearch(int data);
	void removeNode(int data);
	void recRemoveNode(int data);
	void inOrderTraversal();
	int getRootData() const;
};
#endif // !_BINARY_SEARCH_TREE_H
