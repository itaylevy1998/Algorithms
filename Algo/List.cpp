#include "List.h"

//constructor
List::List(int vertex)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
	this->u = vertex;
}
//destructor
List::~List()
{
	Edge* curr = head, *next;
	while (curr != nullptr) {
		next = curr->getNext();
		delete(curr);
		curr = next;
	}
}

Edge* List::getHead()
{
	return head;
}
//checks if the list is empty. returns true if it is.
bool List::isEmpty()
{
	return (head == nullptr);
}
// creates a node and insert it to the end of the list.
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
// creates a node and insert it to the start of the list.
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

// removes a given edge from the list.
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
// finding an egde in the list using it's value. returns true if the edge exists.
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
// finding an egde in the list using it's value. returns true if the edge exists.
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
	throw(1);
	/*std::cout << "Invalid Input!";
	exit(1);*/
	//if we got here that means the edge doesn't exist in the graph
	
}





