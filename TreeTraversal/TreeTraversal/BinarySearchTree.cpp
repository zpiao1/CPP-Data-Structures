#include "BinarySearchTree.h"

int node::getData() const
{
	return data;
}

void BinarySearchTree::pre_order(node * curr) const
{
	if (curr) {
		cout << curr->data << ' ';
		pre_order(curr->leftChild);
		pre_order(curr->rightChild);
	}
}

void BinarySearchTree::in_order(node * curr) const
{
	if (curr) {
		in_order(curr->leftChild);
		cout << curr->data << ' ';
		in_order(curr->rightChild);
	}
}

void BinarySearchTree::post_order(node * curr) const
{
	if (curr) {
		post_order(curr->leftChild);
		post_order(curr->rightChild);
		cout << curr->data << ' ';
	}
}


void BinarySearchTree::insert(int data)
{
	node *tempNode = new node(data);
	if (!root)
		root = tempNode;
	else {
		node *current = root;
		while (true) {
			// go to left of the tree
			if (data < current->data) {
				if (!(current->leftChild)) {
					current->leftChild = tempNode;
					return;
				} else
					current = current->leftChild;
			} else {	// go to right of the tree
				if (!(current->rightChild)) {
					current->rightChild = tempNode;
					return;
				} else
					current = current->rightChild;
			}
		}
	}
}

node * BinarySearchTree::search(int data) const
{
	node *current = root;
	cout << "Visiting elements: ";
	while (current) {
		cout << current->data << ' ';
		if (current->data > data)
			current = current->leftChild;
		else if (current->data < data)
			current = current->rightChild;
		else
			return current;
	}
	// not found
	return nullptr;
}

void BinarySearchTree::pre_order_traversal() const
{
	pre_order(root);
}

void BinarySearchTree::inorder_traversal() const
{
	in_order(root);
}

void BinarySearchTree::post_order_traversal() const
{
	post_order(root);
}
// If it has an unvisited existing left child, push onto the stack
// Else if it has an unvisited existing right childe, push onto the stack
// Else (all existing children have been visited), pop the current node
// Prinf if all existing children have not been visited
void BinarySearchTree::iterative_pre_order_traversal() const
{
	if (!root)
		return;
	stack<node *> s;
	s.push(root);
	node *curr = nullptr, *parent = nullptr;
	bool visited_left = false, visited_right = false;
	while (!s.empty()) {
		curr = s.top();
		if ((!curr->leftChild || !visited_left) &&
			(!curr->rightChild || !visited_right))
			cout << curr->getData() << ' ';
		if (curr->leftChild && !visited_left) {
			s.push(curr->leftChild);
			visited_right = false;
		}
		else if (curr->rightChild && !visited_right) {
			s.push(curr->rightChild);
			visited_left = false;
		}
		else {
			s.pop();
			if (!s.empty()) {
				parent = s.top();
				visited_right = (curr == parent->rightChild);
				visited_left = true;
			}
		}
	}
}

// Print if only left of existing children has been visited
void BinarySearchTree::iterative_inorder_traversal() const
{
	if (!root)
		return;
	stack<node *> s;
	s.push(root);
	node *curr = nullptr, *parent = nullptr;
	bool visited_left = false, visited_right = false;
	while (!s.empty()) {
		curr = s.top();
		if ((!curr->leftChild || visited_left) &&
			(!curr->rightChild || !visited_right))
			cout << curr->getData() << ' ';
		if (curr->leftChild && !visited_left) {
			s.push(curr->leftChild);
			visited_right = false;
		}
		else if (curr->rightChild && !visited_right) {
			s.push(curr->rightChild);
			visited_left = false;
		}
		else {
			s.pop();
			if (!s.empty()) {
				parent = s.top();
				visited_right = (curr == parent->rightChild);
				visited_left = true;
			}
		}
	}
}

// Print only if all existing children have been visited
void BinarySearchTree::iterative_post_order_traversal() const
{
	if (!root)
		return;
	stack<node *> s;
	s.push(root);
	node *curr = nullptr, *parent = nullptr;
	bool visited_left = false, visited_right = false;
	while (!s.empty()) {
		curr = s.top();
		if ((!curr->leftChild || visited_left) &&
			(!curr->rightChild || visited_right))
			cout << curr->getData() << ' ';
		if (curr->leftChild && !visited_left) {
			s.push(curr->leftChild);
			visited_right = false;
		}
		else if (curr->rightChild && !visited_right) {
			s.push(curr->rightChild);
			visited_left = false;
		}
		else {
			s.pop();
			if (!s.empty()) {
				parent = s.top();
				visited_right = (curr == parent->rightChild);
				visited_left = true;
			}
		}
	}
}
