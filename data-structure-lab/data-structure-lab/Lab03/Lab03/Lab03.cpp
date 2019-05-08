#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;


char parentheses[50];
int print(char []);
int match(char, char);

int main() {
	
	ifstream inFile("Lab03.txt");
	int i = 0;
	while (!inFile.eof()) {

		inFile.getline(parentheses, 50);

		switch (print(parentheses)) {
		case 1:
			cout << parentheses << "" << "Valid" << endl;
			break;
		case 0:
			cout << parentheses << "" << "Invalid(Unbalanced parentheses)" << endl;
			break;
		case -1:
			cout << parentheses << "" << "Invalid (Mismatched parentheses)" << endl;
			break;

		}
	}
	
	return 0;
}


int print(char parentheses[]) {
	
	Stack s;

	for (int i = 3; parentheses[i] != ' '; i++) {
		if ((parentheses[i] == '(' || parentheses[i] == '{' )|| parentheses[i] == '[') {
			s.push(parentheses[i]);
		}
		if ((parentheses[i] == ')' || parentheses[i] == '}') || parentheses[i] == ']') {
			if (s.isEmpty())
				return 0;		// unbalance
			else {
				char temp = s.pop();
				if (! match(temp, parentheses[i]))
					return -1;		// mismatch
			}
		}
	}

	if (s.isEmpty())	
		return 1;
	else
		return 0;
}

int match(char a, char b) { // a가 pop 한거 ({[ b가 ]})
	if (a == '(') {
		if (b == ')')
			return true;
		else
			return false;
	}
	else if (a == '{') {
		if (b == '}')
			return true;
		else
			return false;
	}
	else {
		if (b == ']')
			return true;
		else
			return false;
	}

}