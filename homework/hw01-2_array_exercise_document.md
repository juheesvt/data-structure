# Homework #1-2 Document
> Name : 강주희  
> Student ID : 20181570  
> Program ID : Homework#1 

### Description 
- 입력된 도형의 변의 정보를 가지고 넓이를 구해서 출력하는 프로그램이다.

### Algorithm 
- triangle, rectangle, circle 의 각 제원을 데이터 파일로 받아, 구조체 배열에 저장한다
- 도형의 이름마다 다른 넓이 공식을 이용해서 넓이를 계산한 후, 다시 구조체 배열에 저장한다 !
- 각 도형의 제원 및 넓이를 출력한다.

### Function
- main (hw01-2.cpp)
    + 초기 데이터가 저장되어있는 파일을 열어서 구조체 배열에 저장한다.
    + areaCalculate ( 넓이 계산하는 함수 ) 를 호출한다.
    + 도형의 넓이가 저장된 구조체 배열을 출력한다.
- areaCalculate (hw01-2.cpp)
    + strcmp를 이용해 도형의 이름을 구분하고 각 도형에 알맞는 넓이 공식을 사용해 계산된 넓이를 구조체 배열에 저장한다.
  
### 코드 상세 설명

- main (hw01-2.cpp)
    + Description
        * 초기 데이터가 저장되어있는 파일을 열어서 구조체 배열에 저장한다.
        * areaCalculate ( 넓이 계산하는 함수 ) 를 호출한다.
        * 도형의 넓이가 저장된 구조체 배열을 출력한다.
    + Variable
        * fp : 파일 객체
        * numOfData : 결과 데이터를 저장할 배열의 길이
        * figure[] : 각 도형의 이름과 제원을 저장할 구조체 배열
        
```c
#include <iostream>

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
```
        
- areaCalculate (hw01-2.cpp)
    + Description
        * strcmp를 이용해 도형의 이름을 구분하고 각 도형에 알맞는 넓이 공식을 사용해 계산된 넓이를 구조체 배열에 저장한다.
    + Variable
        * figure[] : 각 도형의 이름과 제원, 그리고 넓이를 저장할 구조체 배열
        * numOfData : 구조체 배열의 길이
        
```c
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
```

### 실행결과
![순서대로 도형의 이름, 각 제원의 길이, 넓이](https://github.com/juheesvt/data-structure/blob/master/homework/hw01-2%20%EC%8B%A4%ED%96%89%EA%B2%B0%EA%B3%BC.png)
