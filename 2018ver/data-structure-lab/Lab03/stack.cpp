#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"

Stack::Stack() {
	top = -1;
}

Stack::~Stack(){
	for (; isEmpty() == false;) {
		pop();
	}
}

int Stack::isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int Stack::isFull() {
	if (top == sizeStack) {
		return 1;
	}
	else {
		return 0;
	}
}

void Stack::push(char val) {
	stack[++top] = val;
	
}

char Stack::pop() {
	char pop_val = stack[top];
	stack[top--] = NULL;
	return pop_val;
}

void Stack::display() {

	for (int i = 0; i < top; ++i) {
		cout << stack[i] << " ";
	}
	cout << endl;
}


#endif