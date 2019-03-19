#include <iostream>

using namespace std;

int recursiveAdd(int n, int m);
int iterativeAdd(int n, int m);

int recursiveAdd(int n, int m) {
	if (!n)

		return n + m;
	cout << "n = " << n << " " << "m = " << m << endl;
	return recursiveAdd(n - 1, m + 1);
}

int iterativeAdd(int n, int m) {

	while (n != 0) {
		cout << "n = " << n << " " << "m = " << m << endl;

		n -= 1;
		m += 1;	
	}
	return n + m;

}