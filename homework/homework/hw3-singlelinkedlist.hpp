#ifndef SingleLINKEDLIST_HPP
#define SingleLINKEDLIST_HPP
#include <iostream>
#include <stdio.h>


using namespace std;


class Node {
	
private:
	char name;
	int id;
	char major[3];
	char grade;
	Node * next;

public:
	Node(char name = NULL, int id = NULL, char grade = NULL, char * major = NULL) {
		this->name = name;
		this->id = id;
		this->grade = grade;
		strcpy(this->major, major);
		this->next = NULL;
	}

	char getName() {
		return this->name;
	}
	int getId() {
		return this->id;
	}
	char getGrade() {
		return this->grade;
	}
	char *getMajor() {
		return this->major;
	}

	void setName(char name) {
		this->name = name;
	}
	void setId(int id) {
		this->id = id;
	}
	void setGrade(char grade) {
		this->grade = grade;
	}
	void setMajor(char * major) {
		major = major;
	}

	Node * getNext() {
		return this->next;
	}

	void setNext(Node * next) {
		this->next = next;
	}
};



class SingleLinkedList {

private:
	Node* head;

public:

	SingleLinkedList() {
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

	// 오름차순으로 정렬되게 집어 넣기 !

	void insert(char name, int id, char grade, char * major) {
		Node * newNode = new Node(name, id, grade, major);

		if (isEmpty()) 
			head = newNode;

		else {
			Node * temp = head;

			// 새로운 노드의 name의 값이 헤드의 name의 값보다 작을 경우
			if (newNode->getName() < head->getName()) {
				head = newNode;
				newNode->setNext(temp);
			}
			else { 
				for (int i = 0;; i++) {
					// 리스트에 노드 하나만 있는데 헤드의 name값 보다 클 경우
					if (temp != NULL && temp->getNext() == NULL) {
						temp->setNext(newNode);
						break;
					}
					else if (
						// 리스트 중간에 newNode가 삽입될 조건
						temp != NULL &&
						newNode->getName() >= temp->getName() &&
						temp->getNext() != NULL &&
						newNode->getName() < temp->getNext()->getName()) {

						newNode->setNext(temp->getNext());
						temp->setNext(newNode);
						break;
					}
					temp = temp->getNext();
				}
			}
		}
	}
	// 특정한 성적을 받은 사람만 출력 + 그냥 출력
	void display(char grade = NULL, const char * major = NULL) {
		if (isEmpty())
			cout << "SingleLinkedList is Empty !!" << endl;
		else if (grade == NULL && major == NULL){
			Node * temp = head;
			for (; temp != NULL; temp = temp->getNext()) {
				cout << "Name : " << temp->getName() << "\t";
				cout << "Id : " << temp->getId() << "\t";
				cout << "Grade : " << temp->getGrade() << "\t";
				cout << "Major : " ;
				
				for(char * t = temp->getMajor(); *t != NULL; t++)
					cout << *t;
				cout << endl;
			}			
		}
		else if (grade != NULL){
			Node * temp = head;
			for (; temp != NULL; temp = temp->getNext()) {
				if (temp->getGrade() == grade) {
					cout << "Name : " << temp->getName() << "\t";
					cout << "Id : " << temp->getId() << "\t";
					cout << "Grade : " << temp->getGrade() << "\t";
					cout << "Major : ";

					for (char * t = temp->getMajor(); *t != NULL; t++)
						cout << *t;
					cout << endl;
				}	
			}
			
		}
		else {
			Node * temp = head;
			for (; temp != NULL; temp = temp->getNext()) {
				if (strcmp(temp->getMajor(),major) == 0) {
					cout << "Name : " << temp->getName() << "\t";
					cout << "Id : " << temp->getId() << "\t";
					cout << "Grade : " << temp->getGrade() << "\t";
					cout << "Major : ";

					for (char * t = temp->getMajor(); *t != NULL; t++)
						cout << *t;
					cout << endl;
				}
			}
		}
	}

	void concatenate(Node* list1head, Node* list2head) {
		// list 1이 빈 리스트일 때
		if (list1head == NULL) {
			head = new Node(list2head->getName(), list2head->getId(), list2head->getGrade(), list2head->getMajor());
			Node * temp = head;
			Node * linkNode = list2head->getNext();

			for (; linkNode != NULL; linkNode = linkNode->getNext(), temp = temp->getNext()) {
				temp->setNext(new Node(linkNode->getName(), linkNode->getId(), linkNode->getGrade(), linkNode->getMajor()));
			}
		}

		// list 2가 빈 리스트일 때
		else if (list2head == NULL) {
			head = new Node(list1head->getName(), list1head->getId(), list1head->getGrade(), list1head->getMajor());
			Node * temp = head;
			Node * linkNode = list1head->getNext();

			for (; linkNode != NULL; linkNode = linkNode->getNext(), temp = temp->getNext()) {
				temp->setNext(new Node(linkNode->getName(), linkNode->getId(), linkNode->getGrade(), linkNode->getMajor()));
			}
		}

		else {
			//오름차 순으로 합치기 !
			Node * temp = list1head;
			for (; temp != NULL; temp = temp->getNext()) 
				insert(temp->getName(), temp->getId(), temp->getGrade(), temp->getMajor());
			
			temp = list2head;
			for (; temp != NULL; temp = temp->getNext())
				insert(temp->getName(), temp->getId(), temp->getGrade(), temp->getMajor());	
		}
	}


	~SingleLinkedList() {
		if (!isEmpty()) {

			Node * del_node = head;
			Node * next_del_node = head->getNext();

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