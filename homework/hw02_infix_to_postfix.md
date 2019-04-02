# Homework #2 Document
> Name : 강주희  
> Student ID : 20181570  
> Program ID : Homework#2 

### Description 
- infix to postfix 는 수식의 중위표기를 후위표기로 바꾸는 것이다.
- infix notation 은 우리가 흔히 쓰는 2+3 같은 수식이고, fostfix notation은 23+ 같이 연산자가 피연산자 뒤에 온다.
- 컴퓨터가 수식을 인식하기에는 infix notation 보다 postfix notation 이 편하다.
- infix to postfix 변환과 변환된 postfix notation 계산에는 자료구조 stack이 사용된다.

### Algorithm 
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
    
### Function

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

### 코드 상세 설명

### 실행결과
![Spare Matrix Transpose](https://github.com/juheesvt/data-structure/blob/master/homework/hw01-1%20%EC%8B%A4%ED%96%89%EA%B2%B0%EA%B3%BC.png)
