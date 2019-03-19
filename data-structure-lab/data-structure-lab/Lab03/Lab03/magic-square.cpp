#include <iostream>

using namespace std;

void magicSquare(int);

int main() {

	int n;
	cout << "��� ���� �������� ����ڽ��ϱ� ? ( n * n ) n = ";
	cin >> n;

	magicSquare(n);
	return 0;
}

void magicSquare(int n) {

	// n x n ���� �迭 ũ�� ���� �迭 �� 0���� �ʱ�ȭ 
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