# Homework #1-1 Document
> Name : 강주희  
> Student ID : 20181570  
> Program ID : Homework#1 

### Description 
- Spare Matrix는 희소 행렬이다. 의미 없는 데이터가 많은 희소행렬을 0이 아닌 데이터와 그 데이터의 행과 열의  
  3-tuples로 저장하면 시간 및 공간이 절약된다. 효율적으로 희소행렬을 표현할 때, row major와 column major 로   
  표현 할 수 있는데, 이번 과제에서는 row major를 column major로 변환할 것이다.  
- 구현 알고리즘은 **fast transpose algorithm**을 사용할 것인데, 그 이유는 nomal transpose보다 연산속도가 빠르기 때문이다.

### Algorithm 
- rowOrder 배열에 초기 데이터를 넣어준다. 
- 전치한 데이터를 넣어줄 colOrder 배열의 0번째 인덱스에 원래 데이터의 행렬의 수와 데이터의 수를 넣어준다.
- 유효한 데이터의수가 1개 이상 있을 때 즉, 영행렬이 아닐 때를 전제 조건으로 시작한다.
- 먼저 기존 배열의 column 수 만큼 row_terms를 0 으로 초기화 한다.  
- 그 다음에 원래 행렬의 각 열에 대한 원소 수를 먼저 구해 전치 행렬에서 각 행에 대한 원소 수를 결정한다 !
- 위의 정보로부터 전치 행렬에서 각 행의 시작위치를 구하고 원래 행렬에 있는 원소를 하나씩 전치 행렬의 올바른 위치로 옮기는 것이다.
- 각 열에 대한 원소 수를 구했다면, startingPos라는 배열을 만드는데 이 배열은 전치행렬에서 각 행의 시작위치를 저장한 것이다.
- startingPos[0]은 1로 초기화해준다. 왜냐면 전치행렬의 0 번째 인덱스는 행렬의 갯수와 원소 수가 저장되어있기 때문이다.
- startingPos에는 그 전의 시작지점(startingPos[i-1])에 그 열에 해당하는 원소 수를 더해서 저장한다.
- 이제 마지막으로 데이터를 저장하면 되는데, 위에서 만든 startingPos 배열을 이용해 해당 열에 대한 데이터를 가져와서 저장한다 !

### Function
- main (hw01-1.cpp)
  * freopen을 이용해 파일을 열어서 전치할 배열에 초기 데이터를 삽입한다.
  * fastTranspose 함수를 실행해 행 우선 배열을 전치시킨다.
  * 전치된 배열을 출력한다.
- fastTranspose (hw01-1.cpp)
  * 위에서 설명한 fastTranspose algorithm을 구현한다.
  
### 코드 상세 설명

- main (hw01-1.cpp)
  + Description
    * freopen을 이용해 파일을 열어서 전치할 배열에 초기 데이터를 삽입한다.
    * fastTranspose 함수를 실행해 행 우선 배열을 전치시킨다.
    * 전치된 배열을 출력한다.
  + Variable
    * Term : 희소행렬을 효율적으로 저장하기 위해 만든 struct로, row, column과 해당 데이터를 저장한다.
    * rowOrder, coluOrder : 데이터를 저장하기 위한 Term형 구조체 배열이다. 각각 행우선, 열우선 배열이다.

``` c
#include <iostream>
#define MAX_COL 50

using namespace std;

struct Term {			// 효율적인 희소행렬에 들어갈 데이터
	int row;
	int col;
	int value;
};

void fastTranspose(Term a[], Term b[]);		// fastTranspose 알고리즘을 수행할 함수의 prototype

Term rowOrder[9], colOrder[9];			// 처음에 주어질 행우선 배열과, 전치된 열우선 배열을 저장할 구조체 배열 선언

int main() {

	freopen("homework01-1.txt", "r", stdin);		// freopen으로 파일을 열어 stdin 입력으로 넘겨준다.
	for (int i = 0; i < 9; ++i) {				// 원소 수만큼 for문을 돌면서
		cin >> rowOrder[i].row >> rowOrder[i].col >> rowOrder[i].value;		// 순서대로 row, col, value에 저장해준다.		
	}

	fastTranspose(rowOrder, colOrder);			// fastTranspose 함수를 호출한다.
	
	
	// 전치된 colOrder matrix를 출력한다.
	for (int i = 0; i < colOrder->value+1; ++i) {		// 각 열에 대한 원소 수 + 맨 위에 행과 열 원소수를 표시할 한줄을 추가 ! 
		printf("%3d %3d %3d\n", colOrder[i].row, colOrder[i].col, colOrder[i].value);		// 간격 유지를 위해 3칸씩 차지
	}
	return 0;
}
```

