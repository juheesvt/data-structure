# Homework #1-2 Document
> Name : 강주희  
> Student ID : 20181570  
> Program ID : Homework#1 

### Description 
- 입력된 도형의 변의 정보를 가지고 넓이를 구해서 출력하는 프로그램이다.

### Algorithm 
- triangle, rectangle, circle 의 각 제원을 데이터 파일로 받아, 구조체 배열에 저장한다
- 도형의 이름마다 다른 넓이 공식을 이용해서 넓이를 계산한 후, 다시 구조체 배열에 저장한다 !
- 넓이 구하는 공식
    * circle : 반지름 x 반지름 x 3.14
    * triangle : 밑변 x 높이 x 0.5
    * rectangle : 가로 x 
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

struct Figure {					// 각 도형의 이름과 변의 길이( 반지름, 높이,변 등), 그리고 넓이를 멤버로 가진 구조체
	char name[9];
	float a = 0;				// a와 b는 삼각형인 경우에 각각 밑변과 높이,
	float b = 0;				// 사각형인 경우에는 각각 가로와 세로, 원인 경우에는 a가 반지름이고 b는 사용하지 않는다
	float area = 0;				// 계산된 넓이를 저장할 변수이다
};

Figure figure[7];				// 여러 도형의 정보를 저장할 Figure 타입 구조체 배열

void areaCalculate(Figure [], int);		// 넓이를 계산할 함수

int main() {

	FILE * fp =fopen("homework01-2.txt", "r");		// fopen 함수로 파일객체 fp를 만듬
	int numOfData = 0;					// 배열의 사이즈를 저장한 변수 
	


	for (int i = 0; fscanf(fp, "%d") != EOF; i++) {		// 파일의 끝을 만날 때까지

		fscanf(fp,"%s", &figure[i].name);		// fscanf를 이용해 타입을 지정해서 구조체 배열에 저장한다.
		fscanf(fp,"%f", &figure[i].a);

		if (figure[i].name != "circle") {		// 만약에 도형이름이 circle이 아니면 입력을 한번 더 받는다.
			fscanf(fp,"%f", &figure[i].b);
		}
		numOfData++;					// 포문 한번 돌 때마다 numOfData를 증가시켜서 구조체 배열의 크기를 구한다.

	}
	

	areaCalculate(figure, numOfData);			// 함수에 구조체 배열과 배열의 크기를 넘겨주어 넓이를 구한다.

	for (int i = 0; i < numOfData; i++) {			// 기존 데이터에 넓이 값이 더해진 구조체 배열을 출력하는 부분이다
								// 왼쪽부터 자리를 차지해서 일정간격을 유지하도록 하고 
		if ( ! strcmp(figure[i].name,"circle") ) {	//소수점 둘째자리까지 출력한다
			printf("%-10s %-11.2f %-7.2f\n", figure[i].name, figure[i].a, figure[i].area);  
		}
		else {
			printf("%-10s %-5.2f %-5.2f %-7.2f\n", figure[i].name, figure[i].a, figure[i].b, figure[i].area);
		}						// 원일때와 아닐 때로 나누어서 출력한다. 원은 제원의 정보가 하나이기 때문 !
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
		
		if (!strcmp(figure[i].name, "circle"))				// 도형이 원일 때
			figure[i].area = figure[i].a * figure[i].a * 3.14;	// 넓이 = 반지름 * 반지름 * 3.14

		else if (!strcmp(figure[i].name, "triangle"))			// 도형이 삼각형일 때
			figure[i].area = figure[i].a * figure[i].b * 0.5;	// 넓이 = 밑변 * 높이 * 0.5

		else								// 도형이 사각형이면
			figure[i].area = figure[i].a * figure[i].b;		// 넓이 = 가로 * 
	}
}
```

### 실행결과
![순서대로 도형의 이름, 각 제원의 길이, 넓이](https://github.com/juheesvt/data-structure/blob/master/homework/hw01-2%20%EC%8B%A4%ED%96%89%EA%B2%B0%EA%B3%BC.png)
