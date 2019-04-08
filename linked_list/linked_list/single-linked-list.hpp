#ifndef SingleLINKEDLIST_HPP
#define SingleLINKEDLIST_HPP
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {

private:
	T data;
	Node<T> * next;

public:
	Node<T>() {
		data = NULL;
		next = NULL;
	}
	T getData() {
		return this->data;
	}
	void setData(T data) {
		this->data = data;
	}
	Node<T> * getNext() {
		return this->next;
	}
	void setNext(Node<T> *next) {
		this->next = next;
	}

};


template <typename T>
class SingleLinkedList {

private:
	Node<T> * head;
	int tail;
public:

	SingleLinkedList() {
		head = NULL;
		tail = 0;
	}

	bool isEmpty() {
		if (head == NULL)
			return true;
		return false;
	}
	// ������������ ���ĵǰ� ���� �ֱ� !
	void insert(T data) {
		Node<T> * node = new Node<T>();
		node->setData(data);
		if (isEmpty())
			head = node;

		else {
			if (node->getData() < head->getData()) {
				Node<T> * temp = head;
				head = node;
				node->setNext(temp);
			}
			else {
				Node<T> *temp = head;
				for (int i = 0;; ++i) {
					if (temp != NULL && temp->getNext() == NULL) {
						temp->setNext(node);
						break;
					}
					else if (node != NULL &&
						temp != NULL &&
						node->getData() >= temp->getData() &&
						temp->getNext() != NULL &&
						node->getData() < (temp->getNext())->getData()) {

						node->setNext(temp->getNext());
						temp->setNext(node);
						break;

					}
					temp = temp->getNext();
				}
			}
		}
		tail += 1;
	}

	void append(T data) {

		Node<T> * node = new Node<T>();
		node->setData(data);

		if (isEmpty()) {
			head = node;
		}
		else {

			Node<T> *temp = head;
			for (;; temp = temp->getNext()) {
				if (temp->getNext() == NULL) {
					temp->setNext(node);
					break;
				}
			}
		}
		tail++;
		
	}
	void del(T data) {
		if (!tail)
			cout << "SingleLinkedList is Empty !!" << endl;

		else {
			Node<T> * pre_target_node = NULL;
			Node<T> * target_node = head;
			bool in = true;

			for (; target_node != NULL; pre_target_node = target_node, target_node = target_node->getNext()) {
				if (data == target_node->getData()) {

					if (pre_target_node != NULL)
						pre_target_node->setNext(target_node->getNext());

					if (target_node == head)
						head = target_node->getNext();

					delete target_node;
					tail -= 1;
					break;
				}
				if (target_node != head && target_node->getNext() == NULL)
					in = false;
			}
			if (!in)
				cout << data << "�� list�ȿ� �����ϴ�." << endl;
		}
	}
	int size() {
		return tail;
	}
	void display() {
		if (isEmpty())
			cout << "SingleLinkedList is Empty !!" << endl;
		else {
			Node<T> * temp = head;
			for (int i = 0; i < tail; ++i) {
				cout << temp->getData() << " ";
				temp = temp->getNext();
			}
			cout << endl;
		}
	}
	int search(T data) {
		Node<T> * temp = head;
		int index = -1;

		for (int i = 0; i < tail; ++i) {
			if (data == temp->getData()) {
				index = i;
				break;
			}
			temp = temp->getNext();
		}
		if (index == -1)
			cout << data << "�� list�ȿ� �����ϴ�." << endl;
		else
			cout << index << endl;
		return index;
	}
	~SingleLinkedList() {
		if (!isEmpty()) {

			Node<T> * del_node = head;
			Node<T> * next_del_node = head->getNext();

			for (int i = 0; ; ++i) {

				if (next_del_node->getNext() == NULL) {
					delete del_node;
					delete next_del_node;
					break;
				}

				else {
					delete del_node;
					del_node = next_del_node;
					next_del_node = next_del_node->getNext();

				}
			}
		}
	}

};
#endif