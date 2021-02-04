#include "tree-build.hpp"
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

	t.draw(t.getroot(),1);




}