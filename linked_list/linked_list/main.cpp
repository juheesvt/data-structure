
#include "single-linked-list-queue.hpp"
#include "single-linked-list-stack.hpp"

int main() {
	
	SingleLinkedListQueue<char> q;
	SingleLinkedListStack<char> s;
	SingleLinkedList<char> sll;

	s.push('a');
	s.push('e');
	s.display();
	q.enQueue('b');
	q.enQueue('c');
	q.enQueue('d');
	q.display();
	//sll.concatenate((s.getStack()).getHead(), (q.getQueue()).getHead());

	return 0;
}


