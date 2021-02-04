#include <iostream>
#define MAX_COL 50

using namespace std;

struct Term {
	int row;
	int col;
	int value;
};

void fastTranspose(Term a[], Term b[]);

Term rowOrder[9], colOrder[9];

int main() {

	freopen("homework01-1.txt", "r", stdin);
	for (int i = 0; i < 9; ++i) {
		cin >> rowOrder[i].row >> rowOrder[i].col >> rowOrder[i].value;
	}

	fastTranspose(rowOrder, colOrder);


	for (int i = 0; i < colOrder->value+1; ++i) {
		printf("%3d %3d %3d\n", colOrder[i].row, colOrder[i].col, colOrder[i].value);

	}
	return 0;
}



void fastTranspose(Term rowOrder[], Term colOrder[]) {

	int row_terms[MAX_COL], startingPos[MAX_COL];
	int i, j, num_cols = rowOrder[0].col, num_terms = rowOrder[0].value;

	colOrder[0].row = num_cols;
	colOrder[0].col = rowOrder[0].row;
	colOrder[0].value = num_terms;

	if (num_terms > 0 ){
		for (i = 0; i < num_cols; i++) {
			row_terms[i] = 0;			
		}
		for (i = 1; i <= num_terms; i++) {
			row_terms[rowOrder[i].col]++;
		}

		startingPos[0] = 1;
		for (i = 1; i < num_cols; i++) {
			startingPos[i] = startingPos[i - 1] + row_terms[i - 1];
		}

		for (i = 1; i <= num_terms; i++) {					
			j = startingPos[rowOrder[i].col]++;
			colOrder[j].row = rowOrder[i].col;
			colOrder[j].col = rowOrder[i].row;
			colOrder[j].value = rowOrder[i].value;
		}

	}
}


