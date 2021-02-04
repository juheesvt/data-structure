#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node<T> * next;
	Node<T> * prev;

public:
	Node(T data = NULL, Node<T> * next = NULL, Node<T> * prev = NULL) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	T getData() {
		return this->data;
	}
	Node<T> * getNext() {
		return this->next;
	}
	Node<T> * getPrev() {
		return this->prev;
	}
	void setData(T data) {
		this->data = data;
	}
	void setNext(Node<T> * next) {
		this->next = next;
	}
	void setPrev(Node<T> * prev) {
		this->prev = prev;
	}
};

template <typename T>
class DoubleLinkedList {
private:
	Node<T> * head;
public:
	DoubleLinkedList() {
		head = NULL;
	}
	Node<T> * getHead() {
		return this->head;
	}
	void setHead(Node<T> * head) {
		this->head = head;
	}
	bool isEmpty() {
		return head == NULL;
	}

	// insert(오름차순 정렬)
	void insert(T data) {
		Node<T> * newNode = new Node<T>(data);

		if (isEmpty())
			head = newNode;

		else {
			Node<T> * temp = head;

			// 새로운 노드의 값이 헤드의값보다 작을 경우
			if (newNode->getData() < head->getData()) {
				head = newNode;
				newNode->setNext(temp);
				temp->setPrev(newNode);
			}
			else {
				for (int i = 0;; i++) {
					// 리스트에 노드 하나만 있는데 헤드의 값 보다 클 경우
					if (temp != NULL && temp->getNext() == NULL) {
						temp->setNext(newNode);
						newNode->setPrev(temp);
						break;
					}
					else if (
						// 리스트 중간에 삽입될 조건
						temp != NULL &&
						newNode->getData() >= temp->getData() &&
						temp->getNext() != NULL &&
						newNode->getData() < temp->getNext()->getData()) {

						newNode->setNext(temp->getNext());
						temp->getNext()->setPrev(newNode);
						temp->setNext(newNode);
						newNode->setPrev(temp);
						break;
					}
					temp = temp->getNext();
				}
			}
		}
	}
	void insertAfter(int index, T data) {
		Node<T> * newNode = new Node<T>(data);

		if (isEmpty()) {
			head = newNode;
			return;
		}

		Node<T> * temp = head;
		for (int i = 0; i < index-1; i++) {
			temp = temp->getNext();
		}
		newNode->setNext(temp->getNext());
		temp->getNext()->setPrev(newNode);
		temp->setNext(newNode);
		newNode->setPrev(temp);

	}
	void insertBefore(int index, T data) {

		Node<T> * newNode = new Node<T>(data);

		if (isEmpty()) {
			head = newNode;
			return;
		}

		Node<T> * temp = head;

		for (int i = 0; i < index - 1; i++) {
			temp = temp->getNext();
		}
		if (temp == head) {
			newNode->setNext(temp);
			temp->setPrev(newNode);
			head = newNode;
		}
		else {
			temp->getPrev()->setNext(newNode);
			newNode->setPrev(temp->getPrev());
			newNode->setNext(temp);
			temp->setPrev(newNode);
		}

	}

	void delIndex(int index) {
		if (isEmpty()) {
			cout << "List is Empty!!" << endl;
			return;
		}
		Node<T> * temp = head;
		for (int i = 0; i < index - 1; i++)
			temp = temp->getNext();

		//삭제할 노드가 헤드일 경우
		if (temp == head) {
			head->getNext()->setPrev(NULL);
			head = head->getNext();
			delete temp;
			return;
		}
		
		//마지막 노드를 삭제할 경우
		if (temp->getNext() == NULL) {
			temp->getPrev()->setNext(NULL);
			delete temp;
			return;
		}

		// 중간 노드를 삭제할 경우
		temp->getPrev()->setNext(temp->getNext());
		temp->getNext()->setPrev(temp->getPrev());
		delete temp;

	}

	void del(T data) {
		if (isEmpty())
			cout << "DoubleLinkedList is Empty !!" << endl;

		else {
			Node<T> * pre_target_node = NULL;
			Node<T> * target_node = head;
			bool in = true;

			for (; target_node != NULL; pre_target_node = target_node, target_node = target_node->getNext()) {
				if (data == target_node->getData()) {	

					if (pre_target_node != NULL) {	
						pre_target_node->setNext(target_node->getNext());
						target_node->getNext()->setPrev(pre_target_node);
					}
					
					if (target_node == head) {
						head = target_node->getNext();
						target_node->getNext()->setPrev(NULL);
					}

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

	// display
	void displayForward() {
		if (isEmpty()) {
			cout << " List is Empty!! " << endl;
			return;
		}

		Node<T> * temp = head;
		cout << "DoubleLinkedList(Forward) : ";
		for (; temp != NULL; temp = temp->getNext())
			cout << temp->getData() << " ";
		cout << endl;
	}
	void displayBackward() {
		if (isEmpty()) {
			cout << " List is Empty!! " << endl;
			return;
		}

		Node<T> * temp = head;
		cout << "DoubleLinkedList(Backward) : ";
		for (; temp->getNext() != NULL; temp = temp->getNext());
		for (; temp != NULL; temp = temp->getPrev())
			cout << temp->getData() << " ";
		cout << endl;
			
	}
	Node<T> * findNode(int index) {
		if (isEmpty()) {
			cout << " List is Empty !! " << endl;
			return;
		}
		Node<T> * temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->getNext();
		}
		return temp;
	}

	~DoubleLinkedList() {
		if (!isEmpty()) {

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