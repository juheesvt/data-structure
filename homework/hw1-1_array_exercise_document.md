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
```

### 실행결과
![Spare Matrix Transpose](https://github.com/juheesvt/data-structure/blob/master/homework/hw01-1%20%EC%8B%A4%ED%96%89%EA%B2%B0%EA%B3%BC.png)
