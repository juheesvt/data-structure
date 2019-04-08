#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"


Queue::Queue() {
	rear = 0;
	front = 0;
}

int Queue::isEmpty() {
	if (!rear) {
		cout << " Queue is empty !" << endl;
		return 1;
	}
	return 0;	
}

int Queue::isFull() {
	if (rear == queueSize) {
		cout << "Queue is full ! " << endl;
		return 1;
	}
	return 0;
}

void Queue::enQueue(char var) {
	if (isFull())
		cout << "Queue is full !" << endl;
	else
		queue[rear++] = var;
}

char Queue::deQueue() {

	if (isEmpty()) {
		cout << "Queue is empty ! " << endl;
		return 'y';
	}
	else {
		char dequeue = queue[front];

		for (int i = 0; i < rear; ++i) {
			queue[i] = queue[i + 1];
		}

		rear -= 1;

		return dequeue;
	}
}

void Queue::display() {
	for (int i = 0; i < rear; ++i) {
		cout << queue[i] << " ";
	}
	cout << endl;
}
#endif