#include <iostream>
#include "stack.hpp"
// �������� 3ĭ�̸� 3ĭ ������
// ���� ��ť�ϰ� �ϳ� ����
// 0��° �ε����� front�ϱ� 
// �����ʹ� �ΰ����� Queue�� ���� !!

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
	

	q.enQueue('b');
	q.enQueue('c');
	q.enQueue('d');


	q.enQueue('G');

	q.printQueue();

	cout << "Output :";

	cout << q.deQueue() << " ";
	cout << q.deQueue() << " ";
	cout << q.deQueue() << " ";

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
	front = 0;
	rear = 0;
}
void Queue::enQueue(char value) {
	rear = (rear) % size+1;
	if (isFull()) {
		cout << "Queue is Full" << endl;
		return;
	}
	qarray[rear] = value;

}


char Queue::deQueue() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
	}
	else {
		front = (front ) % size);
		return qarray[front];
	}
}
bool Queue::isFull() {
	return rear == front;
}
bool Queue::isEmpty() {
	return rear == front;
}
void Queue::printQueue() {
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else {
		cout << "Queue : ";
		int i = (front + 1) % size;
		while (true) {
			cout << qarray[i] << " ";
			if (i == rear)
				break;
			i = (i + 1) % size;
		}
		cout << endl;
	}
}