#include "LinkedList.h"
int node::getData() const
{
	return data;
}
int node::getKey() const
{
	return key;
}
void LinkedList::printList()
{
	node *ptr = head;
	std::cout << std::endl << "[ ";

	// start from the beginning
	while (ptr) {
		std::cout << "(" << ptr->key << ", " << ptr->data << ") ";
		ptr = ptr->next;
	}

	std::cout << " ]";
}

void LinkedList::insertFirst(int key, int data)
{
	// create a link
	node *link = new node(key, data);
	// point it to old first node
	link->next = head;
	// point first to new first node
	head = link;
}

node* LinkedList::deleteFirst()
{
	// save reference to first link
	node *tempLink = head;

	// if list is empty
	if (!head)
		return nullptr;
	// mark next to first link as first
	head = head->next;

	// return the deleted link
	return tempLink;
}

bool LinkedList::isEmpty()
{
	return head == nullptr;
}

size_t LinkedList::length()
{
	size_t length = 0;
	node *current = head;

	for (current = head; current != nullptr; current = current->next)
		++length;

	return length;
}

node * LinkedList::find(int key)
{
	// start from the first link
	node *current = head;

	// if list is empty
	if (!head)
		return nullptr;

	// navigate through list
	while (current->key != key) {
		// if it is last node
		if (!(current->next))
			return nullptr;
		else
			// go to next link
			current = current->next;
	}

	// if data found, return the current link
	return current;
}

node* LinkedList::deleteByKey(int key)
{
	// start from the first link
	node *current = head;
	node *previous = nullptr;

	// if list is empty
	if (!head)
		return nullptr;

	// navigate through list
	while (current->key != key) {
		// if it is last node
		if (!(current->next))
			return nullptr;
		else {
			// store reference to current link
			previous = current;
			// move to next link
			current = current->next;
		}
	}

	// found a match, update the link
	if (current == head)
		// change first to point to next link
		head = head->next;
	else
		// by pass the current link
		previous->next = current->next;
	return current;
}

void LinkedList::sort()
{
	size_t i, j, k;
	int tempKey, tempData;
	node *current, *next;

	size_t size = length();
	k = size;

	for (i = 0; i != size - 1; ++i, --k) {
		current = head;
		next = head->next;

		for (j = 1; j != k; ++j) {
			if (current->data > next->data) {
				tempData = current->data;
				current->data = next->data;
				next->data = tempData;

				tempKey = current->key;
				current->key = next->key;
				next->key = tempKey;
			}
			current = current->next;
			next = next->next;
		}
	}
}

void LinkedList::reverse()
{
	node *prev = nullptr;
	node *current = head;
	node *next;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}
