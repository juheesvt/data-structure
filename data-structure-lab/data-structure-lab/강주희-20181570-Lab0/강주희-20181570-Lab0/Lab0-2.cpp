
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;


int main() {

	ifstream in("Lab0-2.dat");
	string line;
	int idx = 0;
	int sum;

	while (getline(in, line)) {
		cout << line << endl;
		cout << "The number of words : " <<line.length() << endl;
		sum += line.length();
		
	}

	cout << "total is : " << sum << endl;

	in.close();

	return 0;
}