# Homework #2 Document
> Name : 강주희  
> Student ID : 20181570  
> Program ID : Homework#2 

## Description 
- infix to postfix 는 수식의 중위표기를 후위표기로 바꾸는 것이다.
- infix notation 은 우리가 흔히 쓰는 2+3 같은 수식이고, fostfix notation은 23+ 같이 연산자가 피연산자 뒤에 온다.
- 컴퓨터가 수식을 인식하기에는 infix notation 보다 postfix notation 이 편하다.
- infix to postfix 변환과 변환된 postfix notation 계산에는 자료구조 stack이 사용된다.

## Algorithm 
- 데이터 처리는 자료구조 stack을 이용한다
- 열거형 타입 enum을 선언해 연산자에 숫자를 할당한다.
- 연산자 우선순위의 계산의 편의를 위해 isp(in-stack-precedence), icp(in-comming-precedence) 배열을 사용한다.
- ifstream의 getline 함수를 이용해서 텍스트 파일의 연산식을 한줄씩 읽어와 infixToPostfix 함수로 넘긴다.

- infixToPostfix 함수에서
    + char형 stack 객체를 만들어준다.
    + 변환된 postfix 수식을 저장할 postfix 배열을 만든다.
    + 생성된 stack 배열의 0번째 인덱스에 연산식의 끝을 알리는 ' ' 문자를 push한다.
    + 한줄씩 받아온 연산식(buff)을 가지고 변환을 시작한다.
    + 반복문을 이용해 getToken() 함수의 argument로 buff 배열의 i 번째 인덱스를 넘긴다.
    + getToken()은 입력받은 연산자(또는 피연산자)를 enum 형태로 넘겨주는 함수이다.
    + getToken() 에서 반환된 것이 피연산자면 postfix배열과 stack에 넣는다.   
    + getToken() 에서 반환된 것이 '('면 stack에 넣고, ')'이면 stack의 top요소고 '('일 때까지 pop하고 pop한 요소를 postfix에 넣는다.
    + 그리고 마지막으로 한번 더 pop해서 ')'를 제거해준다.
    + 만약에 getToken() 에서 반환된 것이 연산자면, 스택의 top요소와 buff[i]의 우선순위를 비교해,  
      buff에서 받아온 연산자의 우선순위가 높거나 같을 때만 buff[i]를 push해주고 아닐때는 stack의  
      top요소를 빼서 postfix 배열에 넣어주고 buff[i]를 push해준다.
    + 연산식을 도는 반복문이 끝나면, stack에 남아있는 연산자 및 피연산자를 postfix에 순서대로 넣어준다. (pop 이용)
    + 변환된 postfix 배열을 OperatePostfix로 넘겨서 후위 연산식을 계산한다.
    
- operatePostfix 함수에서
    + int 형 stack 객체를 만들어준다.
    + 연산할 숫자를 담는 int형 변수 op1, op2를 선언해준다.
    + postfix의 배열을 돌면서 getToken() 함수를 이용해 반환 값이 피연산자면 stack에 숫자로 저장한다.
    + 만약 getToken() 에서 반환된 값이 연산자면, stack에서 pop 두번을 해서  
      수식을 각각 op1과 op2에 저장하고 계산한 결과를 다시 stack에 넣어준다
    + 배열을 끝까지돌고 stack의 남은 값을 반환해주면 postfix 연산 완료 !
    
## Function

- main (hw02.cpp)
    + ifstream 함수를 이용해 데이터 파일을 불러온다.
    + while문을 이용해서 데이터 파일에 적힌 연산식을 한 줄씩 읽어와 buff 배열에 저장한다.
    + buff 배열에 저장한 연산식을 infixToPostfix 로 넘겨준다.

- infixToPostfix (hw02.cpp)
    + infix notation을 postfix notation으로 바꿔준다.
    + 변환된 후위 연산식을 콘솔창에 출력하고, postfix 배열에 저장한다.
    + postfix 배열을 operatePostfix 함수로 넘겨준다.

- operatePostfix (hw02.cpp)
    + 변환된 후위 연산식을 계산해 숫자를 반환한다.
    + 연산식을 읽고 계산하는 데에 switxh case 문을 사용한다.
    
