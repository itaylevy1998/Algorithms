#pragma once
#include <iostream>
using namespace std;

struct Pair {
	int key;	// edge weight
	int data;	// vertex name
};

class PriorityQueue
{
public:
	PriorityQueue(int max = 0);
	~PriorityQueue();

	void Build(int* V, int* min);
	Pair* DeleteMin();
	bool IsEmpty();
	void DecreaseKey(int place, int newKey);

private:
	int maxSize, allocated, heapSize;
	Pair** heap;

	int Parent(int pair);
	int Left(int pair);
	int Right(int pair);
	void FixHeapUp(int place);
	void FixHeapDown(int pair);
	void Swap(int i, int j);
};

