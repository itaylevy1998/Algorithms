#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Pair {
	int key;	// edge weight
	int data;	// vertex name
};

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	void Build(int max, vector<int>& min);
	Pair DeleteMin();
	bool IsEmpty();
	void DecreaseKey(int item, int newKey);

private:
	vector<Pair> heap;
	vector<int> indices;
	int Parent(int pair);
	int Left(int pair);
	int Right(int pair);
	void FixHeapUp(int place);
	void FixHeapDown(int pair);
	void Swap(int i, int j);
};