- fastTranspose (hw01-1.cpp)
    + Description
        * row major matrix를 받아 fast transpose algorithm을 수행한다.
    + Variable
        * rowOrder[] : 전치할 행렬의 데이터를 담은 배열
        * colOrder[] : rowOrder 배열을 전치시켜서 데이터를 저장할 배열, 최종 결과물 !
        * row_terms[] : 해당 인덱스의 열의 원소 수를 저장하는 배열 ! 
        * startingPos [] : 해당 인덱스의 열의 원소가 저장되기 시작할 위치를 저장하는 배열 !
        * i : for문에서 인덱스를 지정할 변수 
        * j : startingPos에서 전치할 배열의 해당 열의 시작지점을 저장할 변수. 시작지점을 할당하고, startingPos는 증가시킨다.
        * num_cols : 전치할 배열의 열의 개수를 저장하는 변수
        * num_terms : 전치할 배열의 원소 수를 저장할 변수 
	
```c
void fastTranspose(Term rowOrder[], Term colOrder[]) {

	int row_terms[MAX_COL], startingPos[MAX_COL];				// 인덱스에 해당하는 열의 갯수를 저장하는 배열 row_terms, 
										// 각 열의 시작지점을 저장해놓은 배열 startingPos 선언
	int i, j, num_cols = rowOrder[0].col, num_terms = rowOrder[0].value; 	// 반복문에서 index를 표시할 변수 i와
										// startingPos의 정보를 저장할 j
										// num_cols와 num_terms에는 각각 행과 원소 수를 할당함

	colOrder[0].row = num_cols;			// colOrder의 행 정보에 기존 행렬의 row값 할당
	colOrder[0].col = rowOrder[0].row;		// colOrder의 열 정보에 기존 행렬의 column값 할당
	colOrder[0].value = num_terms;			// colOrder의 원소 수 정보에 기존 행렬의 원소 수값 할당

	if (num_terms > 0 ){				// 영행렬이 아닐 때, 즉 행렬의 크기가 1이상일 때
		for (i = 0; i < num_cols; i++) {	
			row_terms[i] = 0;		// 데이터가 존재하는 column 만큼 row_terms를 0으로 초기화 시켜준다.	
		}
		for (i = 1; i <= num_terms; i++) {
			row_terms[rowOrder[i].col]++;	// 기존행렬의 행을 row_terms의 index로 표현하여 데이터 가있는 index의 값을 증가시킴. 
		}

		startingPos[0] = 1;			// startingPos[0]을 1로 초기화 시킨 이유 : 0에는 행렬과 원소수의 정보가 있기 때문 !
		for (i = 1; i < num_cols; i++) {
			startingPos[i] = startingPos[i - 1] + row_terms[i - 1];		// 시작위치 + 데이터의 수 = 다음 행의 시작위치
		}

		for (i = 1; i <= num_terms; i++) {					
			j = startingPos[rowOrder[i].col]++;		// j에 startingPos을 이용해 해당 열에 대한 데이터의 시작위치를 저장									     // 하고 startingPos를 증가시킨다. 
			colOrder[j].row = rowOrder[i].col;		// 행과 열을 전치 시켜서 colOrder 배열에 
			colOrder[j].col = rowOrder[i].row;
			colOrder[j].value = rowOrder[i].value;
		}

	}
}
```

### 실행결과
![Spare Matrix Transpose](https://github.com/juheesvt/data-structure/blob/master/homework/hw01-1%20%EC%8B%A4%ED%96%89%EA%B2%B0%EA%B3%BC.png)
