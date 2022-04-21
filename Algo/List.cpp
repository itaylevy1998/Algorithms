#include "List.h"

List::List(int vertex)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
	this->v = vertex;
}

List::~List()
{
	Edge* curr = head, *next;
	while (curr != nullptr) {
		next = curr->getNext();
		delete(curr);
		curr = next;
	}
}

bool List::isEmpty()
{
	return (head == nullptr);
}

void List::insertToEnd(int u,int vertex, int weight)
{
	Edge* newEdge = new Edge(u,vertex, weight, nullptr, tail);
	if (isEmpty()) 
		head = tail = newEdge;
	else
	{
		tail->setNext(newEdge);
		tail = newEdge;
	}
	size++;
}

void List::insertToStart(int u, int vertex, int weight) {
	Edge* newEdge = new Edge(u, vertex, weight, head, nullptr);
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

bool List::findEdge(int v)
{
	Edge* curr = head;
	while (curr != nullptr) {
		if (curr->getV() == v)
			return true;
		curr = curr->getNext();
	}
	return false;
}

void List::findEdgeAndRemoveIt(int v)
{
	Edge* curr = head;
	while (curr != nullptr) {
		if (curr->getV() == v) {
			removeEdge(curr);
			return;
		}
		curr = curr->getNext();
	}
	//if we got here that means the edge doesn't exist in the graph
	
}





