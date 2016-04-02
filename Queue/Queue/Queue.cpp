#include "Queue.h"

void node::setData(int Data)
{
	data = Data;
}

void node::setNext(node * Next)
{
	next = Next;
}

int node::getData() const
{
	return data;
}

node * node::getNext() const
{
	return next;
}

int Queue::peek()
{
	return front->getData();
}

bool Queue::isEmpty()
{
	return itemCount == 0;
}

bool Queue::isFull()
{
	return itemCount == MAX;
}

void Queue::insert(int data)
{
	if (!isFull()) {
		node *newNode = new node(data, nullptr);
		if (isEmpty())
			front = newNode;
		else 
			rear->setNext(newNode);
		rear = newNode;
		itemCount++;
	}
}

int Queue::removeData()
{
	node *temp = front;
	int data = temp->getData();
	front = front->getNext();
	delete temp;
	itemCount--;
	if (isEmpty())
		rear = nullptr;
	return data;
}
