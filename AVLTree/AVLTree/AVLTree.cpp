#include "AVLTree.h"

int AVLTree::getHeight(node * root)
{
	return (root ? root->height : -1);
}

void AVLTree::rotateLeft(node ** ptrRoot)
{
	if (!*ptrRoot)
		return;
	node *pivot = (*ptrRoot)->right;
	(*ptrRoot)->right = pivot->left;
	pivot->left = *ptrRoot;
	*ptrRoot = pivot;
}

void AVLTree::rotateRight(node ** ptrRoot)
{
	if (!*ptrRoot)
		return;
	node *pivot = (*ptrRoot)->left;
	(*ptrRoot)->left = pivot->right;
	pivot->right = *ptrRoot;
	*ptrRoot = pivot;
}

node * AVLTree::findSuccessor(node * root)
{
	node *curr = root;
	if (curr) {
		curr = curr->right;
		while (curr && curr->left)
			curr = curr->left;
	}
	return curr;
}

void AVLTree::rebalance(node ** ptrRoot)
{
	if (!*ptrRoot)
		return;
	node *left = (*ptrRoot)->left;
	node *right = (*ptrRoot)->right;
	if (getHeight(left) > 1 + getHeight(right)) {
		if (getHeight(left->left) < getHeight(left->right))
			rotateLeft(&left);
		rotateRight(ptrRoot);
	} else if (getHeight(right) > 1 + getHeight(left)) {
		if (getHeight(right->right) < getHeight(right->left))
			rotateRight(&right);
		rotateLeft(ptrRoot);
	}
	update((*ptrRoot)->right);
	update((*ptrRoot)->left);
	update(*ptrRoot);
}

void AVLTree::update(node * root)
{
	if (root)
		root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

void AVLTree::inOrderTraversal(node * root)
{
	if (root) {
		inOrderTraversal(root->left);
		std::cout << root->data << ' ';
		inOrderTraversal(root->right);
	}
}

node * AVLTree::search(node * root, int data)
{
	if (!root)
		return nullptr;
	if (data < root->data)
		return search(root->left, data);
	else if (data > root->data)
		return search(root->right, data);
	else
		return root;
}

void AVLTree::insert(node ** ptrRoot, int data)
{
	if (!(*ptrRoot))
		*ptrRoot = new node(data);
	else if (data < (*ptrRoot)->data)
		insert(&((*ptrRoot)->left), data);
	else if (data > (*ptrRoot)->data)
		insert(&((*ptrRoot)->right), data);
	else
		return;
	rebalance(ptrRoot);
}

void AVLTree::removeNode(node ** ptrRoot, int data)
{
	if (!(*ptrRoot))
		return;
	if (data < (*ptrRoot)->data)
		removeNode(&((*ptrRoot)->left), data);
	else if (data > (*ptrRoot)->data)
		removeNode(&((*ptrRoot)->right), data);
	else {
		if ((*ptrRoot)->left && (*ptrRoot)->right) {
			node *successor = findSuccessor(*ptrRoot);
			(*ptrRoot)->data = successor->data;
			removeNode(&((*ptrRoot)->right), successor->data);
		} else {
			node *temp = *ptrRoot;
			*ptrRoot = ((*ptrRoot)->left ? (*ptrRoot)->left : (*ptrRoot)->right);
			delete temp;
		}
	}
	rebalance(ptrRoot);
}

bool AVLTree::isEmpty() const
{
	return !root;
}

void AVLTree::insert(int data)
{
	insert(&root, data);
}

void AVLTree::removeNode(int data)
{
	removeNode(&root, data);
}

void AVLTree::inOrderTraversal()
{
	inOrderTraversal(root);
}

node * AVLTree::search(int data)
{
	return search(root, data);
}

int AVLTree::getRootData() const
{
	return (root ? root->data : -1);
}
