#include "polynomial.cpp"

int main() {

	freopen("polynomial.txt", "r", stdin);

	for (int i = 0; i < 4; ++i) {
		startA = 0;
		cin >> terms[i].coef >> terms[i].expon;
		avail++;
	}
	finishA = avail - 1;

	for (int i = finishA + 1; i < 8; ++i) {
		startB = finishA + 1;
		cin >> terms[i].coef >> terms[i].expon;
		avail++;
	}
	finishB = avail - 1;

	polyAdd(startA, finishA, startB, finishB);


	for (int i = finishB + 1; i < avail; ++i) {
		cout << terms[i].coef << "     ";
	}
	cout << endl;

	for (int i = finishB + 1; i < avail; ++i) {
		cout << terms[i].expon << "    ";
	}
	cout << endl;

}
