// 강주희 20181570 Lab0-1

#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

void start();
int min();
int max();

int max_position;
int min_position;

int main(void) {
	
	string modify;
	cout << "파일을 수정하시겠습니까 ? (yes or no)" << endl;
	cin >> modify;

	if (modify == "yes")
		start();
	
	cout << "Minimum number is " << min() << "position is" << min_position << "," <<endl;
	cout << "Maximum number is " << max() << "position is" << max_position << endl;

}

void start() {

	ofstream out("Lab0-1.dat");
	int number;

	for (int i = 0; i < 10; ++i) {
		cin >> number;
		if (out.is_open()) {
			out << number << endl;
		}
	}

	double num = 10;
	(int)num;
	int n = 10;
}

int min() {
	ifstream in("Lab0-1.dat");
	string line;
	int num_arr[10];
	int idx = 0;


	while (getline(in, line)) {
		num_arr[idx] = stoi(line);
		idx += 1;
	}

	in.close();

	int min = num_arr[0];
	for (int i = 0; i < 10; ++i ) {
		if (num_arr[i] < min) {
			min = num_arr[i];
			min_position = i;
		}

	}

	return min;
}


int max() {
	ifstream in("Lab0-1.dat");
	string line;
	int num_arr[10];
	int idx = 0;


	while (getline(in, line)) {
		num_arr[idx] = stoi(line);
		idx += 1;
	}

	in.close();

	int max = num_arr[0];
	for (int i = 0; i < 10; ++i) {
		if (num_arr[i] > max) {
			max = num_arr[i];
			max_position = i;
		}
	}
	return max;
}


