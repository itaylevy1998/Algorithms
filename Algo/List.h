#pragma once
#include "Edge.h"
#include <iostream>

class List {
private:
	Edge* head;
	Edge* tail;
	int size;
	int u;
public:
	List(int vertex);
	~List();
	Edge* getHead();
	bool isEmpty();
	void insertToEnd(int u,int vertex, int weight);
	void insertToStart(int u, int vertex, int weight);
	void removeEdge(Edge* toRemove);
	void findEdgeAndRemoveIt(int v);
	bool findEdge(int v);
};
