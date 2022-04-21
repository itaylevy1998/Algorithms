#include "Edge.h"

Edge::Edge(int u, int vertex, int weight, Edge* next, Edge* prev)
{
	this->u = u;
	this->v = vertex;
	this->weight = weight;
	this->next = next;
	this->prev = prev;
}

Edge::~Edge()
{
}

bool Edge::isHead()
{
	return prev == nullptr;
}

bool Edge::isTail()
{
	return next == nullptr;
}

Edge* Edge::getNext()
{
	return next;
}

Edge* Edge::getPrev()
{
	return prev;
}

int Edge::getVertex()
{
	return v;
}

void Edge::setNext(Edge* next)
{
	this->next = next;
}

void Edge::setPrev(Edge* prev)
{
	this->prev = prev;
}
