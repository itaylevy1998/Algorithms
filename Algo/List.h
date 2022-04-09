#pragma once

class Edge {
private:
	int vertex;
	int weight;
	Edge* next;
public:
	Edge(int vertex ,int weight, Edge* next);
	~Edge();
	

};

class List {
	Edge* head;
	Edge* tail;
};
