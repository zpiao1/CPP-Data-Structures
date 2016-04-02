#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <iostream>
#include <cstddef>
class node {
	friend class LinkedList;
private:
	int data = 0;
	int key = 0;
	node *next = nullptr;
public:
	// constructors
	node(int Key, int Data) :
		data(Data), key(Key), next(nullptr) {}
	// default constructor
	node() = default;
	// member functions
	int getKey() const;
	int getData() const;
};

class LinkedList {
public:
	// constructor
	// default constructor
	LinkedList() :
		head(nullptr) {}
	// member functions
	void printList();
	void insertFirst(int key, int data);
	node* deleteFirst();
	bool isEmpty();
	size_t length();
	node *find(int key);
	node* deleteByKey(int key);
	void sort();
	void reverse();

private:
	node *head = nullptr;
};
#endif