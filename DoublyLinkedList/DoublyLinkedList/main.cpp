#include "DoublyLinkedList.h"
using namespace std;
int main()
{
	DoublyLinkedList list;
	list.insertFirst(1, 10);
	list.insertFirst(2, 20);
	list.insertFirst(3, 30);
	list.insertFirst(4, 1);
	list.insertFirst(5, 40);
	list.insertFirst(6, 56);

	cout << "List (First to Last): ";
	list.displayForward();

	cout << endl << "List (Last to First): ";
	list.displayBackward();

	cout << endl << "List, after deleteing first recored: ";
	list.deleteFirst();
	list.displayForward();

	cout << endl << "List, after deleting last record: ";
	list.deleteLast();
	list.displayForward();

	cout << endl << "List, insert after key(4): ";
	list.insertAfter(4, 7, 13);
	list.displayForward();

	cout << endl << "List, after delete key(4): ";
	list.deleteByKey(4);
	list.displayForward();

	while (!list.isEmpty())
		list.deleteFirst();

	return 0;
}