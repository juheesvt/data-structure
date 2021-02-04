#include <iostream>

using namespace std;

void recursivePermutation(int n, int r);     // nPm
int iterationPermutation(int n, int r);
void swap(int * a, int *b);
void print();

int arr[] = { 1,2,3 };
int cnt = 0;


void recursivePermutation(int n, int r) {

	if (!r) {
		print();
		return ;
	}

	for (int i = n - 1; i >= 0; --i) {

		swap(&arr[i], &arr[n - 1]);
		recursivePermutation(n - 1, r - 1);

		swap(&arr[i], &arr[n - 1]);
	}
		
}

void swap(int * a, int * b) {
	int temp =* a;
	* a =* b;
	* b = temp;
}

void print() {

	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

}

