
#include "single-linked-list-queue.hpp"

int main() {
	
	SingleLinkedListQueue<int> q;

	if (q.isEmpty())
		cout << "Queue is Empty" << endl;

	q.enQueue(1);
	q.display();
	q.enQueue(2);
	q.display();
	q.enQueue(3);
	q.display();
	cout << q.deQueue() << endl;
	q.display();
	q.deQueue();
	q.deQueue();
	q.display();
	q.deQueue();

	return 0;
}


