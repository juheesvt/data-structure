#ifndef SINGLELINKEDLISTSTACK_HPP
#define SINGLELINKEDLISTSTACK_HPP
#include "single-linked-list.hpp"



template <typename T>
class SingleLinkedListStack {
private:
	SingleLinkedList<T> stack;
	int top;
	T topData;
	
public:
	SingleLinkedListStack<T>() {
		top = -1;
	}

	int isEmpty() {
		if (top == -1)
			return 1;
		return 0;
	}
	void push(T data) {
		stack.push(data);
		top++;
	}
	T pop() {
		Node<T> *temp = stack.getHead();
		stack.setHead((stack.getHead())->getNext());
		stack.setTail(--top);
		return temp->getData();
	}
	void display() {
		stack.display();
	}

};



#endif