
#include "single-linked-list-stack.hpp"

int main() {
	SingleLinkedListStack<int> s;

	if (s.isEmpty())
		cout << "stack is Empty !" << endl;
	else
		cout << "stack isn't Empty !" << endl;

	s.push(1);
	s.push(2);
	s.push(10);
	s.display();
	cout << s.pop() << endl;
	s.display();


	return 0;
}


