#include <stdio.h>

int main() {

	int i, j = 1;
	int num;

	scanf("%d", &num);

	for (i = 1; i < num + 1; i++)
		j *= i; // j = j *i



	printf("%d", j);


	return 0;
}