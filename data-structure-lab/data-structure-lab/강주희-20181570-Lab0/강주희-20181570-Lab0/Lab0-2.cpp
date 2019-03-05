
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;


int main() {

	ifstream in("Lab0-2.dat");
	string line;
	int idx = 0;
	int sum=0;
	

	while (getline(in, line)) {

		int word_num = 0;
		cout << line << endl;

		for (int i = 0; i < line.length(); ++i) {
			if (line[i] == ' ')
				word_num += 1;
		}
		cout << "The number of words : " << word_num << endl;
		sum += word_num;
		
	}

	cout << "total is : " << sum << endl;

	in.close();

	return 0;
}