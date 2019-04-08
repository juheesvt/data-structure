#include <iostream>
#include "stack.hpp"
// 교수님은 3칸이면 3칸 다잡음
// 세개 엔큐하고 하나 빼면
// 0번째 인덱스가 front니까 
// 데이터는 두개지만 Queue는 다참 !!

#define MAX_SIZE 50
using namespace std;

class Queue {
private:
	char *qarray;
	int front;
	int rear;
	const int size;
public:
	Queue(int size);
	void enQueue(char value);
	char deQueue();
	bool isFull();
	bool isEmpty();
	void printQueue();
};

Queue q(MAX_SIZE);
Stack <char> s;

int main() {
	

	s.push('a');
	q.enQueue('b');
	q.enQueue('c');
	q.enQueue('d');
	s.push('e');

	s.push('F');
	q.enQueue('G');

	s.display();

	q.printQueue();

	cout << "Output :";
	cout << s.pop() << " ";
	cout << q.deQueue() << " ";
	cout << q.deQueue() << " ";
	cout << q.deQueue() << " ";
	cout<< s.pop() << endl;

	s.pop();
	q.deQueue();

	
	q.enQueue('A');
	q.enQueue('B');
	q.enQueue('C');
	q.deQueue();
	q.enQueue('D');
														

	q.printQueue();

	q.deQueue();
	q.deQueue();
	q.deQueue();




}

Queue::Queue(int size) : size(3) {
	qarray = new char[size]();
	front = -1;
	rear = -1;
}
void Queue::enQueue(char value) {
	rear = ((rear+1) % size);
	if (isFull()) {
		rear--;
		if (rear < 0) {
			rear = 0;
		}
		cout << "Queue is Full		" << endl;
	}
	else {
		qarray[rear] = value;
	}
}


char Queue::deQueue() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
	}
	else {
		front = (front +1) % size;
		return qarray[front];
	}
}
bool Queue::isFull() {
	if (rear == front)
		return true;
	else
		return false;
}
bool Queue::isEmpty() {
	if (front == rear)
		return true;
	else
		return false;
}
void Queue::printQueue() {
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else {
		cout << "Queue : ";
		int i = (front + 1) % (size);
		while (true) {
			cout << qarray[i-1] << " ";
			if (i == rear)
				break;
			i = (i + 1) % size;
		}
		cout << endl;
	}
}