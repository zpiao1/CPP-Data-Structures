#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H
#include <iostream>
#include <cstddef>
static const size_t MAX = 6;
class node {
private:
	int data = 0;
	node *next = nullptr;
public:
	node(int Data, node *Next) :
		data(Data), next(Next) {}
	node() = default;
	void setData(int Data);
	void setNext(node *Next);
	int getData() const;
	node *getNext() const;
};

class Queue {
private:
	node *front = nullptr;
	node *rear = nullptr;
	size_t itemCount = 0;
public:
	int peek();
	bool isEmpty();
	bool isFull();
	void insert(int data);
	int removeData();
};
#endif