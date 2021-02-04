#include "double-linked-list.hpp"
void getData();
struct Student {
	char name[5];
	int w;
	int h;
};

Student s1[4];

int main() {

	DoubleLinkedList dll;

	getData();

	for (int i = 0; i < sizeof(s1) / sizeof(Student); i++) {
		dll.insert(s1[i].name, s1[i].w, s1[i].h);
	}

	dll.displayForward();
	cout << endl;

	char Lee[4] = "lee";
	dll.search(Lee);
	cout << endl;

	dll.del(Lee);
	dll.displayForward();

	char insertName[5] = "Park";
	dll.insertAfter(2, insertName, 73, 176);
	dll.displayForward();

	dll.findNode(2);
	cout << endl;

	dll.displayBackward();


	return 0;
}

void getData() {
	FILE * f1 = fopen("input.txt", "r");
	for (int i = 0; fscanf(f1, "%d") != EOF; i++) {
		fscanf(f1, "%s\n", &s1[i].name);
		fscanf(f1, "%d", &s1[i].w);
		fscanf(f1, "%d", &s1[i].h);


	}
}