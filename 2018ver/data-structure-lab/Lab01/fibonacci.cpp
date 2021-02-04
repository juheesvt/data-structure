#include <iostream>

using namespace std;

int iterationFibonacci(int n);
int recursiveFibonacci(int n);


int recursiveFibonacci(int n) {
	
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int iterationFibonacci(int n) {

	if (!n)
		return 0;

	if (n == 1)
		return 1;

	else {

		int c;
		int a = 0;
		int b = 1;

		for (int i = 0; i < n-1; ++i) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}