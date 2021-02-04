#include <iostream>

using namespace std;

int recursiveDiff(int a, int b) {

	if (a == 0 || b == 0)
		return a + b;
	return recursiveDiff(a - 1, b - 1);
}