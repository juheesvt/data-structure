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
        
- Node ( hw03-singlelinkedlist.hpp , class Node )
    * Node class's Construct
    * parameter로 name, id, grade, major 이 있다.
        
- getName ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 name을 반환하는 함수
        
- getId ( hw03-singlelinkedlist.hpp , class Node )
     * 멤버 변수 id을 반환하는 함수
        
- getGrade ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 grade을 반환하는 함수
        
- getMajor ( hw03-singlelinkedlist.hpp , class Node )
    * 배열의이름 major을 반환하는 함수
        
- getNext ( hw03-singlelinkedlist.hpp , class Node )
    * 해당 노드에 연결된 next 주솟값을 반환하는 함수
        
- setName ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 name의 값을 설정하는 함수
        
- setId ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 id의 값을 설정하는 함수
        
- setGrade ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 grade의 값을 설정하는 함수
        
- setMajor ( hw03-singlelinkedlist.hpp , class Node )
    * strcpy()를 이용해 this->major에 받아온 배열을 복사한다
        
- setNext ( hw03-singlelinkedlist.hpp , class Node )
    * 해당 노드에 연결된 next 주솟값을 설정하는 함수
        
- SingleLinkedList ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * SingleLinkedList Class's Construct.
    * head를 NULL로 초기화 시킨다.
    
- getHead ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * head node를 반환한다.    
    
- setHead ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * head node를 설정한다.
    
- isEmpty ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * list가 비어있는지 검사한다.
    
- insert ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * parameter로 name, id, grade, major을 받아 Node 생성자를 호출해 node를 만들어준다
    * 오름차순으로 노드를 리스트에 이어준다.
    
- display ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * default parameter로 grade, major을 받는다
    * 매개변수로 아무것도 들어오지 않는다면, 리스트에 있는 데이터를 전부 출력한다.
    * 매개변수 grade가 들어오면 해당 grade 값을 가진 노드만 출력한다.
    * 매개변수 major가 들어오면 해당 major 값을 가진 노드만 출력한다.

- concatenate ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * 두 리스트의 헤드값을 받아와서 새로운 리스트를 만든다.
    * 새로 만들어진 노드들을 insert()함수를 이용해 이어서 오름차순으로 정렬된다.
    
- ~SingleLinkedList ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * SingleLinkedList의 소멸자로, 리스트내의 모든 노드들을 삭제한다.
    
        
## 코드 상세 설명
- main (hw03.cpp)
    + Description
        * SingleLinkedList의 객체를 생성한다.
        * getData() 함수를 이용해서 데이타 파일을 읽어 구조체 배열에 저장한다.
        * 구조체 배열에 담긴 학생들의 정보를 for문을 이용해 SingleLinkedList 의 첫번째와 두번째 객체에 insert해준다.
        * 메서드를 호출해 만들어진 리스트들을 출력한다.
    + Variable
        * ```SingleLinkedList d1``` : data1 파일에서 가져온 데이터를 저장할 객체.
        * ```SingleLinkedList d2``` : data2 파일에서 가져온 데이터를 저장할 객체.
        * ```SingleLinkedList newList``` : d1과 d2를 합쳐서 새로운 리스트를 생성한 객체.
 ```cpp
 // SingleLinkedList 를 구현한 hpp파일 가져오기
 #include "hw3-singlelinkedlist.hpp"

// 데이터를 읽어서 저장시켜줄 함수
void getData();

// 데이터 파일에 있는 학생의 정보를 저장할 구조체
struct Student {
	char name;
	int id;
	char major[3];
	char grade;
};

// 구조체 배열, 각각 파일1, 파일2의 데이터들을 담을 것임
Student data1[7];
Student data2[3];

int main() {
    // 데이터를 담을 SingleLinkedList 객체 생성
	SingleLinkedList d1;
	SingleLinkedList d2;
	SingleLinkedList newList;
    
    // txt 파일로 부터 데이터 읽어서 구조체 배열에 저장할 함수 호출.
	getData();
    
    // 구조체 배열 data1, data2에 있는 데이터를 각각 d1, d2 객체에 삽입 !
	for (int i = 0; i < sizeof(data1) / sizeof(Student); i++) 
		d1.insert(data1[i].name, data1[i].id, data1[i].grade, data1[i].major);
	for (int i = 0; i < sizeof(data2) / sizeof(Student); i++) 
		d2.insert(data2[i].name, data2[i].id, data2[i].grade, data2[i].major);
	
    // 오름차순으로 정렬된 d1의 데이터 출력하기
	d1.display();
	cout << endl;
    
    // d1의 데이터 중에서 grade가 'A'인 노드만 출력하기
	d1.display('A');
	cout << endl;
    
    // d1과 d2를 합쳐서 newList라는 새로운 객체에 삽입
	newList.concatenate(d1.getHead(), d2.getHead());
    
    //newList의 데이터 중에서 major가 "CS"인 노드만 출력하기
	newList.display(NULL, "CS");

	return 0;
}
 
 ```
