#include "DoublyLinkedList.h"

inline int node::getKey() const
{
	return key;
}

inline int node::getData() const
{
	return data;
}

inline bool DoublyLinkedList::isEmpty()
{
	return head == nullptr;
}

size_t DoublyLinkedList::length()
{
	size_t length = 0;
	node *current;
	for (current = head; current; current = current->next)
		++length;
	return length;
}

void DoublyLinkedList::displayForward()
{
	// start from the beginning
	node *ptr = head;
	// navigate till the end of the list
	std::cout << std::endl << "[ ";
	while (ptr) {
		std::cout << "(" << ptr->getKey() << ", " << ptr->getData() << ") ";
		ptr = ptr->next;
	}
	std::cout << " ]";
}

void DoublyLinkedList::displayBackward()
{
	// start from last
	node *ptr = last;

	// navigate till the start of the list
	std::cout << std::endl << "[ ";
	while (ptr) {
		// print data
		std::cout << "(" << ptr->getKey() << ", " << ptr->getData() << ") ";
		ptr = ptr->prev;
	}
	std::cout << " ]";
}

void DoublyLinkedList::insertFirst(int key, int data)
{
	// create a link
	node *link = new node(key, data);

	if (isEmpty())
		// make it the last link
		last = link;
	else
		// update first prev link
		head->prev = link;
	// point it to old first link
	link->next = head;
	link->prev = nullptr;
	// point first to new first link
	head = link;
}

void DoublyLinkedList::insertLast(int key, int data)
{
	// create a link
	node *link = new node(key, data);

	if (isEmpty())
		// make it the first link
		head = link;
	else
		// make link a new last link
		last->next = link;
	// mark old last node as prev of new link
	link->prev = last;
	link->next = nullptr;
	// point last to new last node
	last = link;
}

node * DoublyLinkedList::deleteFirst()
{
	// save reference to first link
	node *tempLink = head;

	// if only one link
	if (!(head->next))
		last = nullptr;
	else
		head->next->prev = nullptr;
	head = head->next;
	// return the deleted link
	return tempLink;
}

node * DoublyLinkedList::deleteLast()
{
	// save reference to last link
	node *tempLink = last;
	
	// if only one link
	if (!(last->prev))
		head = nullptr;
	else
		last->prev->next = nullptr;

	last = last->prev;
	// return the deleted link
	return tempLink;
}

node * DoublyLinkedList::deleteByKey(int key)
{
	// start from the fisrt link
	node *current = head;
	node *previous = nullptr;

	// if list is empty
	if (!head)
		return nullptr;

	// navigate through list
	while(current->key != key) {
		// if it is last node
		if (current == last)
			return nullptr;
		else {
			// store reference to curent link
			previous = current;
			// move to next link;
			current = current->next;
		}
	}

	// found a match, update the link
	if (current == head)
		// change first to point to next link
		head = head->next;
	else
		// bypass the current link
		current->prev->next = current->next;
	
	if (current == last)
		// change last to point to prev link
		last = current->prev;
	else
		current->next->prev = current->prev;

	return current;
}

bool DoublyLinkedList::insertAfter(int key, int newKey, int data)
{
	// start from the first link
	node *current = head;

	// if list is empty
	if (!head) 
		return false;

	// navigate through list
	while (current->key != key)
		// if it is last node
		if (current == last)
			return false;
		else
			// move to next link
			current = current->next;

	// create a link
	node *newLink = new node(key, data);

	if (current == last) {
		newLink->next = nullptr;
		last = newLink;
	} else {
		newLink->next = current->next;
		current->next->prev = newLink;
	}
	newLink->prev = current;
	current->next = newLink;
	return true;
}

