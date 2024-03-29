#pragma once
// hello
class Edge {
private:
	int u;
	int v;
	int weight;
	Edge* next;
	Edge* prev;
public:
	Edge(int u, int vertex, int weight, Edge* next, Edge* prev);
	~Edge();
	bool isHead();
	bool isTail();
	Edge* getNext();
	Edge* getPrev();
	int getV();
	int getU();
	int getWeight();
	void setNext(Edge* next);
	void setPrev(Edge* prev);
};

