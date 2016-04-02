#pragma once
#ifndef _AVL_TREE_H
#define _AVL_TREE_H
#include <iostream>
#include <algorithm>
class node {
	friend class AVLTree;
private:
	int height = 0;
	int data = -1;
	node *left = nullptr;
	node *right = nullptr;
public:
	node() = default;
	node(int Data) :
		data(Data), height(0), left(nullptr), right(nullptr) {}
};
class AVLTree {
private:
	node *root = nullptr;
	// Auxiliary functions
	int getHeight(node *root);
	void rotateLeft(node **ptrRoot);
	void rotateRight(node **ptrRoot);
	node *findSuccessor(node *root);
	void rebalance(node **ptrRoot);
	void update(node *root);
	// Overloaded private functions
	void inOrderTraversal(node *root);
	node *search(node *root, int data);
	void insert(node **ptrRoot, int data);
	void removeNode(node **ptrRoot, int data);
public:
	AVLTree() = default;
	bool isEmpty() const;
	void insert(int data);
	void removeNode(int data);
	void inOrderTraversal();
	node *search(int data);
	int getRootData() const;
};
#endif // !_AVL_TREE_H