- getData (hw03.cpp)
    + Description
        * fopen을 이용해 주어진 데이터 텍스트 파일을 열어 파일 객체를 생성한다.
        * for문과 fscanf를 이용해 파일을 공백단위로 읽어서 자료형에 맞게 구조체 배열에 넣어준다.
    + Variable
        * ```FILE * f1``` : homework03-1.txt을 fopen 으로 열어서 생성한 파일 객체.
        * ```FILE * f2``` : homework03-2.txt을 fopen 으로 열어서 생성한 파일 객체.
```cpp

void getData() {
    // homework03-1.txt의 데이터를 담고있는 파일 객체를 생생
	FILE * f1 = fopen("homework03-1.txt", "r");
    
    // 파일 객체 f1의 데이터를 각 자료형에 맞게 data1 구조체 배열에 삽입
	for (int i = 0; fscanf(f1, "%d") != EOF; i++) {
		fscanf(f1, "%c", &data1[i].name);
		fscanf(f1, "%d", &data1[i].id);
		fscanf(f1, "%s\n", &data1[i].major);
		fscanf(f1, "%c", &data1[i].grade);
	}
    // homework03-2.txt의 데이터를 담고있는 파일 객체를 생생
	FILE * f2 = fopen("homework03-2.txt", "r");
    
    // 파일 객체 f2의 데이터를 각 자료형에 맞게 data12 구조체 배열에 삽입
	for (int i = 0; fscanf(f2, "%d") != EOF; i++) {
		fscanf(f2, "%c", &data2[i].name);
		fscanf(f2, "%d", &data2[i].id);
		fscanf(f2, "%s\n", &data2[i].major);
		fscanf(f2, "%c", &data2[i].grade);
	}
}
```
- Node ( hw03-singlelinkedlist.hpp , class Node )
    + Description
        * Node class's Construct
        * parameter로 name, id, grade, major 이 있다.
    + Variable
        * ```char name``` : 학생의 이름을 저장하는 멤버 변수
        * ```int id``` : 학생의 아이디을 저장하는 멤버 변수
        * ```char grade``` : 학생의 성적을 저장하는 멤버 변수
        * ```char major[3]``` : 학생의 전공을 저장하는 멤버 변수
        * ```Node * next``` : 해당 노드에 연결된 다음 노드의 주솟값을 저장하는 
        
- getName ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 name을 반환하는 함수
        
- getId ( hw03-singlelinkedlist.hpp , class Node )
     * 멤버 변수 id을 반환하는 함수
        
- getGrade ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 grade을 반환하는 함수
        
- getMajor ( hw03-singlelinkedlist.hpp , class Node )
    * 배열의이름 major을 반환하는 함수
        
- getNext ( hw03-singlelinkedlist.hpp , class Node )
    * 해당 노드에 연결된 next 주솟값을 반환하는 함수
        
- setName ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 name의 값을 설정하는 함수
        
- setId ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 id의 값을 설정하는 함수
        
- setGrade ( hw03-singlelinkedlist.hpp , class Node )
    * 멤버 변수 grade의 값을 설정하는 함수
        
- setMajor ( hw03-singlelinkedlist.hpp , class Node )
    * strcpy()를 이용해 this->major에 받아온 배열을 복사한다
        
- setNext ( hw03-singlelinkedlist.hpp , class Node )
    * 해당 노드에 연결된 next 주솟값을 설정하는 함수
    
