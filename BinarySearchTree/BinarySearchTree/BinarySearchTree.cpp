#include "BinarySearchTree.h"

void BinarySearchTree::recInsert(node ** ptrRoot, int data)
{
	if (!(*ptrRoot))
		*ptrRoot = new node(data);
	else if ((*ptrRoot)->data > data)
		recInsert(&((*ptrRoot)->left), data);
	else if ((*ptrRoot)->data < data)
		recInsert(&((*ptrRoot)->right), data);
}

node * BinarySearchTree::recSearch(node * root, int data)
{
	if (!root) {
		cerr << "The tree is empty!" << endl;
		return nullptr;
	}
	if (root->data > data)
		return recSearch(root->left, data);
	else if (root->data < data)
		return recSearch(root->right, data);
	else
		return root;
}

void BinarySearchTree::recRemoveNode(node ** ptrRoot, int data)
{
	if (!(*ptrRoot)) {
		cerr << "The node is not found!" << endl;
		return;
	}
	if ((*ptrRoot)->data < data)
		recRemoveNode(&((*ptrRoot)->right), data);
	else if ((*ptrRoot)->data > data)
		recRemoveNode(&((*ptrRoot)->left), data);
	else {
		node *toBeRemoved;
		if ((*ptrRoot)->left && (*ptrRoot)->right) {
			toBeRemoved = recFindMin((*ptrRoot)->right);
			(*ptrRoot)->data = toBeRemoved->data;
			recRemoveNode(&((*ptrRoot)->right), toBeRemoved->data);
		} else {
			toBeRemoved = *ptrRoot;
			*ptrRoot = ((*ptrRoot)->left ? (*ptrRoot)->left : (*ptrRoot)->right);
			delete toBeRemoved;
		}
	}
}

void BinarySearchTree::inOrderTraversal(node * root)
{
	if (root) {
		inOrderTraversal(root->left);
		cout << root->data << ' ';
		inOrderTraversal(root->right);
	}
}

node * BinarySearchTree::findSuccessor(node * Node)
{
	if (!(Node->right))
		return nullptr;
	Node = Node->right;
	while (Node->left)
		Node = Node->left;
	return Node;
}

node * BinarySearchTree::recFindMin(node * root)
{
	return (root->left ? recFindMin(root->left) : root);
}

bool BinarySearchTree::isEmpty() const
{
	return !root;
}

void BinarySearchTree::insert(int data)
{
	node *newNode = new node(data);
	if (isEmpty())
		root = newNode;
	else
	{
		node *curr = root;
		while (curr) {
			if (curr->data > data)
				if (curr->left)
					curr = curr->left;
				else {
					curr->left = newNode;
					return;
				}
			else if (curr->data < data)
				if (curr->right)
					curr = curr->right;
				else {
					curr->right = newNode;
					return;
				}
		}
	}
}

void BinarySearchTree::recInsert(int data)
{
	recInsert(&root, data);
}

node * BinarySearchTree::search(int data)
{
	node *curr = root;
	while (curr) {
		if (curr->data == data)
			return curr;
		else if (curr->data > data)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return nullptr;
}

node * BinarySearchTree::recSearch(int data)
{
	return recSearch(root, data);
}

void BinarySearchTree::removeNode(int data)
{
	node *curr = root;
	node *parent = nullptr;
	if (!root) {
		cerr << "Tree is empty!" << endl;
		return;
	}
	// The node if the root
	if (root->data == data) {
		root = (root->left ? root->left : root->right);
		delete curr;
		return;
	}
	while (curr) {
		if (curr->data != data) {
			parent = curr;
			curr = (curr->data > data ? curr->left : curr->right);
		} else {
			if (curr->left && curr->right) {
				auto replace = findSuccessor(curr);
				curr->data = replace->data;
				parent = curr;
				curr = curr->right;
				while (curr) {
					if (curr->data != replace->data) {
						parent = curr;
						curr = (curr->data > replace->data ? curr->left : curr->right);
					} else {
						if (curr == parent->left)
							parent->left = (curr->right ? curr->right : curr->left);
						else
							parent->right = (curr->right ? curr->right : curr->left);
						break;
					}
				}
			} else {
				if (curr == parent->left)
					parent->left = (curr->right ? curr->right : curr->left);
				else
					parent->right = (curr->left ? curr->left : curr->right);
			}
			delete curr;
			return;
		}
	}
	cerr << "The node is not found!" << endl;
}

void BinarySearchTree::recRemoveNode(int data)
{
	return recRemoveNode(&root, data);
}

void BinarySearchTree::inOrderTraversal()
{
	inOrderTraversal(root);
}

int BinarySearchTree::getRootData() const
{
	return root->data;
}

int node::getData() const
{
	return data;
}
