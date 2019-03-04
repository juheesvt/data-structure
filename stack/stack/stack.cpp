#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"

Stack::Stack() {
	top = 0;
}

int Stack::isEmpty() {
	if (!top) {
		cout << "empty !" << endl;
		return 1;
	}
	else {
		cout << "not empty !" << endl;
		return 0;
	}
}

int Stack::isFull() {
	if (top) {
		cout << "full !" << endl;
		return 1;
	}
	else {
		cout << " not full !" << endl;
		return 0;
	}
}

void Stack::push(char val) {
	stack[top++] = val;
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