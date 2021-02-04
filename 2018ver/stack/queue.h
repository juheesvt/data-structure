#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

const int queueSize = 3;

class Queue {
private:
	
	char queue[queueSize];
	int  rear;
	int	 front;

public:
	Queue();
	int isFull();
	int isEmpty();
	void enQueue(char var);
	char deQueue();
	void display();


};
#endif //!QUEUE_H
