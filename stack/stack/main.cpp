#ifndef MAIN_CPP
#define MAIN_CPP
#include "queue.h"

int main() {
	/*
	Stack s1;

	s1.isEmpty(); // 비었는지 출력하기
	s1.push('a');
	s1.display();
	s1.push('b');
	s1.display();
	s1.push('c');
	s1.display();
	s1.isFull();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	*/


	/*
	empty!
	a
	ab
	abc
	full!
	ab
	a
	*/

	Queue q;

	q.isEmpty();
	q.enQueue('a');
	q.display();
	q.enQueue('b');
	q.display();
	q.enQueue('c');
	q.display();
	q.isFull();
	q.deQueue();
	q.display();
	q.deQueue();
	q.display();
	q.deQueue();
	q.isEmpty();





	return 0;
}

#endif