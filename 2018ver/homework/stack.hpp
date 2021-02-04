#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>

using namespace std;

const int sizeStack = 100;

template <typename T>
class Stack {
private:
	T stack[sizeStack] = { 0, };
	int top;

public:
	Stack() {
		top = -1;
	}
	~Stack() {
		for (; isEmpty() == false;) 
			pop();
	}
	void push(T val) {
		stack[++top] = val;
	}
	T pop() {
		T pop_val = stack[top];
		stack[top--] = NULL;
		return pop_val;
	}
	int isEmpty() {
		if (top == -1) 
			return 1;
		return 0;
	}
	int isFull() {
		if (top == sizeStack)
			return 1;
		return 0;
	}
	void display() {
		for (int i = 0; i < top; ++i) 
			cout << stack[i] << " ";
		cout << endl;
	}
	T getStackOfTop() {
		return stack[top];
	}
};

#endif