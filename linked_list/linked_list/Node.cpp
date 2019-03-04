#pragma once
#ifndef NODE_CPP
#define NODE_CPP
#include "Node.h"

Node::Node() {
	data = NULL;
	next = NULL;
}

void Node::setData(int data) {
	this->data = data;
}

int Node::getData() {
	return this->data;
}

void Node::setNext(Node * next) {
	this->next = next;
}

Node * Node::getNext(){
	return this->next;
}

#endif