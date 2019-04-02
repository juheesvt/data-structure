#include <fstream>
#include "stack.hpp"

// ������ Ÿ�� precedence ����
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;


void infixToPostfix(char []);
int OperatePostfix(char []);
precedence getToken(char );


static int isp[] = { 0,19,12,12,13,13,13,0 };
static int icp[] = { 20,19,12,12,13,13,13,0 };

int main() {
	
	ifstream inFile("homework02.txt");
	char buff[sizeStack];
	
	while (inFile.getline(buff, 100)) {
		cout << "1) Echo data (infix form) : " << buff << endl;
		cout << "2) Conversion (postfix form) : ";
		infixToPostfix(buff);
		
	}
	

	return 0;
}

//����ǥ�⸦ ����ǥ��� �ٲٴ� �Լ�
void infixToPostfix(char buff[]) {
	
	Stack<char> s;

	char postfix[sizeStack] = { 0, };
	int pCnt = 0;
	
	s.push(' ');
	
	for (int i = 0; buff[i] != '\0'; i++) {
		if (getToken(buff[i]) == operand) {
			cout << buff[i];
			postfix[pCnt++] = buff[i];
		}

		else if (getToken(buff[i]) == lparen)
			s.push('(');

		else if (getToken(buff[i]) == rparen) {
			while (s.getStackOfTop() != '(') {
				char temp = s.pop();
				cout << temp;
				postfix[pCnt++] = temp;
			}
			s.pop();						// remove '(' 
		}
		
		else {
			if (isp[getToken(s.getStackOfTop())] <= icp[getToken(buff[i])])
				s.push(buff[i]);
			else {
				char temp = s.pop();
				cout << temp;
				s.push(buff[i]);
				postfix[pCnt++] = temp;
			}
		}	
	}
	char token;
	// stack�� �����ִ� ������ �� �ǿ����� ���
	while (( token = s.pop()) != ' ') {
		postfix[pCnt++] = token;
		cout << token;
	}
	cout << endl;
	
	cout << "3) Result :  " << OperatePostfix(postfix) << endl << endl;
		
}

int OperatePostfix(char postfix[]) {
	Stack<int> p;
	int op1, op2;
	int n = 0; // ���� ��Ʈ���� ����

	for (int i = 0;  postfix[i] != '\0'; i++) {
		if (getToken(postfix[i]) == operand)
			p.push(postfix[i]-'0');	

		else {
			op2 = p.pop();
			op1 = p.pop();
			
			switch (postfix[i]) {
			case '+':
				p.push(op1 + op2);
				break;
			case '-':
				p.push(op1 - op2);
				break;
			case '*':
				p.push(op1*op2);
				break;
			case '/':
				p.push(op1 / op2);
				break;
			}
		}
	}
	return p.pop();
	
	return 0;
}


// �Է¿��� ��ū�� �޾Ƶ��̴� �Լ�
precedence getToken(char token) {
	
	switch (token) {
	case '(':
		return lparen;
	case ')':
		return rparen;
	case '+':
		return precedence::plus;
	case '-':
		return precedence::minus;
	case '/':
		return divide;
	case '*':
		return times;
	case '%':
		return mod;
	case ' ':
		return eos;
	default:
		return operand;
	}
}