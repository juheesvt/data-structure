#include <iostream>

using namespace std;

int recursiveFactorial(int n);
int iterationFactorial(int n);

int main() {

	cout << iterationFactorial(3) << " " << recursiveFactorial(3) << endl;
	return 0;
}

int recursiveFactorial(int n) {

	if (n == 1)
		return 1;
	return n * recursiveFactorial(n - 1);
}

int iterationFactorial(int n) {

	int fac = 1;
	for (int i = n; i > 1; --i) {
		fac *= i;
	}
	return fac;
}