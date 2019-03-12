#include <iostream>

using namespace std;

int recursiveHanoi(int num, int start, int end, int assistant);

int main() {

	recursiveHanoi(3, 1, 3, 2);

}

int recursiveHanoi(int num, int start, int end, int assistant) {

	if (num == 1) {
		cout << start << "->" << end << endl;
		return 1;
	}
	recursiveHanoi(num - 1,start, assistant, end );
	cout << start << "->" << end << endl;
	recursiveHanoi(num - 1, assistant, end, start);
}