#ifndef  MAIN_CPP
#define MAIN_CPP
#include "single_linked_list.h"

int main() {
	SingleLinkedList sll;
	
	sll.isEmpty();
	sll.insert(10);
	sll.display();
	sll.insert(5);
	sll.display();
	sll.insert(0);
	sll.insert(100);
	sll.display();
	sll.del(0);
	sll.display();
	sll.del(100);
	sll.display();
	sll.del(2);
	sll.del(5);
	sll.del(10);
	sll.display();

	return 0;
}

#endif // ! MAIN_CPP


