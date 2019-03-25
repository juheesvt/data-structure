#include <iostream>
#include <string>

using namespace std;

struct Figure {
	char name[9];
	float a = 0;
	float b = 0;
	float area = 0;
};

Figure figure[7];

void areaCalculate(Figure [], int);

int main() {

	FILE * fp =fopen("homework01-2.txt", "r");
	int numOfData = 0;
	


	for (int i = 0; fscanf(fp, "%d") != EOF; i++) {

		fscanf(fp,"%s", &figure[i].name);
		fscanf(fp,"%f", &figure[i].a);

		if (figure[i].name != "circle") {
			fscanf(fp,"%f", &figure[i].b);
		}
		numOfData++;

	}
	

	areaCalculate(figure, numOfData);

	for (int i = 0; i < numOfData; i++) {
		
		if ( ! strcmp(figure[i].name,"circle") ) {
			printf("%-10s %-11.2f %-7.2f\n", figure[i].name, figure[i].a, figure[i].area);
		}
		else {
			printf("%-10s %-5.2f %-5.2f %-7.2f\n", figure[i].name, figure[i].a, figure[i].b, figure[i].area);
		}
	}
	return 0;
}

void areaCalculate(Figure figure[], int numOfData) {

	for (int i = 0; i < numOfData ; i++) {
		
		if (!strcmp(figure[i].name, "circle"))
			figure[i].area = figure[i].a * figure[i].a * 3.14;

		else if (!strcmp(figure[i].name, "triangle"))
			figure[i].area = figure[i].a * figure[i].b * 0.5;

		else
			figure[i].area = figure[i].a * figure[i].b;
	}
}

