#include <iostream>

using namespace std;

class MinHeap {
private :
	int * heap;				//�����Ҵ��� ���� �迭
	const int maxSize;
	int current;			// �����͸� ������ �� �ִ� idx

public :
	// �ִ������� �迭�� �����Ҵ�
	// ���� ��ġ�� 0���� �ʱ�ȭ
	MinHeap(int size = 7) : maxSize(size) {
		heap = new int[maxSize];
		current = 0;
	}

	// �Ҹ���
	~MinHeap() {
		delete[] heap;
	}

	// heap �� ������� üũ 
	int isEmpty() {
		return current == 0;
	}

	// heap �� �����ִ���  üũ
	int isFull() {
		return current == maxSize;
	}

	void swap(int * a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	// heap�� ������ ����
	void insert(int data) {
		if (isFull()) {
			cout << "Heap is Full !! " << endl;
			return;
		}
		//�������� ���һ���
		int pos = current++;
		heap[pos] = data;

		if (current != 1) {
			// �θ� ������ �� �� �۴ٸ� ��ȯ !!
			int parPos = (pos - 1) / 2;
			while (heap[pos] < heap[parPos]) {
				swap(&heap[pos], &heap[parPos]);
				pos = parPos;
				parPos = (pos - 1) / 2;
			}
		}
	}

	int del() {
		/* heap�� ��������� ������ ����ϰ�
		   NULL�� ��ȯ�Ѵ�.      */
		if (isEmpty()) {
			cout << "Heap is empty !!" << endl;
			return NULL;
		}

		int returnData = heap[0];
		// root�� ���� ������ ��� ��ȯ �� ����
		swap(&heap[0], &heap[current - 1]);
		heap[current-- - 1] = NULL;
		
		// ���ο� root ã��
		int r = 0;
		int leftChild, rightChild;

		while (r<= current - 1) {
			leftChild = (r + 1) * 2 - 1;
			rightChild = (r + 1) * 2;

			if (leftChild >= current) // child ���� x
				break;
			else if (rightChild >= current) { 
				// ���� child�� ������
				if (heap[leftChild] < heap[r]) {
					// ���� �ڽİ� �θ��� �� �ٲ��ֱ�
					swap(&heap[leftChild], &heap[r]);
					r = leftChild;
				}
				else
					break;
			}
			else{ // ���� child ����

				//�ΰ��� �ڽ��� �θ𺸴� ���� ��
				if (heap[leftChild] < heap[r] &&
					heap[rightChild] < heap[r]) {

					// ���� <������
					if (heap[leftChild] < heap[rightChild]) {
						swap(&heap[leftChild], &heap[r]);
						r = leftChild;
					}
					else { // ������ < ����
						swap(&heap[rightChild], &heap[r]);
						r = rightChild;
					}
				}
				// ���� �ϳ��� ������
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