#include <iostream>

using namespace std;

class MinHeap {
private :
	int * heap;				//동적할당을 위한 배열
	const int maxSize;
	int current;			// 데이터를 삽입할 수 있는 idx

public :
	// 최대사이즈로 배열을 동적할당
	// 현재 위치를 0으로 초기화
	MinHeap(int size = 7) : maxSize(size) {
		heap = new int[maxSize];
		current = 0;
	}

	// 소멸자
	~MinHeap() {
		delete[] heap;
	}

	// heap 이 비었는지 체크 
	int isEmpty() {
		return current == 0;
	}

	// heap 이 꽉차있는지  체크
	int isFull() {
		return current == maxSize;
	}

	void swap(int * a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	// heap에 데이터 삽입
	void insert(int data) {
		if (isFull()) {
			cout << "Heap is Full !! " << endl;
			return;
		}
		//마지막에 원소삽입
		int pos = current++;
		heap[pos] = data;

		if (current != 1) {
			// 부모 값보다 내 가 작다면 교환 !!
			int parPos = (pos - 1) / 2;
			while (heap[pos] < heap[parPos]) {
				swap(&heap[pos], &heap[parPos]);
				pos = parPos;
				parPos = (pos - 1) / 2;
			}
		}
	}

	int del() {
		/* heap이 비어있으면 문구를 출력하고
		   NULL을 반환한다.      */
		if (isEmpty()) {
			cout << "Heap is empty !!" << endl;
			return NULL;
		}

		int returnData = heap[0];
		// root와 가장 마지막 노드 교환 및 삭제
		swap(&heap[0], &heap[current - 1]);
		heap[current-- - 1] = NULL;
		
		// 새로운 root 찾기
		int r = 0;
		int leftChild, rightChild;

		while (r<= current - 1) {
			leftChild = (r + 1) * 2 - 1;
			rightChild = (r + 1) * 2;

			if (leftChild >= current) // child 존재 x
				break;
			else if (rightChild >= current) { 
				// 왼쪽 child만 존재함
				if (heap[leftChild] < heap[r]) {
					// 왼쪽 자식과 부모의 값 바꿔주기
					swap(&heap[leftChild], &heap[r]);
					r = leftChild;
				}
				else
					break;
			}
			else{ // 양쪽 child 존재

				//두개의 자식이 부모보다 작을 때
				if (heap[leftChild] < heap[r] &&
					heap[rightChild] < heap[r]) {

					// 왼쪽 <오른쪽
					if (heap[leftChild] < heap[rightChild]) {
						swap(&heap[leftChild], &heap[r]);
						r = leftChild;
					}
					else { // 오른쪽 < 왼쪽
						swap(&heap[rightChild], &heap[r]);
						r = rightChild;
					}
				}
				// 둘중 하나만 작을때
				else if (heap[leftChild] < heap[r]) {
					swap(&heap[leftChild], &heap[r]);
					r = leftChild;
				}
				else if (heap[rightChild] < heap[r]) {
					swap(&heap[rightChild], &heap[r]);
					r = rightChild;
				}
				else
					break;

			}
		}
		return returnData;
	}

	void display() {
		cout << "( ";
		for (int i = 0; i < current; i++) {
			cout << heap[i] << " ";
		}
		cout << ")" << endl;
	}

	int level() {
		int l = 0;
		for( int sum=0, i =0; sum<current;i++){
			int temp = 1;
			for (int j = 0; j < i; j++)
				temp *= 2;
			sum += temp;
			l++;
		}
		return l;
	}


};