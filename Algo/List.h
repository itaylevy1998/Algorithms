#pragma once
#include "Edge.h"

class List {
private:
	Edge* head;
	Edge* tail;
	int size;
	int v;
public:
	List(int vertex);
	~List();
	bool isEmpty();
	void insertToEnd(int u,int vertex, int weight);
	void insertToStart(int u, int vertex, int weight);
	void removeEdge(Edge* toRemove);
	void findEdgeAndRemoveIt(int v);
	bool findEdge(int v);
};
