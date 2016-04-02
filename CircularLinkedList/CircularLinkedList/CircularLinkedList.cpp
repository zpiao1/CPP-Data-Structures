#include "CircularLinkedList.h"

inline int node::getKey() const
{
	return key;
}

inline int node::getData() const
{
	return data;
}

inline node * node::getNext() const
{
	return next;
}

inline void node::setKey(int Key)
{
	key = Key;
}

inline void node::setData(int Data)
{
	data = Data;
}

inline void node::setNext(node * Next)
{
	next = Next;
}

inline bool CircularLinkedList::isEmpty() const
{
	return head == nullptr;
}

int CircularLinkedList::length() const
{
	int length = 0;
	node *current = head;
	if (head)
		do {
			length++;
			current = current->getNext();
		} while (current->getNext() != head);
	return length;
}

void CircularLinkedList::insertFirst(int key, int data)
{
	// create a link
	node *link = new node(key, data);
	node *current = head;

	if (isEmpty())
		link->setNext(link);
	else {
		// point it to old first node
		link->setNext(head);
		while (current && current->getNext() != head)
			current = current->getNext();
		current->setNext(link);
	}
	head = link;
}

node * CircularLinkedList::deleteFirst()
{
	node *tempLink = head;
	node *current = head;

	if (!head)
		return nullptr;
	if (head->getNext() == head)
		head = nullptr;
	else {
		while (current && current->getNext() != head)
			current = current->getNext();
		head = head->getNext();
		current->setNext(head);
	}
	return tempLink;
}

void CircularLinkedList::printList() const
{
	node *ptr = head;
	std::cout << std::endl << "[ ";
	if (head)
		do {
			std::cout << "(" << ptr->getKey() << ", " << ptr->getData() << ") ";
			ptr = ptr->getNext();
		} while (ptr != head);
	std::cout << " ]";
}

void CircularLinkedList::setHead(node * Head)
{
	head = Head;
}

node * CircularLinkedList::getHead() const
{
	return head;
}
