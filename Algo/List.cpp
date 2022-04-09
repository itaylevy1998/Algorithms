#include "List.h"

List::List()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

List::~List()
{
}

bool List::isEmpty()
{
	return (head == nullptr);
}

void List::insertToEnd(int vertex, int weight)
{
	Edge* newEdge = new Edge(vertex, weight, nullptr, tail);
	if (isEmpty()) 
		head = tail = newEdge;
	else
	{
		tail->setNext(newEdge);
		tail = newEdge;
	}
	size++;
}

void List::insertToStart(int vertex, int weight) {
	Edge* newEdge = new Edge(vertex, weight, head, nullptr);
	if (isEmpty())
		head = tail = newEdge;
	else
	{
		head->setPrev(newEdge);
		head = newEdge;
	}
	size++;
}


void List::removeEdge(Edge* toRemove)
{
	if (isEmpty())
		return;
	else if (size == 1){
		head = tail = nullptr;
	}
	else if (toRemove->isHead() ){
		head = toRemove->getNext();
		head->setPrev(nullptr);
	}
	else if (toRemove->isTail()) {
		tail = toRemove->getPrev();
		tail->setNext(nullptr);
	}
	else {
		toRemove->getPrev()->setNext(toRemove->getNext());
		toRemove->getNext()->setPrev(toRemove->getPrev());
	}
	delete(toRemove);
	size--;
}





