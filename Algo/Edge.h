#pragma once

class Edge {
private:
	int vertex;
	int weight;
	Edge* next;
	Edge* prev;
public:
	Edge(int vertex, int weight, Edge* next, Edge* prev);
	~Edge();
	bool isHead();
	bool isTail();
	Edge* getNext();
	Edge* getPrev();
	void setNext(Edge* next);
	void setPrev(Edge* prev);
};

