#include "bst.hpp"


int main() {

	BinarySearchTree bst;

	bst.Delete();
	bst.Traverse(bst.getRoot());


	bst.insert(bst.getRoot(), 30);
	bst.insert(bst.getRoot(), 40);
	bst.insert(bst.getRoot(), 20);
	bst.insert(bst.getRoot(), 10);
	bst.insert(bst.getRoot(), 50);
	bst.draw();

	cout << " Leaf : " << bst.leaf(bst.getRoot()) << endl;

	bst.del(bst.getRoot(), 20);
	bst.draw();
	
	bst.del(bst.getRoot(), 50);
	bst.draw();

	bst.del(bst.getRoot(), 30);
	bst.draw();

	bst.search(30);
	cout << bst.search(10) << endl;

	bst.Traverse(bst.getRoot());
	
	
}