```cpp

class Node {
	
private:
	char name;          // 학생의 이름
	int id;             // 학생의 아이디
	char major[3];      // 학생의 전공
	char grade;         // 학생의 성적
	Node * next;        // 노드에 연결된 다음 노드의 주소

public:
    // 노드 클래스의 생성자, 디폴트 매개변수로 name, id, grade, major 을 받아 초기화시킨다
	Node(char name = NULL, int id = NULL, char grade = NULL, char * major = NULL) {
		this->name = name;              
		this->id = id;
		this->grade = grade;
		strcpy(this->major, major);     // strcpy를 통해 문자열을 복사한다.
		this->next = NULL;
	}

	char getName() {
		return this->name;      // 멤버 변수 name의 값을 반환한다.
	}
	int getId() {
		return this->id;        // 멤버 변수 name의 값을 반환한다.
	}
	char getGrade() {
		return this->grade;     // 멤버 변수 name의 값을 반환한다.
	}
	char *getMajor() {
		return this->major;     // 멤버 변수 name의 값을 반환한다.
	}

	void setName(char name) {
		this->name = name;      // 멤버 변수 name의 값을 반환한다.
	}
	void setId(int id) {
		this->id = id;          // 멤버 변수 name의 값을 반환한다.
	}
	void setGrade(char grade) {
		this->grade = grade;    // 멤버 변수 name의 값을 반환한다.
	}
	void setMajor(char * major) {
		major = major;          // 멤버 변수 name의 값을 반환한다.
	}

	Node * getNext() {
		return this->next;      // 멤버 변수 name의 값을 반환한다.
	}

	void setNext(Node * next) {
		this->next = next;      // 멤버 변수 name의 값을 반환한다.
	}
};

```
        
- SingleLinkedList ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    + Description
        * SingleLinkedList Class's Construct.
        * head를 NULL로 초기화 시킨다.
    + Variable 
        * ```Node* head```: 리스트의 첫번째 노드를 저장하는 노드
    
- getHead ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * head node를 반환한다.    
    
- setHead ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * head node를 설정한다.
    
- isEmpty ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    * list가 비어있는지 검사한다.
    
```cpp

class SingleLinkedList {

private:
	Node* head;

public:

	SingleLinkedList() {
		head = NULL;            // head를 NULL로 초기화
	}

	Node * getHead() {
		return this->head;      // head를 반환하는 함수
	}

	void setHead(Node * head) {
		this->head = head;      // head를 설정하는 함수
	}

	bool isEmpty() {
		return head == NULL;    // 리스트가 비었는지 검사하는 함수
	}   
```
    
- insert ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    + Description
        * parameter로 name, id, grade, major을 받아 Node 생성자를 호출해 node를 만들어준다
        * name을 기준으로 오름차순으로 노드를 리스트에 이어준다.
    + Variable
        * ```Node * newNode```: 삽입할 데이터를 저장한 새 노드 
        * ```Node * temp```: 데이터의 삽입을 위해 head부터 시작해서 리스트를 타고 들어갈 임시 노드
```cpp
	void insert(char name, int id, char grade, char * major) {
        // 받아온 name, id, grade, major를 Node의 생성자로 넘겨줘서 새로운 노드 생성
		Node * newNode = new Node(name, id, grade, major);
        
        // 만약 리스트가 비어있으면 새로운 노드가 head가 된다.
		if (isEmpty()) 
			head = newNode;

		else {
            // 리스트를 타고갈 임시 노드
			Node * temp = head;

			// 새로운 노드의 name의 값이 헤드의 name의 값보다 작을 경우
			if (newNode->getName() < head->getName()) {
                // 새로운 노드가 헤드가 되고, 헤드는 새노드의 다음 노드가 됨.
				head = newNode;         
				newNode->setNext(temp);
			}
			else {
     			for (int i = 0;; i++) {
					// 리스트에 노드 하나만 있는데 헤드의 name값 보다 클 경우
					if (temp != NULL && temp->getNext() == NULL) {
                        // 헤드의 다음 노드가 새노드가 됨.
						temp->setNext(newNode);
						break;
					}
					else if (
						// 리스트 중간에 newNode가 삽입될 조건
						temp != NULL &&
						newNode->getName() >= temp->getName() &&
						temp->getNext() != NULL &&
						newNode->getName() < temp->getNext()->getName()) {
                        
                        // 새노드의 다음 노드를 현재 노드(임시 노드)의 다음노드로 설정하고
                        newNode->setNext(temp->getNext());
                        // 현재 노드의 다음 노드를 새 노드로 설정한다.
						temp->setNext(newNode);
						break;
					}
                    // temp 노드를 다음 노드로 이동시킨다.
					temp = temp->getNext();
				}
			}
		}
	}
```
        
