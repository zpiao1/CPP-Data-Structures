#include "BinarySearchTree.h"
#include <array>
using namespace std;
int main()
{
	int i;
	BinarySearchTree bst;
	array<int, 5> array = { 27,14,35,10,42 };
	for (i = 0; i < 5; ++i)
		bst.insert(array[i]);

	i = 31;
	node *temp = bst.search(i);
	if (temp)
		cout << "[" << temp->getData() << "] Element found." << endl;
	else
		cout << "[ x ] Element not found (" << i << ")." << endl;

	i = 15;
	temp = bst.search(i);
	if (temp)
		cout << "[" << temp->getData() << "] Element found." << endl;
	else
		cout << "[ x ] Element not found (" << i << ")." << endl;

	cout << endl << "Preorder traversal: ";
	bst.pre_order_traversal();

	cout << endl << "Iterative preorder traversal: ";
	bst.iterative_pre_order_traversal();

	cout << endl << "Inorder traversal: ";
	bst.inorder_traversal();

	cout << endl << "Iterative irorder traversal: ";
	bst.iterative_inorder_traversal();

	cout << endl << "Post order traversal: ";
	bst.post_order_traversal();

	cout << endl << "Iterative post order traversal: ";
	bst.iterative_post_order_traversal();
	return 0;
}