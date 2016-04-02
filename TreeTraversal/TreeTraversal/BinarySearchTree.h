#pragma once
#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H
#include <iostream>
#include <stack>
using namespace std;
class node {
	friend class BinarySearchTree;
private:
	int data = -1;
	node *leftChild = nullptr;
	node *rightChild = nullptr;
public:
	node() = default;
	node(int Data) :
		data(Data), leftChild(nullptr), rightChild(nullptr) {}
	int getData() const;
};

class BinarySearchTree {
private:
	node *root = nullptr;
	void pre_order(node *curr) const;
	void in_order(node *curr) const;
	void post_order(node *curr) const;
public:
	BinarySearchTree() = default;
	void insert(int data);
	node *search(int data) const;
	void pre_order_traversal() const;
	void inorder_traversal() const;
	void post_order_traversal() const;
	void iterative_pre_order_traversal() const;
	void iterative_inorder_traversal() const;
	void iterative_post_order_traversal() const;
};
#endif // !_BINARY_SEARCH_TREE_H
