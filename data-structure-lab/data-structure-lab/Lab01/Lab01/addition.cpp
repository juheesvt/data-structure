#include <iostream>

using namespace std;

int recursiveAdd(int n, int m);
int iterativeAdd(int n, int m);

int main() {

	cout << recursiveAdd(3, 7) << endl;
	cout << iterativeAdd(4, 8) << endl;

	return 0;
}

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