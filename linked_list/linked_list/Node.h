#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

class Node {

private:
	int data;
	Node * next;

public:
	Node();
	int getData();
	void setData(int data);
	Node * getNext();
	void setNext(Node *next);

};


#endif
