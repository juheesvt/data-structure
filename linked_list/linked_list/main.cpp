
#include "double-linked-list.hpp"


int main() {
	DoubleLinkedList<int> d;

	d.insert(20);
	d.insert(10);
	d.insert(30);
	d.displayForward();

	d.insertAfter(2, 40);
	d.displayForward();

	d.insertBefore(3, 50);
	d.displayForward();

	d.delIndex(5);
	d.displayForward();

	d.displayBackward();

	

	return 0;
}


