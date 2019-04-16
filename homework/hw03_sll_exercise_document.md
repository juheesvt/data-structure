# Homework #3 Document
> Name : 강주희  
> Student ID : 20181570  
> Program ID : Homework#3

## Description 
- Single Linked List를 이용해 주어진 데이터를 다루는 것이다.
- 2개의 데이터 파일의 각 학생의 이름과 id, 전공, 학점이 주어진다.
- 오름차 순으로 정렬, 링크드리스트를 합쳐 새로운 리스트 만들기, 특정 데이터를 가진 학생만 출력등의 기능을 수행한다.


## Algorithm 
- 데이터 처리는 자료구조 Single Linked List을 이용한다
- single linked list의 알고리즘
    + 각 노드를 이어서 하나의 리스트로 만드는 것이 링크드리스트이다.
    + Array 보다 데이터의 삽입 및 삭제가 편하다.
    + Node 클래스와 Linked List클래스를 따로만들어서 데이터의 저장은 Node에서 진행하고, 각 Node 끼리의 연결을 Linked List에서 서 수행한다.
    + 보통 method는 isEmpty(), display(), insert(data), del(data), search() 등이 있다.
    + 이번 homework에서는 주어진 데이터에 맞게 기존 함수를 변형 및 추가, 혹은 삭제도 할 것이다.
    + txt파일에서 데이터 읽어오기
        * fopen 과 fscanf를 사용해서 만들어놓은 Student 구조체 배열에 데이터를 할당한다.
    + Linked List를 이용해서 데이터 처리하기
        * 구조체 배열에 있는 데이터를 insert함수를 이용해 Linked List에 넣어준다. 
        * 이 때, insert함수는 학생의 이름을 기준으로 오름차순으로 데이터를 집어넣는다.
        * 링크드리스트에 있는 데이터들 중에, grade(성적)가 "A"인 학생들만 출력하기 위해, display의 parameter 중 grade인자에 'A'를 넘겨준다.
        * 데이터1에서 읽어서 만든 리스트와 데이터2에서 읽어서 만든 리스트를 concatenate()함수를 이용해서 합치고 오름차순으로 정렬한다.
        * 새로 만든 리스트에서 major(전공)가 CS인 학생들만 출력하기 위해 display의 parameter중 major인자에 "CS"를 넘겨준다.
    
## Function
    - main (hw03.cpp)
        * SingleLinkedList의 객체를 생성한다.
        * getData() 함수를 이용해서 데이타 파일을 읽어 구조체 배열에 저장한다.
        * 구조체 배열에 담긴 학생들의 정보를 for문을 이용해 SingleLinkedList 의 첫번째와 두번째 객체에 insert해준다.
        * 메서드를 호출해 만들어진 리스트들을 출력한다.
    - getData (hw03.cpp)
        * fopen을 이용해 주어진 데이터 텍스트 파일을 열어 파일 객체를 생성한다.
        * for문과 fscanf를 이용해 파일을 공백단위로 읽어서 자료형에 맞게 구조체 배열에 넣어준다.
    - Node (hw03-singlelinkedlist.hpp , class Node)
        * Node 클래스의 생성자
        * parameter로 name, id, grade, major 이 있다.
    - getName (hw03-singlelinkedlist.hpp , class Node)
        * 멤버 변수 name을 반환하는 함수
    - getId (hw03-singlelinkedlist.hpp , class Node)
        * 멤버 변수 id을 반환하는 함수
    - getGrade (hw03-singlelinkedlist.hpp , class Node)
        * 멤버 변수 grade을 반환하는 함수
    - getMajor (hw03-singlelinkedlist.hpp , class Node)
        * 배열의이름 major을 반환하는 함수
    - getNext (hw03-singlelinkedlist.hpp , class Node)
        * 해당 노드에 연결된 next 주솟값을 반환하는 함수
    - setName (hw03-singlelinkedlist.hpp , class Node)\
        * 멤버 변수 name의 값을 설정하는 함수
    - setId (hw03-singlelinkedlist.hpp , class Node)
        * 멤버 변수 id의 값을 설정하는 함수
    - setGrade (hw03-singlelinkedlist.hpp , class Node)
        * 멤버 변수 grade의 값을 설정하는 함수
    - setMajor (hw03-singlelinkedlist.hpp , class Node)
        * strcpy()를 이용해 this->major에 받아온 배열을 복사한다
    - setNext (hw03-singlelinkedlist.hpp , class Node)
        * 해당 노드에 연결된 next 주솟값을 설정하는 함수
        
## 코드 상세 설명


### 데이터 파일
- homework02.txt
```txt
2+3
2+3*5
3*5+9-3
9*(1+2)
3+9*(5-2)
```

### 실행결과
![](https://github.com/juheesvt/data-structure/blob/master/homework/hw02%20%EC%8B%A4%ED%96%89%EA%B2%B0%EA%B3%BC.png)
