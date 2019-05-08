#include <iostream>
#include <string>

using namespace std;


class Node {
private:
	char data;
	int prio;
	Node* left;
	Node* right;

public:
	Node(int data = NULL,int prio = 4, Node* left = NULL, Node* right = NULL) {
		this->data = data;
		this->prio = prio;
		this->left = left;
		this->right = right;
	}
	void setData(int data) {
		this->data = data;
	}
	void setPrio(int prio) {
		this->prio = prio;
	}
	void setLeft(Node* left) {
		this->left = left;
	}
	void setRight(Node* right) {
		this->right = right;
	}
	char getData() {
		return this->data;
	}
	int getPrio() {
		return this->prio;
	}
	Node * getLeft() {
		return this->left;
	}
	Node * getRight() {
		return this->right;
	}
};

class Tree {
private:
	Node * root;
public:
	char prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

	Tree() {
		root = NULL;
	}
	Node * getroot() {
		return this->root;
	}
	void buildTree(string s) {
		int i = 0;
		while (s[i] != NULL) {
			Node * newNode = new Node(s[i]);
			int j = 0;
			for (; j < 4; j++) {
				if (newNode->getData() == prec[j][0]) {
					newNode->setPrio(prec[j][1]);
					break;
				}
			}
			if (j == 4) {
				operand(newNode);
			}
			else {
				oper(newNode);
			}
			i++;
		}
	}

	void operand(Node * newNode) {
		if (root == NULL) {
			root = newNode;
			return;
		}
		Node * temp = root;
		while (temp->getRight() != NULL)
			temp = temp->getRight();
		temp->setRight(newNode);
		
	}

	void oper(Node * newNode) {
		if (root->getPrio() >= newNode->getPrio()) {
			newNode->setLeft(root);
			root = newNode;
		}
		else {
			newNode->setLeft(root->getRight());
			root->setRight(newNode);
		}
	}

	int evalTree(Node * p) {
		Node * temp = p;
		int value;
		if (temp != NULL) {
			if (temp->getData() >= '0' && temp->getData() <= '9')
				value = temp->getData() - '0';
			else {
				int left = evalTree(temp->getLeft());
				int right = evalTree(temp->getRight());
				switch (temp->getData()) {
				case '+':
					value = left + right;
					break;
				case '-':
					value = left - right;
					break;

				case '*':
					value = left * right;
					break;

				case '/':
					value = left / right;
					break;
				}
			}
		}
		else
			cout << "Empty Tree" << endl;
		return value;
	}

	void display(Node * temp) {

		if (temp == NULL)
			return;
		if (temp->getData() < '0' || temp->getData() > '9')
			cout << "(" ;

		display(temp->getLeft());
		cout << (char)(temp->getData());
		display(temp->getRight());

		if(temp->getData() < '0' || temp->getData() > '9')
			cout << ")";
	}

	void inOrder(Node * ptr) {
		if (ptr) {
			inOrder(ptr->getLeft());
			cout << (char)ptr->getData();
			inOrder(ptr->getRight());
		}
	}

	void postOrder(Node * ptr) {
		if (ptr) {
			postOrder(ptr->getLeft());
			postOrder(ptr->getRight());
			cout << ptr->getData();
		}
	}

	void preOrder(Node * ptr) {
		if (ptr) {
			cout << ptr->getData();
			preOrder(ptr->getLeft());
			preOrder(ptr->getRight());
		}
	}


};