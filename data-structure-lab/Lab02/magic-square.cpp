#include <iostream>

using namespace std;

void magicSquare(int);


void magicSquare(int n) {

	// n x n 으로 배열 크기 동적 배열 후 0으로 초기화 
	int ** magicSquareMatrix= new int*[n]();
	for (int i = 0; i < n; ++i)
		magicSquareMatrix[i] = new int[n]();

	for (int r = 0, c = n / 2, num = 1; num <= n * n; ++num) {
		magicSquareMatrix[r][c] = num;

		if (num % n == 0)
			r++;

		else {
			r--, c++;

			if (r < 0)
				r = n - 1;

			if (c > n - 1)
				c = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout <<magicSquareMatrix[i][j] << "  ";
		}
		cout << endl;
	}

	
}