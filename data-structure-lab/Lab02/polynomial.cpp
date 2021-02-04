#include <iostream>
using namespace std;

int compare(int, int);
void polyAdd(int, int, int, int);
void attach(int, int);

const int MAX_TERMS = 100;

struct  Polynomial {
	int coef;
	int expon;
};

Polynomial terms[MAX_TERMS];

int avail = 0;
int startA, finishA, startB, finishB;



void polyAdd(int startA, int finishA, int startB, int finishB) {

	int coefficient;

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
			else {
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