- getToken (hw02.cpp)
    + 토큰을 받아서 해당 연산자를 enum으로 반환해준다.
    + 연산자의 우선순위를 계산하기 위해서 쓰인다.
 
 - Stack<T>::Stack() (stack.hpp)
     + T형 stack의 생성자로, top의 값을 -1로 초기화해준다.
     
 - Stack<T>::~Stack() (stack.hpp)
     + T형 stack의 소멸자로, stack 배열의 있는 데이터를 삭제해준다.
 
 - Stack<T>::push (stack.hpp)
    + stack 배열의 top (제일 맨 위) 에 데이터를 삽입한다.
    
 - Stack<T>::pop() (stack.cpp)
    + stack의 top 요소를 제거하고 반환한다.
    
 - Stack<T>::isEmpty (stack.hpp) 
    + stack이 비어있으면 1, 아니면 0을 반환한다.
    + top값으로 확인 !

- Stack<T>::isFull (stack.hpp)
   + stack이 최대크기만큼 차있으면 1, 아니면 0을 반환한다.
   + top과 sizeStack으로 확인 !
   
- Stack<T>::displau (stack.hpp)
   + stack의 있는 요소들을 다 출력시킨다.
   
- Stack<T>::getStackTop (stack.hpp)
   + stack을 pop()하지 않고도 stack의 top요소에 접근할 수 있도록 stack[top]을 반환해준다.

## 코드 상세 설명
- 전역 변수
    + Description
        * 파일 입출력을 위한 fstream을 include 한다.
        * stack.hpp 을 include 해서 stack 메서드를 사용한다.
        * 우선순위의 간편한 계산을 위해 enum 을 선언한다.
        * 구현할 함수의 prototype을 선언해준다.
        * 우선순위 비교를 위한 배열 isp, icp를 선언 및 초기화 해준다.
    + Variable
        * ```isp []``` : stack 속에 있는 연산자의 우선순위를 저장한 배열
        * ```icp []``` : buff 로 받아온 연산자의 우선순위를 저장한 배열

```c
#include <fstream>
#include "stack.hpp"

// 열거형 타입 precedence 선언
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;


void infixToPostfix(char []);
int operatePostfix(char []);
precedence getToken(char );


static int isp[] = { 0,19,12,12,13,13,13,0 };
static int icp[] = { 20,19,12,12,13,13,13,0 };
```

- main (hw02.cpp)
    + Description
        * ifstream 함수를 이용해 데이터 파일을 불러온다.
        * while문을 이용해서 데이터 파일에 적힌 연산식을 한 줄씩 읽어와 buff 배열에 저장한다.
        * buff 배열에 저장한 연산식을 infixToPostfix 로 넘겨준다. 
    + Variable
        * ```ifstream inFile``` : 연산식을 가져올 데이터 파일 객체이다.
        * ```char buff[sizeStack]``` : 데이터 파일에서 받아온 연산식을 저장할 배열이다.
```c
int main() {
	
	ifstream inFile("homework02.txt");
	char buff[sizeStack];
	
	while (inFile.getline(buff, 100)) {
		cout << "1) Echo data (infix form) : " << buff << endl;
		cout << "2) Conversion (postfix form) : ";
		infixToPostfix(buff);
		
	}
	return 0;
}
```

- infixToPostfix (hw02.cpp)
    * Description    
        + infix notation을 postfix notation으로 바꿔준다.
        + 변환된 후위 연산식을 콘솔창에 출력하고, postfix 배열에 저장한다.
        + postfix 배열을 operatePostfix 함수로 넘겨준다.
        
    * Variable
        + ```Stack <char> s``` : postfix notation으로의 변환을 위한 char형 스택
        + ```char postfix[sizeStack]``` : 변환된 postfix 수식을 저장할 배열
        + ```int pCnt``` : postfix 배열의 인덱스를 가리킬 변수
        + ```char token``` : buff를 다 돈 후, 스택에 남아있는 요소를 출력할 때 pop한 요소를 저장할 변수
