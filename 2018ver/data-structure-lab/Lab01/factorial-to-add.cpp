#include <iostream>

using namespace std;


void recursiveFacSum(int n);
void iterativeFacSum(int n);

int sum = 0;

void recursiveFacSum(int n) {

	if (n == 1) {
		cout << 1 << " = " << sum + 1 << endl;
		return ;
	}

	cout << n << " + ";
	sum += n;
	return recursiveFacSum(n - 1);
}

void iterativeFacSum(int n) {

	int sum = 0;

	if (n == 1) {
		cout << 1 << endl;
		return;
	}

	while (n != 1) {
		cout << n << " + ";
		sum += n;
		n -= 1;
	}
	cout << "1 = " << sum + 1 << endl;


}