- display ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    + Description
        * default parameter로 grade, major을 받는다
        * 매개변수로 아무것도 들어오지 않는다면, 리스트에 있는 데이터를 전부 출력한다.
        * 매개변수 grade가 들어오면 해당 grade 값을 가진 노드만 출력한다.
        * 매개변수 major가 들어오면 해당 major 값을 가진 노드만 출력한다.
    + Variable
        * ```Node * temp```: 노드를 출력하기 위해 리스트를 타고 이동할 임시노드
        * ```char * t```: 포인터 연산으로 major을 출력할 포인터
```cpp
    // 특정한 성적을 받은 사람만 출력 or 특정한 전공 출력 or 그냥 출력
	void display(char grade = NULL, const char * major = NULL) {
		if (isEmpty())      // 리스트가 비어있을 때 !
			cout << "SingleLinkedList is Empty !!" << endl;
        
        // 파라미터 값이 모두 NULL 이면 리스트에 있는 모든 노드를 출력
		else if (grade == NULL && major == NULL){
			Node * temp = head;              // 임시 노드를 헤드로 지정
			for (; temp != NULL; temp = temp->getNext()) {  // 임시 노드 이동시키기
				cout << "Name : " << temp->getName() << "\t";   // 이름 출력
				cout << "Id : " << temp->getId() << "\t";       // id  출력
				cout << "Grade : " << temp->getGrade() << "\t"; // grade 출력        
				cout << "Major : " ;
				// major 배열 출력
				for(char * t = temp->getMajor(); *t != NULL; t++)
					cout << *t;
				cout << endl;
			}			
		}
        // 특정 grade를 가진 노드만 출력하기
		else if (grade != NULL){
			Node * temp = head;
			for (; temp != NULL; temp = temp->getNext()) {
                // 현재 노드의 grade 값이 파라미터의 grade값과 같다면 출력하기
				if (temp->getGrade() == grade) {
					cout << "Name : " << temp->getName() << "\t";
					cout << "Id : " << temp->getId() << "\t";
					cout << "Grade : " << temp->getGrade() << "\t";
					cout << "Major : ";

					for (char * t = temp->getMajor(); *t != NULL; t++)
						cout << *t;
					cout << endl;
				}	
			}
			
		}
		else {  // 특정 전공을 가진 노드만 출력하기
			Node * temp = head;
			for (; temp != NULL; temp = temp->getNext()) {
                // 현재 노드의 major 가 파라미터의 major 값과 같다면 출력
				if (strcmp(temp->getMajor(),major) == 0) {
					cout << "Name : " << temp->getName() << "\t";
					cout << "Id : " << temp->getId() << "\t";
					cout << "Grade : " << temp->getGrade() << "\t";
					cout << "Major : ";

					for (char * t = temp->getMajor(); *t != NULL; t++)
						cout << *t;
					cout << endl;
				}
			}
		}
	}
```

- concatenate ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    + Description
        * 두 리스트의 헤드값을 받아와서 새로운 리스트를 만든다.
        * 새로 만들어진 노드들을 insert()함수를 이용해 이어서 오름차순으로 정렬된다.
    + Variable
        * ```Node * temp```: 새 리스트에 연결될 노드를 생성해 저장할 임시노드
        * ```Node * linkNode```: 합칠 노드를 가리키는 임시 노드
