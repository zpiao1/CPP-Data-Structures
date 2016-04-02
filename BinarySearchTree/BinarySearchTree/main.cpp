#include "BinarySearchTree.h"
#include <array>
using namespace std;
int main()
{
	BinarySearchTree iterBST, recBST;
	array<int, 7> array = { 27, 14, 35, 10, 19, 31, 42 };
	for (size_t i = 0; i < 7; ++i)
		iterBST.insert(array[i]);
	for (size_t i = 0; i < 7; ++i)
		recBST.recInsert(array[i]);

	cout << "iterBST: in order traversal: " << endl;
	iterBST.inOrderTraversal();
	cout << endl;
	cout << "recBST: in order traversal:" << endl;
	recBST.inOrderTraversal();
	cout << endl;

	int i = 14;
	node *temp = iterBST.search(i);
	if (temp) {
		cout << "Element found: " << temp->getData() << endl;
		iterBST.removeNode(temp->getData());
		iterBST.inOrderTraversal();
		cout << endl;
	} else
		cout << "Element not found" << endl;

	temp = recBST.recSearch(i);
	if (temp) {
		cout << "Element found: " << temp->getData() << endl;
		recBST.recRemoveNode(temp->getData());
		recBST.inOrderTraversal();
		cout << endl;
	}
	else
		cout << "Element not found" << endl;

	i = 35;
	temp = iterBST.search(i);
	if (temp) {
		cout << "Element found: " << temp->getData() << endl;
		iterBST.removeNode(temp->getData());
		iterBST.inOrderTraversal();
		cout << endl;
	}
	else
		cout << "Element not found" << endl;

	temp = recBST.recSearch(i);
	if (temp) {
		cout << "Element found: " << temp->getData() << endl;
		recBST.recRemoveNode(temp->getData());
		recBST.inOrderTraversal();
		cout << endl;
	}
	else
		cout << "Element not found" << endl;

	while (!iterBST.isEmpty())
		iterBST.removeNode(iterBST.getRootData());
	cout << "iterBST: in order traversal: " << endl;
	iterBST.inOrderTraversal();
	cout << endl;

	while (!recBST.isEmpty())
		recBST.removeNode(recBST.getRootData());
	cout << "recBST: in order traversal: " << endl;
	recBST.inOrderTraversal();
	cout << endl;

	return 0;
}