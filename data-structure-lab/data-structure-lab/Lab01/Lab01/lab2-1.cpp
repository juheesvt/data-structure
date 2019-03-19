#include <iostream>

using namespace std;

int recursiveBinarySearch(int data[], int target, int left, int right);
int iterationBinarySearch(int data[], int target, int left, int right);

int main() {

	int list[10] = { 10,20,30,40,50,60,70,80,90,100 };

	while (true) {

		int target, method;
		cout << "  Enter an integer to search : ";
		cin >> target;

		cout << "Enter method of search : (1. Binary Search  2. Recursive binary search) : ";
		cin >> method;

		if (method == 1) {

			int index = iterationBinarySearch(list, target, 0, sizeof(list) / sizeof(int));
			if (index == -1) {
				cout << target << " is NOT FOUND ! " << endl;
				break;
			}

			cout << target << " is at position" << index << endl;

		}

		else {


			int index = recursiveBinarySearch(list, target, 0, sizeof(list) / sizeof(int));
			if (index == -1) {
				cout << target << " is NOT FOUND ! " << endl;
				break;
			}

			cout << target << " is at position" << index << endl;

		}

	}

	return 0;
}



int recursiveBinarySearch(int data[], int target, int left, int right) {

	int middle = (left + right) / 2;

	if (left > right)
		return -1;

	else if (data[middle] < target)
		return recursiveBinarySearch(data, target, middle + 1, right);

	else if (data[middle] > target)
		return recursiveBinarySearch(data, target, left, middle - 1);

	else if (data[middle] == target)
		return middle;



}

int iterationBinarySearch(int data[], int target, int left, int right) {

	int middle;

	while (left <= right) {
		middle = (left + right) / 2;

		if (data[middle] == target)
			return middle;

		else if (data[middle] < target)
			left = middle + 1;

		else if (data[middle] > target)
			right = middle - 1;
	}
	return -1;
}