```cpp
	void concatenate(Node* list1head, Node* list2head) {
		// list 1이 빈 리스트일 때
		if (list1head == NULL) {
            // 현재 리스트의 헤드를 list2의 헤드의 데이터를 가져와서 새 노드로 만들어 할당하기.
			head = new Node(list2head->getName(), list2head->getId(), 
                            list2head->getGrade(), list2head->getMajor());
            // temp를 현재 노드의 head로 초기화
			Node * temp = head;
            // linkNode는 가져올 리스트의 헤드의 다음 노드로 초기화
			Node * linkNode = list2head->getNext();
            
            // 새 리스트에다가 list2의 노드들을 하나씩 가져와서 저장하기.
			for (; linkNode != NULL; linkNode = linkNode->getNext()) {
				temp->setNext(new Node(linkNode->getName(), linkNode->getId(), 
                                        linkNode->getGrade(), linkNode->getMajor()));
                temp = temp->getNext();
			}
		}

		// list 2가 빈 리스트일 때
		else if (list2head == NULL) {
			head = new Node(list1head->getName(), list1head->getId(), 
                            list1head->getGrade(), list1head->getMajor());
            // temp를 현재 노드의 head로 초기화
			Node * temp = head;
            // 새 리스트에다가 list1의 노드들을 하나씩 가져와서 저장하기.
			Node * linkNode = list1head->getNext();
            
            // 새 리스트에다가 list1의 노드들을 하나씩 가져와서 저장하기.
			for (; linkNode != NULL; linkNode = linkNode->getNext()) {
				temp->setNext(new Node(linkNode->getName(), linkNode->getId(), 
                                linkNode->getGrade(), linkNode->getMajor()));
                 temp = temp->getNext();
			}
		}
        // list1, list2 둘다 빈 리스트가 아닐 때 !
		else { 
			//오름차 순으로 합치기 !
            // temp 를 list1의 head로 초기화
			Node * temp = list1head;
            
            // temp 를 이동시키면서 list1의 현재 노드의 데이터를 가져오기
            for (; temp != NULL; temp = temp->getNext()) 
				insert(temp->getName(), temp->getId(), temp->getGrade(), temp->getMajor());
                // insert()함수를 이용해 새 노드를 생성해 오름차 순으로 리스트에 집어넣기
                
			// temp 를 list2의 head로 초기화
			temp = list2head;
            
            // temp 를 이동시키면서 list2의 현재 노드의 데이터를 가져오기
			for (; temp != NULL; temp = temp->getNext())
				insert(temp->getName(), temp->getId(), temp->getGrade(), temp->getMajor());
                // insert()함수를 이용해 새 노드를 생성해 오름차 순으로 리스트에 집어넣기
		}
	}
```
    
- ~SingleLinkedList ( hw03-singlelinkedlist.hpp , class SingleLinkedList )
    + Description
        * SingleLinkedList의 소멸자로, 리스트내의 모든 노드들을 삭제한다.
    + Variable
        * ```Node* del_node```: 삭제할 노드
        * ```Node* next_del_node```: 삭제할 노드의 다음 노드
```cpp
	~SingleLinkedList() {
		if (!isEmpty()) { // 리스트가 비어있지 않을 때 실행 !
        
            // 삭제할 노드를 head로, 그 다음 노드는 삭제할 노드의 다음 노드로 초기화
			Node * del_node = head;
			Node * next_del_node = head->getNext();

			for (int i = 0; ; ++i) {
				if (next_del_node == NULL) {	// 리스트안에 데이터가 하나만 있을 때
					delete del_node;            // del_node만 지운다.
					break;
				}
                
                // next_del_node가 마지막 노드 일때는 둘다 지우고 끝낸다.
				if (next_del_node->getNext() == NULL) {
					delete del_node;
					delete next_del_node;
					break;
				}
                
                // del_node를 지우고 next_del_node를 이용해 노드를 이동시킨다.
				else {
					delete del_node;
					del_node = next_del_node;
					next_del_node = next_del_node->getNext();

				}
			}
		}
	}
};
```


### 데이터 파일
- homework03-1.txt
```txt
H 152 CS B
C 182 EE A
B 195 CS A
G 250 HI C
A 590 EE A
D 812 CH B
J 610 CS A
```
- homework03-2.txt
```txt
F 150 EE B
I 480 CS A
K 100 EE A
```

### 실행결과
![]()
