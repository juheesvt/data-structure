#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

const int sizeStack = 50;

class Stack {
private:
	char stack[sizeStack] = { 0, };
	int top;

public:
	Stack();
	~Stack();
	void push(char val);
	char pop();
	int isEmpty();
	int isFull();
	void display();
};

#endif