```c
void infixToPostfix(char buff[]) {
	
	Stack<char> s;

	char postfix[sizeStack] = { 0, };
	int pCnt = 0;
	
	s.push(' ');
	
	for (int i = 0; buff[i] != '\0'; i++) {
		if (getToken(buff[i]) == operand) {
			cout << buff[i];
			postfix[pCnt++] = buff[i];
		}

		else if (getToken(buff[i]) == lparen)
			s.push('(');

		else if (getToken(buff[i]) == rparen) {
			while (s.getStackOfTop() != '(') {
				char temp = s.pop();
				cout << temp;
				postfix[pCnt++] = temp;
			}
			s.pop();						// remove '(' 
		}
		
		else {
			if (isp[getToken(s.getStackOfTop())] <= icp[getToken(buff[i])])
				s.push(buff[i]);
			else {
				char temp = s.pop();
				cout << temp;
				s.push(buff[i]);
				postfix[pCnt++] = temp;
			}
		}	
	}
	char token;
	// stack에 남아있는 연산자 및 피연산자 출력
	while (( token = s.pop()) != ' ') {
		postfix[pCnt++] = token;
		cout << token;
	}
	cout << endl;
	
	cout << "3) Result :  " << operatePostfix(postfix) << endl << endl;
		
}
```

- operatePostfix (hw02.cpp)
    * Description
        + 변환된 후위 연산식을 계산해 숫자를 반환한다.
        + 연산식을 읽고 계산하는 데에 switxh case 문을 사용한다.
    * Variable
        + ```Stack <int> p``` : 후위 연산식의 연산 결과를 저장할 스택
        + ```int op1, op2``` : 토큰이 연산자일때, 스택에서 pop한 숫자를 저장할 변수
```c
int operatePostfix(char postfix[]) {
	Stack<int> p;
	int op1, op2;

	for (int i = 0;  postfix[i] != '\0'; i++) {
		if (getToken(postfix[i]) == operand)
			p.push(postfix[i]-'0');	

		else {
			op2 = p.pop();
			op1 = p.pop();
			
			switch (postfix[i]) {
			case '+':
				p.push(op1 + op2);
				break;
			case '-':
				p.push(op1 - op2);
				break;
			case '*':
				p.push(op1*op2);
				break;
			case '/':
				p.push(op1 / op2);
				break;
			}
		}
	}
	return p.pop();
}
```

- getToken (hw02.cpp)
    * Description
        + 토큰을 받아서 해당 연산자를 enum으로 반환해준다.
        + 연산자의 우선순위를 계산하기 위해서 쓰인다.
    * Variable
        + ```char token``` : getToken() 의 parameter, 연산자를 받아온다.
```c
precedence getToken(char token) {
	
	switch (token) {
	case '(':
		return lparen;
	case ')':
		return rparen;
	case '+':
		return precedence::plus;
	case '-':
		return precedence::minus;
	case '/':
		return divide;
	case '*':
		return times;
	case '%':
		return mod;
	case ' ':
		return eos;
	default:
		return operand;
	}
}
```

- class Stack (stack.hpp)
    * Description
        + 자료구조 Stack을 구현한 클래스
        + char형과 int형의 스택을 둘다 쓰기위해 template 선언
    * Variable
        + ```const in sizeStack``` : 스택의 최대 크기를 나타내는 상수
        + ```T stack[sizeStack]``` : 데이터를 처리할 배열
        + ```int top``` : 스택의 가장 최근의 (맨 위쪽) 데이터를 가리키는 변수
        + ```T pop_val``` : pop() 한 데이터를 저장할 변수
```c
#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>

using namespace std;

const int sizeStack = 100;

template <typename T>
class Stack {
private:
	T stack[sizeStack] = { 0, };
	int top;

public:
	Stack() {
		top = -1;
	}
	~Stack() {
		for (; isEmpty() == false;) 
			pop();
	}
	void push(T val) {
		stack[++top] = val;
	}
	T pop() {
		T pop_val = stack[top];
		stack[top--] = NULL;
		return pop_val;
	}
	int isEmpty() {
		if (top == -1) 
			return 1;
		return 0;
	}
	int isFull() {
		if (top == sizeStack)
			return 1;
		return 0;
	}
	void display() {
		for (int i = 0; i < top; ++i) 
			cout << stack[i] << " ";
		cout << endl;
	}
	T getStackOfTop() {
		return stack[top];
	}
};
#endif
```
    




### 실행결과
![]()
