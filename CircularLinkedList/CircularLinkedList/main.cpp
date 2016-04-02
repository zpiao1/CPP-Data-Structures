#include "CircularLinkedList.h"
using namespace std;
int main()
{
	CircularLinkedList list;
	list.insertFirst(1, 10);
	list.insertFirst(2, 20);
	list.insertFirst(3, 30);
	list.insertFirst(4, 1);
	list.insertFirst(5, 40);
	list.insertFirst(6, 56);

	cout << "Original List: ";
	list.printList();
	node *newHead = list.getHead()->getNext();
	list.setHead(newHead);
	list.printList();

	while (!list.isEmpty()) {
		node *temp = list.deleteFirst();
		cout << endl << "Deleted value: ";
		cout << "(" << temp->getKey() << ", " << temp->getData() << ") ";
		delete temp;
	}

	cout << endl << "List after deleting all items: ";
	list.printList();

	return 0;
}