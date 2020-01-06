#pragma once
#include <iostream>
#include <string>
#include "Building.h"
#include "Fabrica.h"
#include "Node.h"
using namespace std;
class List
{
private:
	Node * head;
	int size;
protected:
	void push2(Build* data);
public:
	List() : head(nullptr), size(0) {}
	List(const List& other);
	virtual ~List(); 
	void pop();
	void push_front(Build* data);
	void push(Build* data);
	void pop_back(); 
	void clear(); 
	void show();  
	int GetSize() { return size; }  
	void write();
	void read(); 

	Build*& operator[](const int index);

	void insert(Build* data, int index);
	void removeAt(int index) ; 


};
