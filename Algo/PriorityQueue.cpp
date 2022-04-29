#include "PriorityQueue.h"

// constructor
PriorityQueue::PriorityQueue() { }

//destructor
PriorityQueue::~PriorityQueue()
{
	heap.clear();
	indices.clear();
}

// build heap using floyd algorithm - currently not workink
void PriorityQueue::Build(int max, vector<int>& min)
{
	int i;
	indices.push_back(-1);
	for (i = 1; i <= max; ++i)
	{
		Pair tmp;
		tmp.data = i ;
		tmp.key = min[i];
		heap.push_back(tmp);
		indices.push_back(i-1);
	}

	int heapSize = heap.size();

	for (i = heapSize / 2 - 1; i >= 0; i--)
		FixHeapDown(i);

}

// return true if the queue is empty
bool PriorityQueue::IsEmpty() 
{
	if (heap.size() == 0)
		return true;
	else
		return false;
}


// decrese key of given pair
void PriorityQueue::DecreaseKey(int item, int newKey)
{
	int ind = indices[item];
	heap[ind].key = newKey;
	FixHeapUp(ind);
}


// returns the node's parent
int PriorityQueue::Parent(int pair)
{
	return (pair - 1) / 2;
}

// returns the node's left child
int PriorityQueue::Left(int pair)
{
	return (2 * pair + 1);
}

// returns the node's right child
int PriorityQueue::Right(int pair)
{
	return (2 * pair + 2);
}

// delete the pair with the minimum priority and returns it
Pair PriorityQueue::DeleteMin()
{
	int heapsize = heap.size();
	Pair min = heap[0];
	heap[0] = heap[heapsize - 1];
	indices[heap[heapsize - 1].data] = 0;
	heap.resize(heapsize - 1);
	FixHeapDown(0);
	return min;
}

// Fixheap: if the parent priority is greater than it's child poriority, it'll swap them. It'll stop when we get to the root.
void PriorityQueue::FixHeapUp(int pair)
{
	int parent = Parent(pair);

	if (parent >= 0 && (heap[pair].key < heap[parent].key))
	{
		Swap(pair, parent);
		FixHeapUp(parent);
	}
}

// Fixheap towards down - if the node's priority is greater than it's right/left child poriority, it'll swap them. it'll stop when we get to the end of the heap.
void PriorityQueue::FixHeapDown(int pair)
{
	int min = pair, left = Left(pair);
	int right = Right(pair);
	int heapsize = heap.size();

	if (left < heapsize && (heap[left].key < heap[pair].key))
		min = left;
	else
		min = pair;

	if (right < heapsize && (heap[right].key < heap[min].key))
		min = right;

	if (min != pair)
	{
		Swap(pair, min);
		FixHeapDown(min);
	}
}

// swap two pairs in the heap
void PriorityQueue::Swap(int i, int j)
{
	Pair tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
	int tmpInd = indices[heap[i].data];
	indices[heap[i].data] = indices[heap[j].data];
	indices[heap[j].data] = tmpInd;
}
