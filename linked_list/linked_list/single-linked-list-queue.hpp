#ifndef SINGLELINKEDLISTQUEUE_HPP
#define SINGLELINKEDLISTQUEUE_HPP
#include "single-linked-list.hpp"

template <typename T>
class SingleLinkedListQueue {
private:
	SingleLinkedList<T> queue;
	Node<T> * front;
	Node<T> * rear;

public:
	SingleLinkedListQueue() {
		front = NULL;
		rear = NULL;
	}

	SingleLinkedList<T> getQueue() {
		return this->queue;
	}
	
	int isEmpty() {
		if (front == NULL) 
			return true;
		return false;
	}

	void enQueue(T data) {
		Node<T> * temp = new Node<T>(data);
		if (isEmpty()) {
			front = temp;
			rear = temp;
			queue.setHead(front);
		}
		else {
			rear->setNext(temp);
			rear = temp;
		}
	}

	T deQueue() {
		if (isEmpty()) 
			cout << "Queue is Empty !!";

		else {
			Node<T> * temp = front;
			T value = temp->getData();

			front = front->getNext();
			queue.setHead(front);

			if (front == NULL)
				rear = NULL;
			delete temp;
		
			return value;
		}
	}

	void display() {
		if (isEmpty())
			cout << "Queue is Empty!!!" << endl;
		else {
			Node<T> * temp = front;
			while (temp) {
				cout << temp->getData();
				temp = temp->getNext();
			}
			cout << endl;
		}
	}




	
};


#endif
