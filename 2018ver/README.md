 # C로 자료구조 공부하기 전에 알아야 할 것들 
> - 구조체 정의 및 구조체 대상의 typedef 선언
> - malloc 함수와 free 함수 사용과 이 함수들이 메모리 동적할당과 관련된 것 이라는 것
> - 헤더 파일이 필요한 이유
> - 헤더 파일 정의 및 헤더 파일에 들어가야 할 것
> - 헤더 파일 정의에 사용되는 매크로 #ifdef ~ #endif
> - 하나의 프로그램을 둘 이상의 소스파일과 헤더파일에 나눠 담을 줄 알아야 함.
> - 재귀함수의 동작방식  
 
 
#### 구조체 정의 및 구조체 대상의 typedef 선언
 ```c
 typedef int Pair[2];
   Pair point = { 3,4 };
 
 
 struct Time {
   int h, m, s;

   // 구조체내에 정의된 변수들에 접근가능
   int totalSec() {
      return 3600*h + 60*m + s;
   }
};
 ```
#### 동적할당과 malloc 함수
 C언어에서는 메모리 할당 방식에 2가지 종류가 있다 
 - 정적 할당 : 프로그램 실행 전 _변수의 저장공간을 먼저 할당_ 후 프로그램 종료시 해제
 Ex) int a[10] = 0;
 - 동적 할당 : 프로그램 실행 중 _필요한 만큼의 메모리를 할당_ 후 원할때 해제.
 
 #### 동적할당은 언제, 왜 필요한가요 ?
 정적 할당으로 배열의 크기를 잡고 나서 데이터를 집어넣을 때 메모리가 낭비되거나 오버플로우가 생기는 경우가 반드시 존재합니다 !
 예를 들어 같은 반 학생들의 집주소를 저장할 때, 영어 이름을 저장하는 배열을 만들 때등등
 
 #### 동적할당의 사용 방법
 malloc 함수로 동적할당을 할 수 있음 ( C 표준 라이브러리로 stdlib.h 에 정의 )
 
 |함수|기능|
 |:--------|:--------|
 | void * mallod (size_t size); | size 바이트의 메모리를 힙에서 할당하여 반환한다.|
 | void * calloc ( size_t num, size_t size ); | (num * size ) 바이트의 메모리를 힙에서 할당하고 포인터 값을 반환한다. |
 | void * realloc ( void * ptr, size_t size ); | ptr이 가리키는 메모리를 size 바이트 만큼 힙에서 재할당하여 반환한다. |
 | void free (void * prt ); | ptr이 가리키는 메모리를 해제한다. 해제 전까지는 계속 존재하므로 필요없으면 이 함수로 해제해야한다. |
 
 ##### malloc 함수
 예를 들어 malloc(4) 를 하면 4byte 만큼의 메모를 할당 받는다.
 ```C
 int * i = (int*) malloc (sizeof(int));
 ```
 ![](https://github.com/juheesvt/data-structure/blob/master/malloc.PNG)
 
 위와 같이 i라는 포인터 변수를 선언하고 i 값에 다가 메모리를 할당하는 것 !
 만약 malloc(sizeof(int)) 는 그대로 하고 앞에 int* 를 short 형으로 바꾼다면  
 i라는 변수는 short형의 크기의 배열 2개가 선언된다 !  
 ###### input을 받아 input만큼 배열의 크기를 할당받고 싶다면 ?
 ```c
 int *arr = (int*) malloc(sizeof(int)*input);
 ```  
 ##### free 함수
 할당된 메모리를 해제하는 함수이다.
 메모리를 할당받고 메모리가 해제되지 않으면 할당받은 메모리는 사용이 끝났음에도 불구하고 컴퓨터가 종료되기 전까지 해당 메모리를 차지하게 된다.
 때문에 동적할당 후 더 이상 필요하지 않으면 꼭 free 함수로 메모리를 해제 시켜주어야 한다 !  
 위에서 할당한 메모리를 해제 시키려면 
 ```c
 free(arr);
 ```
 ##### 동적할당에서 주의해야 할 점 : 메모리 누수
 free 함수를 써서 메모리를 해제해주지 않으면 할당된 메모리가 계속 남아있는데, 이로 인해 _메모리 누수_ 가 생길 수 있다.  
 예를 들어, 내가 포인터 변수 a 에 4byte 만큼의 메모리를 할당했다고 하자.  
 깜빡하고 free함수를 쓰지 않은 채 프로그램이 종료되면 포인터 변수 a에 대한 주솟값이 사라진다.
 a의 주소가 사라져 a에 접근하지 못하기 때문에 포인터 변수 a에 의해 할당된 메모리를 해제해줄 수 없다.  
 때문에 접근할 수 없어서 해제할 수 없는 메모리가 생기는 것이다 ! 
 
 이해가 어렵다면 다음 그림과 _간접 주소 지정 방식_ 을 참고해보면 좋다.
 
 ![memory leak 이해를 위한 이미지](https://github.com/juheesvt/data-structure/blob/master/memory%20leak.png)
 
 
 4. **헤더 파일** 
 
 ##### 헤더 파일
 - 컴파일러에 의해 다른 소스 파일에 자동으로 포함된 소스 코드의 파일
 - 일반적으로 다른 소스 파일(.cpp) 속의 첫 부분에 포함 됨
 - .h 확장자를 가짐
 ```c
 #include <filename>
 ```
 - `<>`는 컴파일러와 함께 제공되는 헤더파일을 include할 때 사용 ! 
 - 위 헤더 파일은 C++ 런타임 라이브러리의 헤더 파일로써 운영체제의 특별한 위치에 존재
 ```c
 #include "filename"
 ```
 - `""`는 소스 파일이 있는 directory에서 헤더 파일을 include 하도록 전처리기(preprocesser)에게 지시.
 - 일반적으로 자신이 작성한 헤더 파일은 이 방법으로 include함

 ##### 헤더 파일이 필요한 이유 및 헤더파일과 기능 구현 소스 파일을 분리하는 이유 !  
 
 - 헤더 파일은 우리가 사용할 함수를 선언해놓은 파일이라고 할 수 있다.  
 - 보통 헤더 파일에는 선언만 해놓고 기능구현은 cpp 파일에 따로 한다.  
 - cpp 파일에 선언 및 구현을 같이 하면 함수가 많아질 수록 코드가 길어지고 가독성이 떨어지기 때문이다.  
 - 또, 헤더파일에 전방선언을 하고, cpp 파일에 구현하면 함수가 이미 선언되어있기 때문에 순서에 상관없이 구현할 수 있다.
 - 전방 선언이란 식별자를 정의하기 전에 식별자의 존재를 컴파일러에 미리 알리는 것 ! ( 선언만하고 정의 X )
 
 ##### 헤더 파일 작성
 cpp 파일을 컴파일할 때 식별자가 무엇인지 알 수 있도록 헤더 파일에 전방선언을 한다고 했다.  
 사용하고자 하는 모든 함수에 대한 전방선언을 각 파일에 작성하는 것은 매우 지루한 일 !  
 
 헤더 파일을 사용하면 이런 부담을 줄여주고, 선언을 필요한 만큼 한번만 작성하면 되고, 함수 원형에 대한 유지 보수를 편하게 해준다 !  
 
 헤더파일은 두 부분으로 구성됨.
 
 1. 헤더 가드 (Header guard) : 헤더 파일이 같은 파일에서 두 번 이상 포함되지 않게 해줌
 2. 헤더 파일의 소스 코드 : 다른 파일에서 볼 수 있는 모든 함수에 대한 선언
 
 ###### test.h
 ```c
 // header guard 시작
 #ifndef TEST_H
 #define TEST_H
 
 // 헤더 파일 소스 코드

 // header guard  끝
 #endif
 ```
 
 #### 전처리기 (preprocesser)
 전처리기는 프로그램을 컴파일할 때 컴파일 직전에 실행되는 별도의 프로그램  
 전처리기가 실행되면 각 코드 파일에서 지시자(directives)를 찾음  
 지시자(directives)는 #으로 시작해서 줄바꿈으로 끝나는 코드 !
 
 전처리기는 컴파일러가 실행되기 직전에 **텍스트 치환** 역할을 해주고,  
 **디버깅에 도움**을 주며 **헤더 파일의 중복 포함도 방지**해줌
 
 ##### Include
 - `#include` 를 하면 전처리기가 포함된 파일의 내용을 지시자의 위치에 복사함
 ```c
 #include <filename>
 ```
 
 ##### Macro
 - `#define` 지시자를 사용해 매크로를 만들 수 있음
 - Macro는 입력을 출력으로 변환하는 방식을 정의하는 규칙 !
 - 객체와 유사한 매크로와 함수와 유사한 매크로가 있음
 - 함수와 유사한 매크로 (function-like macro)는 함수러첨 작동
 - 객체와 유사한 매크로 (object-like macro)는 다음 두 가지 방법 중 하나로 정의.  
 ```c
 #define identifier
 #define identifier substitution_text 
 // 지시자는 명령어가 아니라서 세미콜론으로 끝나지 않음 !
 ```
 
 ###### 대체 텍스트가 있는 객체와 유사한 매크로 ( Object-like macros with subtitution text )
 
 전처리기가 이 지시자를 발견하면 **identifier**은 앞으로 **substitution_text** 텍스트로 대체된다.  
 식별자(identifier)는 일반적으로 공백을 나타내는 밑줄을 사용하여 대문자로 모두 입력한다.  
 
 ```C
 #define MY_FAVORITE_NUMBER 9
 
 std::cout<<"My favorite number is:"<<MY_FAVORITE_NUMBER<<std::endl;
 ```
 전처리기(preprocessed)는 위 코드를 다음과 같이 치환한다.
 ```c
 std::cout<<"My favorite number is:"<<9<<std::endl;
 ```
 
 ###### 대체 텍스트가 없는 객체와 유사한 매크로 (Object-like macros without substitution test )
 
 객체와 유사한 매크로는 대체 텍스트 없이도 정의할 수 있음.
 
 ```c
 #define USE_YEN
 ```
 일반적으로 이 전처리 지시자는 조건부 컴파일(conditional compilation)을 하기위해 사용된다.
 
 ##### 조건부 컴파일 ( Conditional compilation )
 조건부 컴파일 전처리 지시자를 사용하면 컴파일할 조건이나 컴파일하지 않을 조건을 지정할 수 있음
 
 `#ifdef` 지시자를 사용하면, 전처리기가 이전에 `#`이 정의되었는지 아닌지를 확인한다.  
 정의되었다면 `#ifdef`와 해당 `#endif` 사이의 코드가 컴파일된다.  
 그렇지 않으면 코드가 무시된다.
 
 ```c
 #define LOVE_SVT
 
 #ifdef LOVE_SVT
 std::cout << "hoshi" << std::endl;
 #endif
 
 #ifdef WOW
 std::cout << "wow!" << std::endl;
 #endif
 ```
 `WOW`가 정의되지 않아서 `std::cout << "wow!" << std::endl;` 이 무시된다.  
 
 `#ifndef` 는 `#ifdef`의 반대다.  
 identifier가 아직 정의되지 않았는지 확인한다 !  
 ```c
 #ifndef PRINT_BOB 
 std::cout << "Bob" << std::endl; 
 #endif
 ```

출처: https://boycoding.tistory.com/145?category=1006674 [소년코딩]
 
