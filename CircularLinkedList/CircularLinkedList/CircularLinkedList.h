#pragma once
#ifndef _CIRCULAR_LINKED_LIST_H
#define _CIRCULAR_LINKED_LIST_H
#include <iostream>
#include <cstddef>
class node {
private:
	int data = 0;
	int key = 0;
	node *next = nullptr;
public:
	node() = default;
	node(int Key, int Data, node *Next) :
		key(Key), data(Data), next(Next) {}
	node(int Key, int Data) :
		node(Key, Data, nullptr) {}
	inline int getKey() const;
	inline int getData() const;
	inline node *getNext() const;
	inline void setKey(int Key);
	inline void setData(int Data);
	inline void setNext(node *Next);
};
class CircularLinkedList {
private:
	node *head = nullptr;
public:
	CircularLinkedList() = default;
	inline bool isEmpty() const;
	int length() const;
	void insertFirst(int key, int data);
	node *deleteFirst();
	void printList() const;
	void setHead(node *Head);
	node *getHead() const;
};

#endif