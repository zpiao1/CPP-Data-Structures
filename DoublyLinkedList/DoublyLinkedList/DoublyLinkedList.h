#pragma once
#ifndef _DOUBLY_LINKED_LIST_H
#define	_DOUBLY_LINKED_LIST_H
#include <iostream>
#include <cstddef>
class node {
	friend class DoublyLinkedList;
private:
	int data = 0;
	int key = 0;
	node *next = nullptr;
	node *prev = nullptr;
public:
	// constructors
	// default constructor
	node() = default;
	node(int Key, int Data) :
		data(Data), key(Key), next(nullptr), prev(nullptr) {}
	// member functions
	inline int getKey() const;
	inline int getData() const;
};

class DoublyLinkedList {
private:
	node *head = nullptr;
	node *last = nullptr;
public:
	// default constructor
	DoublyLinkedList() = default;
	// member functions
	inline bool isEmpty();
	size_t length();
	void displayForward();
	void displayBackward();
	void insertFirst(int key, int data);
	void insertLast(int key, int data);
	node *deleteFirst();
	node *deleteLast();
	node *deleteByKey(int key);
	bool insertAfter(int key, int newKey, int data);
};
#endif