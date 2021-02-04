#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include <iostream>

using namespace std;


class Node {
private:
	char name[5];
	int weight;
	int height;
	Node* next;
	Node * prev;

public:
	Node(char * name = NULL, int weight=NULL , int height = NULL, Node * next = NULL, Node * prev = NULL) {
		strcpy(this->name,name);
		this->height = height;
		this->weight = weight;
		this->next = next;
		this->prev = prev;
	}
	char * getName() {
		return this->name;
	}
	int getWeigth() {
		return this->weight;
	}
	int getHeight() {
		return this->height;
	}
	Node* getNext() {
		return this->next;
	}
	Node * getPrev() {
		return this->prev;
	}

	void setName(char * name ) {
		strcpy(this->name,name);
	}
	void setWeight(int w) {
		this->weight = w;
	}
	void setHeight(int h) {
		this->height = h;
	}
	void setNext(Node * next) {
		this->next = next;
	}
	void setPrev(Node * prev) {
		this->prev = prev;
	}
};


class DoubleLinkedList {
private:
	Node * head;
public:
	DoubleLinkedList() {
		head = NULL;
	}
	Node * getHead() {
		return this->head;
	}
	void setHead(Node * head) {
		this->head = head;
	}
	bool isEmpty() {
		return head == NULL;
	}

	// insert(오름차순 정렬)
	void insert(char * name, int w, int h) {
		Node * newNode = new Node(name, w, h);

		if (isEmpty())
			head = newNode;

		else {
			Node * temp = head;

			// 새로운 노드의 값이 헤드의값보다 작을 경우
			if (strcmp(newNode->getName(), head->getName()) < 0) {
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
						newNode->getName() >= temp->getName() &&
						temp->getNext() != NULL &&
						strcmp(newNode->getName(),temp->getNext()->getName()) < 0) {

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
	void insertAfter(int index,char * name, int w, int h) {
		Node * newNode = new Node(name, w, h);

		if (isEmpty()) {
			head = newNode;
			return;
		}

		Node * temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->getNext();
		}
		newNode->setNext(temp->getNext());
		temp->getNext()->setPrev(newNode);
		temp->setNext(newNode);
		newNode->setPrev(temp);

	}
	void insertBefore(int index, char * name, int w, int h) {

		Node * newNode = new Node(name,w,h);

		if (isEmpty()) {
			head = newNode;
			return;
		}

		Node * temp = head;

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
		Node * temp = head;
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

	void del(char * name) {
		if (isEmpty())
			cout << "DoubleLinkedList is Empty !!" << endl;

		else {
			Node * pre_target_node = NULL;
			Node * target_node = head;
			bool in = true;

			for (; target_node != NULL; pre_target_node = target_node, target_node = target_node->getNext()) {
				if (strcmp(name,target_node->getName()) == 0) {

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
				cout << "list안에 해당 이름이 없습니다." << endl;
		}
	}

	// display
	void displayForward() {
		if (isEmpty()) {
			cout << " List is Empty!! " << endl;
			return;
		}

		Node * temp = head;
		cout << "DoubleLinkedList(Forward) " << endl;
		cout << "name" << "\t" << "weight" << "\t" << "height" << endl;
		for (; temp != NULL; temp = temp->getNext()) {
			for (char * t = temp->getName(); *t != NULL; t++)
				cout << *t;
			cout << "\t";

			cout << temp->getWeigth() << "\t";
			cout << temp->getHeight();
			cout << endl;
		}
		cout << endl;
	}
	void displayBackward() {
		if (isEmpty()) {
			cout << " List is Empty!! " << endl;
			return;
		}

		Node * temp = head;
		cout << "DoubleLinkedList(Backward) : ";
		cout << endl;
		for (; temp->getNext() != NULL; temp = temp->getNext());
		for (; temp != NULL; temp = temp->getPrev()) {
			for (char * t = temp->getName(); *t != NULL; t++)
				cout << *t;
			cout << "\t";

			cout << temp->getWeigth() << "\t";
			cout << temp->getHeight();
			cout << endl;
		}
		cout << endl;

	}
	int search(char * name) {
		Node * temp = head;
		int index = -1;
		int i = 0;
		while (temp) {
			if (strcmp(name,temp->getName()) == 0) {
				index = i++;
				break;
			}
			temp = temp->getNext();
		}
		if (index == -1)
			cout << "NotFound" << endl;
		else
			cout << "found" << endl;
		return index;
	}
	Node * findNode(int index) {
		if (isEmpty()) {
			cout << " List is Empty !! " << endl;
			return NULL;
		}
		Node * temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->getNext();
		}
		for (char * t = temp->getName(); *t != NULL; t++)
			cout << *t;
		cout << "\t" << temp->getWeigth() << "\t" << temp->getHeight() << endl;
		return temp;
	}

	~DoubleLinkedList() {
		if (!isEmpty()) {

			Node* del_node = head;
			Node* next_del_node = head->getNext();

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