#pragma once
#ifndef _STACK_H
#define _STACK_H
#include <iostream>
#include <cstddef>
#define MAXSIZE 8
class node {
private:
	node *next = nullptr;
	int data = 0;
public:
	node() = default;
	node(node* Next, int Data) :
		next(Next), data(Data) {}
	node* getNext() const;
	int getData() const;
	void setNext(node *Next);
	void setData(int Data);
};

class Stack {
private:
	node *top = nullptr;
	size_t size = 0;
public:
	Stack() = default;
	bool isEmpty();
	bool isFull();
	int peek();
	int pop();
	void push(int data);
};
#endif