#include <stdio.h>

int main() { 

	int a,i,p;
	scanf("%d", &a);

	for (i = 1; i< a; a--) // a가 1이 될때까지 
		p = a * (a - i);
	
	printf("%d", p);

	return 0;
	
	
	

	/*
	for 과 while 의 차이점 ?
	for 는 내가 몇번 반복할 수 있는지 앎
	while은 내가 몇번 반복할 수 있을지 모름.*/

	//무한루프 : while() 인자에 0을 제외한 정수를 입력하면 조건은 무조건 참임. break 가 없으면 계속 돌아감
	// break 는 단독사용 불가능
	//continue 밑에있는 코드를 실행하지않고 조건을 검사하러감
	//do ~ while은 먼저 실행하고 조건을 검사함. while은 조건을 먼저 확인하고 실행
	/*
	반복문의 3요소
	1. 변수선언
	2. 조건검사
	3. 반복조건을 거짓으로 만들기 위한 연산
	*/

	//for(초기식; 조건식;증감식);
	//초기식, 조건식, 실행, 증감식 순으로 실시됨.
	//for 문안에서 만들어진 변수는 범위가 끝나면 메모리에서 사라짐. 때문에 먼저 ! 선언해줘야함
	//삼항연산자
	// (조건1 > 조건 2)? (참이면실행) : (거짓이면실행);
	//switch(변수)
	// case 숫자
	//default 나머지경우

	//break를 꼭 써야하는데 안쓰면 만족하는  case부터 그 밑에가 다 실행이 된당
	/*
	전달인자 반환값이 있는경우
	double add(int a, intb) {

	double t = a + b; // 7이 저장이 됌

	return t;
	}


	int main(){

	int n = 4, m = 3;
	int sum = add(n, m); //sum 에 7이 저장됨 위에 에드함수에서 반환이 됌.
	}

	*/

	/*
	double add() {

	double t = a + b; // 7이 저장이 됌

	return ;
	}


	int main(){

	int n = 4, m = 3;
	int sum = add(); //sum 에 7이 저장됨 위에 에드함수에서 반환이 됌.
	}

	반환값이 없기 때문에 sum에 대입을 할수가 없음 ~

	*/



	//값을 반환하지 않는 리턴 void 일때 !
	/*
	함수를 왜 쓸까?
	=>  main에다가 다쓸수 있지만 길어지면 가독성이 줄어듦.
	특정작업을 하는 코드를 따로 모아두고싶을때
	디버깅할때 편하게 하려고
	반복을 줄일 수 있다..?*/

	// 지역변수 블록안에서만 쓸수 있고 전역변수는 전체에서 쓸 수 있음.
	//전역변수는 main 밖에다가 쓰면댐 
	//지역변수에  static 을 붙이면 전역변수처럼 성격이 변함
	/*
	재귀함수란 ? 함수가 자기자신을 부르는 것
	알고리즘할 때 많이 쓰임
	탈출조건이 존재함. 자기자신을 부르다가 빠져나갈 조건

	*/
	/*

	int factorial(int n) {
	if ( n ==0)
	return 1;
	else
	return n *factorial(n - 1);
	}

	int main(){
	int result =1;
	int input;
	scanf/

	*/



	}