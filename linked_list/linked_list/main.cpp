
#include "single-linked-list.hpp"

int main() {
	SingleLinkedList<int> sll;
	SingleLinkedList<int> sll2;
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
	// -5 -10 -100

	sll2.append(1);
	sll2.append(2);
	sll2.insert(0);
	sll2.display();

	sll2.reverse();
	sll2.display();

	sll2.concatenate(sll.getHead(), sll.size()); // 2 1 0 -5 -10 -100
	sll2.display();

	return 0;
}


