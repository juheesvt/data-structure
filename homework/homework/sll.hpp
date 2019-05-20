#ifndef SingleLINKEDLIST_HPP
#define SingleLINKEDLIST_HPP
#include <iostream>


using namespace std;

template <typename T>
class Node {

private:
	T data;
	Node<T> * next;

public:
	Node<T>(T data = NULL) {
		this->data = data;
		this->next = NULL;
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

public:

	SingleLinkedList() {
		head = NULL;
	}

	Node<T> * getHead() {
		return this->head;
	}

	void setHead(Node<T> * head) {
		this->head = head;
	}

	bool isEmpty() {
		if (head == NULL)
			return true;
		return false;
	}
	// 오름차순으로 정렬되게 집어 넣기 !
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
	}
	void del(T data) {
		if (isEmpty())
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
					break;
				}
				if (target_node != head && target_node->getNext() == NULL)
					in = false;
			}
			if (!in)
				cout << data << "가 list안에 없습니다." << endl;
		}
	}

	void display() {
		if (isEmpty())
			cout << "SingleLinkedList is Empty !!" << endl;
		else {
			Node<T> * temp = head;
			while (temp) {
				cout << temp->getData() << " ";
				temp = temp->getNext();
			}
			cout << endl;
		}
	}
	int search(T data) {
		Node<T> * temp = head;
		int index = -1;
		int i = 0;
		while (temp) {
			if (data == temp->getData()) {
				index = i++;
				break;
			}
			temp = temp->getNext();
		}
		if (index == -1)
			cout << data << "가 list안에 없습니다." << endl;
		else
			cout << index << endl;
		return index;
	}

	void concatenate(Node<T>* list1head, Node<T>* list2head) {
		if (list1head == NULL)
			head = list2head;

		else if (list2head == NULL)
			head = list1head;

		else {
			//리스트 합치기
			head = list1head;
			Node<T> *temp = list1head;
			for (; temp->getNext() != NULL; temp = temp->getNext());
			temp->setNext(list2head);

			//헤드값 ( 가장 최솟값 구하기 )
			temp = list1head;
			Node<T> * cmp = list1head;
			Node<T> * sortedNode;

			for (; temp->getNext() != NULL; temp = temp->getNext()) {
				if (temp->getData() < cmp->getData())
					cmp = temp;
			}

			//선택정렬시작
			this->head = cmp;
			sortedNode = head;
			for (; sortedNode->getNext() != NULL;) {
				Node<T> * sortTargetNode = sortedNode->getNext();
				Node<T> * minNode = sortedNode->getNext();
				for (; sortTargetNode != NULL; sortTargetNode = sortTargetNode->getNext()) {
					if (sortTargetNode->getData() < minNode->getData())
						minNode = sortTargetNode;
				}
				T changeData = (sortedNode->getNext())->getData();
				(sortedNode->getNext())->setData(minNode->getData());
				minNode->setData(changeData);
				sortedNode = sortedNode->getNext();

			}

		}
	}
	int size() {
		if (isEmpty())
			return 0;
		int length = 0;
		Node<T> * temp = head;
		for (; temp != NULL; temp = temp->getNext())
			length++;
		return length;
	}

	// 리스트 완전히 뒤집기
	void reverse() {
		Node<T> * middle, *trail;
		middle = NULL;

		while (head) {
			trail = middle;
			middle = head;
			head = head->getNext();
			middle->setNext(trail);
		}
		head = middle;
	}

	~SingleLinkedList() {
		if (!isEmpty() || this->head->getData() < 0) {

			Node<T> * del_node = head;
			Node<T> * next_del_node = head->getNext();

			for (int i = 0; ; ++i) {
				if (next_del_node == NULL) {	// 리스트안에 데이터가 하나만 있을 때
					delete del_node;
					break;
				}
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