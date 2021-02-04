#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>

using namespace std;

const int sizeStack = 2;

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
		if (isFull())
			cout << "StackFull"<< endl;
		else
			stack[++top] = val;
	}
	T pop() {
		if (isEmpty())
			cout << "StackEmpty" << endl;
		else {
			T pop_val = stack[top];
			stack[top--] = NULL;
			return pop_val;
		}
	}
	int isEmpty() {
		if (top == -1)
			return 1;
		return 0;
	}
	int isFull() {
		if (top == sizeStack-1) 
			return 1;
		return 0;
	}
	void display() {
		if (isEmpty())
			cout << "StackEmpty" << endl;
		else {
			cout << "Stack : ";
			for (int i = top; i >= 0; i--)
				cout << stack[i] << " ";
			cout << endl;
		}
	}
	T getStackOfTop() {
		if (isEmpty)
			cout << "Stack is empty !" << endl;
		else
			return stack[top];
	}
};

#endif