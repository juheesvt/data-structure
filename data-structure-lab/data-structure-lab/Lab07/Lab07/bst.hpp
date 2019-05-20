#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node * left;
	Node * right;
public:
	Node(int data = NULL, Node* left = NULL, Node* right = NULL) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	void setData(int data) {
		this->data = data;
	}
	void setLeft(Node* left) {
		this->left = left;
	}
	void setRight(Node* right) {
		this->right = right;
	}
	int getData() {
		return this->data;
	}
	Node * getLeft() {
		return this->left;
	}
	Node * getRight() {
		return this->right;
	}
};

class BinarySearchTree {
private:
	Node * root;
public:
	BinarySearchTree() {
		this->root = NULL;
	}
	Node* getRoot() {
		return this->root;
	}
	int isEmpty() {
		return root == NULL;
	}
	int search(int target) {
		if (isEmpty()) {
			cout << "Tree is Empty !!" << endl;
			return NULL;
		}
		Node* temp = root;
		for (; temp != NULL;) {
			if (temp->getData() == target)
				return target;
			else if (target < temp->getData()) {
				temp = temp->getLeft();
				continue;
			}
			else {
				temp = temp->getRight();
				continue;
			}
		}
		cout << "Not found" << endl;
	}

	Node* insert(Node * ptr,int data) {

		if (ptr == NULL) {
			ptr=new Node(data);
			if (isEmpty())
				root = ptr;
		}
		else if (data < ptr->getData())
			ptr->setLeft(insert(ptr->getLeft(), data));
		else
			ptr->setRight(insert(ptr->getRight(), data));
		return ptr;
	}
	Node* findMin(Node * ptr){
		if (ptr->getLeft() == NULL)
			return ptr;
		findMin(ptr->getLeft());
	}
	Node* del(Node * ptr,int data = 0) {
		if (!isEmpty()) {
			if (data < ptr->getData())
				ptr->setLeft(del(ptr->getLeft(), data));
			else if (data > ptr->getData())
				ptr->setRight(del(ptr->getRight(), data));
			else if (ptr->getLeft() == NULL && ptr->getRight() == NULL) { // leaf node
				if (ptr == root)
					root = NULL;
				ptr = NULL;
			}
			else if (ptr->getLeft() == NULL) {
				Node * temp = ptr;
				ptr = ptr->getRight();
				if (temp == root)
					root = ptr;
				delete temp;
			}
			else if (ptr->getRight() == NULL) {
				Node * temp = ptr;
				ptr = ptr->getLeft();
				if (temp == root)
					root = ptr;
				delete temp;
			}
			else {
				Node * temp = findMin(ptr->getRight());
				ptr->setData(temp->getData());
				ptr->setRight(del(ptr->getRight(), ptr->getData()));
			}

		}
		else 
			cout << "not found" << endl;
		return ptr;			
	}
	void draw() {
		display(root, 1);
	}
	void display(Node* ptr, int level) {
		if (ptr != NULL && level <= 7) {
			display(ptr->getRight(), level + 1);
			for (int i = 1; i <= level - 1; i++)
				cout << "   ";
			cout << ptr->getData();
			if (ptr->getLeft() != NULL && ptr->getRight() != NULL)
				cout << "< " << endl;
			else if (ptr->getRight() != NULL)
				cout << "¢Ö " << endl;
			else if (ptr->getLeft() != NULL)
				cout << "¢Ù " << endl;
			else
				cout << endl;
			display(ptr->getLeft(), level + 1);
		}
		
	}

	int leaf(Node *p) {
		if (p == NULL) {
			return 0;
		}
		if (p->getLeft() == NULL && p->getRight() == NULL)
			return 1;
		else
			return leaf(p->getLeft()) + leaf(p->getRight());
	}

	void Traverse(Node * ptr) {
		if (isEmpty()) {
			cout << "Tree is Empty" << endl;
			return;
		}

		inOrder(root); preOrder(root);  postOrder(root);
	}

	void inOrder(Node * ptr) {
		if (ptr) {
			inOrder(ptr->getLeft());
			cout << ptr->getData();
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

	void Delete() {
		if (isEmpty())
			cout << "Tree is Empty" << endl;
	}


};