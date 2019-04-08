
#include "single-linked-list.hpp"

int main() {
	SingleLinkedList<int> sll;
	if (sll.isEmpty())
		cout << "Empty !" << endl;

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
	sll.insert(-5);
	sll.insert(-10);
	sll.append(-100);
	sll.display();
	sll.reverse();
	sll.display();

	return 0;
}


