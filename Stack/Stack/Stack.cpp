#include "Stack.h"

inline node * node::getNext() const
{
	return next;
}

inline int node::getData() const
{
	return data;
}

void node::setNext(node * Next)
{
	next = Next;
}

inline void node::setData(int Data)
{
	data = Data;
}

bool Stack::isEmpty()
{
	return (top == nullptr);
}

bool Stack::isFull()
{
	return size == MAXSIZE;
}

int Stack::peek()
{
	return top->getData();
}

int Stack::pop()
{
	int data = top->getData();
	node *temp = top;
	top = top->getNext();
	delete temp;
	size--;
	return data;
}

void Stack::push(int data)
{
	node *link = new node(top, data);
	top = link;
	size++;
}

