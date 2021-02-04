
#include "addition.cpp"
#include "factorial-to-add.cpp"
#include "difference.cpp"



int main() {

	int a, b, c;
		
	cout << "Enter number 1 : ";
	cin >> a;
	cout << endl;

	cout << "Enter number 2 : ";
	cin >> b;
	cout << endl;

	cout << "Addition Result is : " << recursiveAdd(a, b) << endl;
	cout << "Difference Result is : " << recursiveDiff(a, b) << endl;

	cout << "Enter a number : ";
	cin >> c;
	cout << endl;
		
	cout << "Result is : ";
	recursiveFacSum(c);

	
	return 0;
}
