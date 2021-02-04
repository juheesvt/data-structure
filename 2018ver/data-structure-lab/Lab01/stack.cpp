#include <iostream>

using namespace std;

const int STACK_SIZE = 10;
int stack[STACK_SIZE];
int top;

void initStack();
int isEmpty();
int isFull();
void push(int data);
int pop();


void initStack() {
	top = -1;
}

int isEmpty() {
	if (top == -1)
		return 1;

	return 0;
}

int isFull() {
	if (top == STACK_SIZE - 1)
		return 1;
	return 0;
}

void push(int data) {
	if (isFull()) {
		cout << "stack is full !" << endl;
		return;
	}

	stack[++top] = data;
}

int pop() {
	if (isEmpty())
		cout << " stack is empty !" << endl;
	else
		return stack[top--];
}

