#include "single-linked-list.hpp"

int main() {

	SingleLinkedList<int> s;

	s.del(10);
	s.insert(10);
	s.insert(5);
	s.display();
	s.insert(30);

	if (s.search(5) != -1) {
		cout << "5 is in list" << endl;
	}

	s.del(5);
	s.display();

	if (s.find(3) == -1)
		cout << "not found" << endl;

	s.displayLast();

	s.insert(40);

	s.reverse();
	s.display();


	



}