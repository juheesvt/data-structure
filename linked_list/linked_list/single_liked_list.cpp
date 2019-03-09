#ifndef SINGLE_LINKED_LIST_CPP
#define SINGLE_LINKED_LIST_CPP
#include "single_linked_list.h"


SingleLinkedList::SingleLinkedList() {
	head = NULL;
	tail = 0;
}

bool SingleLinkedList::isEmpty() {
	if (head == NULL) 
		return true;
	
	return false;
}

void SingleLinkedList::insert(int data) {
	Node * node = new Node();
	node->setData(data);
	if (isEmpty()) 
		head = node;

	else{
		if (node->getData() < head->getData()){
			Node * temp = head;
			head = node;
			node->setNext(temp);
		}
		else {
			Node *temp = head;
			for (int i = 0;; ++i) {
				if (temp != NULL && temp->getNext() == NULL) {
					temp->setNext(node);
					break;
				}
				else if (node !=NULL && 
						temp!=NULL &&
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

void SingleLinkedList::del(int data) {

	if (!tail)
		cout << "SingleLinkedList is Empty !!" << endl;

	else {
		Node * pre_target_node = NULL;
		Node * target_node = head;
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
			if ( target_node != head && target_node->getNext() == NULL )
				in = false;
		}
		if (! in )
			cout << data << "가 list안에 없습니다." << endl;
	}	
}

int SingleLinkedList::size() {
	return tail;
}

void SingleLinkedList::display() {
	if( isEmpty() )
		cout << "SingleLinkedList is Empty !!" << endl;
	else {
		Node * temp = head;
		for (int i = 0; i < tail; ++i) {
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}
}

int SingleLinkedList::search(int data) {
	Node * temp = head;
	int index = -1;

	for (int i = 0; i < tail; ++i) {
		if (data == temp->getData()) {
			index = i;
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

SingleLinkedList::~SingleLinkedList() {

	if (!isEmpty()) {


		Node * del_node = head;
		Node * next_del_node = head->getNext();

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


#endif