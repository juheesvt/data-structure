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

	// ������, �Ű������� �����Ϳ� ������ �켱����, �׸��� �ڽ� ��� �ΰ��� ����
	Node(int data = NULL, int prio = 4, Node* left = NULL, Node* right = NULL) {
		this->data = data;
		this->prio = prio;
		this->left = left;
		this->right = right;
	}

	// ������ ��� ������ �������ִ� ����
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

	// ��������� ���� �������� ���͵�
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
	//������ �켱������ ������ �������迭
	char prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

	Tree() { // ������ -> root�� NULL�� �ʱ�ȭ 
		root = NULL;
	}
	Node * getroot() {
		return this->root;
	}
	void buildTree(string s) {
		int i = 0;
		// ��Ʈ���� ���� �� ����
		while (s[i] != NULL) {
			// newNode�� �����԰� ���ÿ� data�� s[i]�� �־��� 
			Node * newNode = new Node(s[i]);
			int j = 0;
			for (; j < 4; j++) {
				// �������̸� ������� prio�� �켱���� ����
				if (newNode->getData() == prec[j][0]) {
					newNode->setPrio(prec[j][1]);
					break;
				}
			}
			// j == 4 �̸� ������
			if (j == 4) {
				operand(newNode);
			}

			// �ƴϸ� oper �Լ��� ȣ���Ѵ�.
			else {
				oper(newNode);
			}
			i++;
		}
	}

	void operand(Node * newNode) {
		// root�� NULL�̸� �� ��带 �ִ´�
		if (root == NULL) {
			root = newNode;
			return;
		}
		Node * temp = root;
		//������ �ڽ��� ���� ������ ��� Ÿ�� ����
		while (temp->getRight() != NULL)
			temp = temp->getRight();
		temp->setRight(newNode);

	}

	void oper(Node * newNode) {
		// �켱������ ��Ʈ���� �۰ų� ������ 
		// ����尡 root�� �ǰ�
		// root�� �� ����� �ڽ��� �ȴ� (����)
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
			cout << "(";

		display(temp->getLeft());
		cout << (char)(temp->getData());
		display(temp->getRight());

		if (temp->getData() < '0' || temp->getData() > '9')
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

	void draw(Node* ptr, int level) {
		if (ptr != NULL && level <= 7) {
			draw(ptr->getRight(), level + 1);
			for (int i = 1; i <= level - 1; i++)
				cout << "   ";
			cout << ptr->getData();
			if (ptr->getLeft() != NULL && ptr->getRight() != NULL)
				cout << "< " << endl;
			else if (ptr->getRight() != NULL)
				cout << "�� " << endl;
			else if (ptr->getLeft() != NULL)
				cout << "�� " << endl;
			else
				cout << endl;
			draw(ptr->getLeft(), level + 1);
		}

	}


};

int main() {


	string s;


	Tree t;
	cin >> s;

	t.buildTree(s);

	cout << "InOrder  :  ";
	t.inOrder(t.getroot());
	cout << endl;

	cout << "postOrder  :  ";
	t.postOrder(t.getroot());
	cout << endl;

	cout << "preOrder  :  ";
	t.preOrder(t.getroot());
	cout << endl;

	cout << "Evaluation  :  " << t.evalTree(t.getroot()) << endl;

	cout << "Tree structure :  ";

	cout << endl;
	cout << endl;

	t.draw(t.getroot(), 1);




}