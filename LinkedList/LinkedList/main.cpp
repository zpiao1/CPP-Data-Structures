#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList list;
	list.insertFirst(1, 10);
	list.insertFirst(2, 20);
	list.insertFirst(3, 30);
	list.insertFirst(4, 1);
	list.insertFirst(5, 40);
	list.insertFirst(6, 56);

	cout << "Original List: ";

	//print list
	list.printList();

	while (!list.isEmpty()) {
		node *temp = list.deleteFirst();
		cout << endl << "Deleted value:";
		cout << "(" << temp->getKey() << ", " << temp->getData() << ") ";
		delete temp;
	}

	cout << endl << "List after deleting all items: ";
	list.printList();
	list.insertFirst(1, 10);
	list.insertFirst(2, 20);
	list.insertFirst(3, 30);
	list.insertFirst(4, 1);
	list.insertFirst(5, 40);
	list.insertFirst(6, 56);
	cout << endl << "Restored List: ";
	list.printList();
	cout << endl;

	node *foundLink = list.find(4);

	if (foundLink) {
		cout << "Element found: ";
		cout << "(" << foundLink->getKey() << ", " << foundLink->getData() << ") " << endl;
	}
	else
		cout << "Element not found." << endl;

	list.deleteByKey(4);
	cout << "List after deleting an item: ";
	list.printList();
	cout << endl;
	foundLink = list.find(4);

	if (foundLink) {
		cout << "Element found: ";
		cout << "(" << foundLink->getKey() << ", " << foundLink->getData() << ") " << endl;
	}
	else
		cout << "Element not found." << endl;

	list.sort();

	cout << "List after sorting the data: ";
	list.printList();

	list.reverse();
	cout << endl << "List after reversing the data: ";
	list.printList();

	return 0;
}