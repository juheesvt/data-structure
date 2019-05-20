#include "minHeap.hpp"

int main() {

	MinHeap mh;
	int input;

	// 임의의 숫자를 사용해 binary tree 구성하기
	int binTree[] = { 9,2,5,3,8 };
	cout << "( ";
	for (int i = 0; i < 5; i++) {
		cout << binTree[i] << " ";
	}
	cout  << ")"<< endl;

	// binary tree 에 있는 데이터를 한개씩 minHeap에 넣기
	for (int i = 0; i < 5; i++)
		mh.insert(binTree[i]);
	mh.display();

	while (true) {
		cout << "1. insert  2.delete  3.empty  4.full  5.depth  6.quit" << endl;
		cin >> input;

		if (input == 1) {
			int data;
			cout << "insert  ";
			cin >> data;
			mh.insert(data);
			cout << endl;

			mh.display();
		}
		if (input == 2) {
			cout << "Delete";
			mh.del();
			cout << endl;
		
			mh.display();
		}
		if (input == 3) {
			if (mh.isEmpty())
				cout << "Heap is empty" << endl;
			else
				cout << "Heap isn't empty" << endl;
		}
		if (input == 4) {
			if (mh.isFull())
				cout << "Heap is full" << endl;
			else
				cout << "Heap isn't full" << endl;
		}
		if (input == 5) {
			cout << "Depth : " << mh.level() << endl;
		}
		if (input == 6) {
			break;
		}
	}
	return 0;

}