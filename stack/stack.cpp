#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"

Stack::Stack() {
	top = -1;
}

Stack::~Stack() {
	for (; isEmpty() == false;)
		pop();
}


int Stack::isEmpty() {
	if (top == -1) 
		return 1;
	else 
		return 0;
}

int Stack::isFull() {
	if (top == sizeStack - 1)
		return 1;
	else
		return 0;
}

void Stack::push(char val) {
	if (isFull())
		cout << "Stack is Full" << endl;
	else
		stack[++top] = val;
}

char Stack::pop() {
	if (isEmpty())
		cout << "StackEmpty" << endl;
	else {
		char pop_val = stack[top];
		stack[top--] = NULL;
		return pop_val;
	}
}

void Stack::display() {
	if (isEmpty())
		cout << "StackEmpty" << endl;
	else {
		cout << "Stack : ";
		for (int i = top; i >= 0; i--)
			cout << stack[i] << " ";
		cout << endl;
	}
}


#endif