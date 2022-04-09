#include "List.h"

Edge::Edge(int vertex, int weight, Edge* next)
{
	this->weight = weight;
	this->next = next;

}

Edge::~Edge()
{
}
