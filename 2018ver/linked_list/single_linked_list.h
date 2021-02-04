#pragma once
#ifndef SingleLINKEDLIST_H
#define SingleLINKEDLIST_H
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;


class SingleLinkedList {

private:
	Node * head;
	int tail;
public:
												
	SingleLinkedList();				
	bool isEmpty();	
	void insert(int data);			// 오름차순으로 정렬되게 집어 넣기 !						
	void del(int data);	
	int size();								
	void display();								
	int search(int data);						
	~SingleLinkedList();

};
#endif