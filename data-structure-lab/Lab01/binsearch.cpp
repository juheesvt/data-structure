#include <iostream>

using namespace std;

int recursiveBinarySearch(int data[], int target, int left, int right);
int iterationBinarySearch(int data[], int target, int left, int right);


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
	
	while (left <=right) {
		middle = (left + right) / 2;
		
		if (data[middle] == target) 
			return middle;

		else if (data[middle] < target)
			left = middle +1;

		else if (data[middle] > target)
			right = middle - 1;
	}
	return -1;
}