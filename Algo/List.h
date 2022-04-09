#pragma once
#include "Edge.h"

class List {
private:
	Edge* head;
	Edge* tail;
	int size;
public:
	List();
	~List();
	bool isEmpty();
	void insertToEnd(int vertex, int weight);
	void insertToStart(int vertex, int weight);
	void removeEdge(Edge* toRemove);
};
