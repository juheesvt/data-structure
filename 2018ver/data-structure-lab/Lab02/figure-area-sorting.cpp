#include<iostream>
#include<string>
using namespace std;

struct Area {
	string type;
	double a;
	double b=0;
	double area;
};

Area terms[7];

int main() {

	freopen("figure.txt", "r", stdin);
	for (int i = 0; i < 7; ++i) {
		cin >> terms[i].type;

		if (terms[i].type == "circle")
			cin >> terms[i].a;

		else
			cin >> terms[i].a >> terms[i].b;
		
	}




	return 0;
}