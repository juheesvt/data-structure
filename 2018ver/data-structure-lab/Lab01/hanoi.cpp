#include <iostream>

using namespace std;

void recursiveHanoi(int num, int from, int to, int y);

void recursiveHanoi(int num, int from, int to, int by) {

	if (num == 1) {
		cout << from << "->" << to << endl;
		return;
	}
	recursiveHanoi(num - 1,from, by, to );
	cout << from << "->" << to << endl;
	recursiveHanoi(num - 1, by, to, from);
}

