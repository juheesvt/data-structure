#include "tree-build.hpp"
#include <fstream>

int main() {

	string s;

	
	ifstream inf("input.txt"); 

	while(!inf.eof()) {
		Tree t;
		char cstr[50] = { 0, };
		inf.getline(cstr, 50);
		s = cstr;
		

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
		t.display(t.getroot());

		cout << endl;
		cout << endl;

		t.draw(t.getroot(), 1);
	}

}