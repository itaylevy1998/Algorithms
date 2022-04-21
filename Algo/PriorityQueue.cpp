#include "PriorityQueue.h"

// constructor
PriorityQueue::PriorityQueue(int max) : heap(nullptr), maxSize(max), allocated(0), heapSize(0)
{
	heap = new Pair * [maxSize];
	allocated = 1;
}

//destructor
PriorityQueue::~PriorityQueue()
{
	for (int i = 0; i < heapSize; i++)
		delete heap[i];

	if (allocated)
		delete[] heap;

	heap = nullptr;
}

// build heap using floyd algorithm - currently not workink
void PriorityQueue::Build(int* V, int* min)
{
	int i;
	for (i = 0; i < maxSize; ++i)
	{
		Pair* tmp = new Pair;
		tmp->data = V[i];
		tmp->key = min[i];
		heap[i] = tmp;
	}

	heapSize = maxSize;

	for (i = maxSize / 2 - 1; i >= 0; i--)
		FixHeapDown(i);

}

// return true if the queue is empty
bool PriorityQueue::IsEmpty() 
{
	if (heapSize == 0)
		return true;
	else
		return false;
}


// decrese key of given pair
void PriorityQueue::DecreaseKey(int place, int newKey)
{
	(*heap[place]).key = newKey;
	FixHeapUp(place);
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
Pair* PriorityQueue::DeleteMin()
{
	if (heapSize < 1)
	{
		return nullptr;
	}
	else
	{
		Pair* min = heap[0];
		heapSize--;
		heap[0] = heap[heapSize];
		FixHeapDown(0);
		return min;
	}
}

// Fixheap: if the parent priority is greater than it's child poriority, it'll swap them. It'll stop when we get to the root.
void PriorityQueue::FixHeapUp(int pair)
{
	int parent = Parent(pair);

	if (parent >= 0 && (heap[pair]->key < heap[parent]->key))
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

	if (left < heapSize && (heap[left]->key < heap[pair]->key))
		min = left;
	else
		min = pair;

	if (right < heapSize && (heap[right]->key < heap[min]->key))
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
	Pair* tmp = heap[i];
	cout << tmp;
	heap[i] = heap[j];
	heap[j] = tmp;
}
