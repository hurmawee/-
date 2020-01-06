#pragma once
#include "Building.h"
#include "Fabrica.h"
#include "Brick.h"
#include "Cottage.h"
#include "Monolithic.h"
#include "Panel.h"

class Node
{
private:
	Build * data;
	Node* next;
public:
	Node() : data(nullptr), next(nullptr) {} 
	Node(Build* d, Node* n) { data = d; next = n; } 
	~Node() {}

	Build* GetData() { return data; } 
	Node* GetNext() { return next; }

	void SetData(Build* d) { data = d; }
	void SetNext(Node* n) { next = n; }
};