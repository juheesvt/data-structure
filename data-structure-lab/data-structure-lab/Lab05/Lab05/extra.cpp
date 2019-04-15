#include "single-linked-list.hpp"

int main() {

	SingleLinkedList<char> stack;
	SingleLinkedList<char> queue;

	stack.push('a');
	stack.push('e');
	stack.display();

	queue.enQueue('b');
	queue.enQueue('c');
	queue.enQueue('d');
	queue.display();





	


	return 0;
}