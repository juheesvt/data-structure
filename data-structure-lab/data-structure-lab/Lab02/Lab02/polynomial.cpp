#include <iostream>


using namespace std;

int compare(int , int );
void polyAdd(int, int, int, int);
void attach(int, int);

const int MAX_TERMS = 100;

struct  Polynomial {
	int coef;
	int expon;
};

Polynomial terms[MAX_TERMS];

int avail=0;
int startA, finishA, startB, finishB;

int main() {

	freopen("polynomial.txt", "r", stdin);

	for (int i = 0; i < 6; ++i) {
		startA = 0;
		cin >> terms[i].coef >> terms[i].expon;
		avail++;
	}
	finishA = avail-1;
	
	for (int i = finishA + 1 ; i < 10; ++i) {
		startB = finishA+1;
		cin >> terms[i].coef >> terms[i].expon;
		avail++;
	}
	finishB = avail-1;

	polyAdd(startA, finishA, startB, finishB);


	for (int i = finishB +1 ; i < avail; ++i) {
		cout << terms[i].coef << "       ";
	}
	cout << endl;

	for (int i = finishB +1 ; i < avail; ++i) {
		cout << terms[i].expon << "      ";
	}
	cout << endl;



}



void polyAdd(int startA, int finishA, int startB, int finishB) {

	float coefficient;

	while ((startA <= finishA) && (startB <= finishB)) {
		

		switch (compare(terms[startA].expon, terms[startB].expon)) {

		case -1:
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient) {
				attach(coefficient, terms[startA].expon);
				startA++;
				startB++;
				break;
			}

		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	}

	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);

	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);



}

int compare(int a, int b) {

	if (a < b)		
		return -1;
	else if (a == b)		
		return 0;
	else		
		return  1;
}

void attach(int coefficient, int exponent) {
	if (avail >= MAX_TERMS) 
		cout << " too many elements..";

	else {
		terms[avail].coef = coefficient;
		terms[avail++].expon = exponent;
	}
}