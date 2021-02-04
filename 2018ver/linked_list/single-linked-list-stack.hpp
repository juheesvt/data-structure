#ifndef SINGLELINKEDLISTSTACK_HPP
#define SINGLELINKEDLISTSTACK_HPP
#include "single-linked-list.hpp"



template <typename T>
class SingleLinkedListStack {
private:
	SingleLinkedList<T> stack;
	int top;

public:
	SingleLinkedListStack<T>() {
		top = -1;
	}
	SingleLinkedList<T> getStack() {
		return this->stack;
	}

	int stackIsEmpty() {
		if (top == -1)
			return 1;
		return 0;
	}
	void push(T data) {
		Node<T> * node = new Node<T>(data);
		if (stackIsEmpty()) {
			stack.setHead(node);
		}
		else {
			Node<T> *temp = stack.getHead();
			stack.setHead(node);
			node->setNext(temp);
		}
		top++;
	}
	T pop() {
		Node<T> *temp = stack.getHead();
		T popData = temp->getData();
		stack.setHead((stack.getHead())->getNext());
		top--;
		delete temp;
		return popData;
	}
	void display() {
		stack.display();
	}

};



#endif