#include "hw3-singlelinkedlist.hpp"

void getData();

struct Student {
	char name;
	int id;
	char major[3];
	char grade;
};

Student data1[7];
Student data2[3];

int main() {

	SingleLinkedList d1;
	SingleLinkedList d2;
	SingleLinkedList newList;

	getData();
	for (int i = 0; i < sizeof(data1) / sizeof(Student); i++) {
		d1.insert(data1[i].name, data1[i].id, data1[i].grade, data1[i].major);
	}

	for (int i = 0; i < sizeof(data2) / sizeof(Student); i++) {
		d2.insert(data2[i].name, data2[i].id, data2[i].grade, data2[i].major);
	}

	d1.display();
	cout << endl;

	d1.display('A');
	cout << endl;

	newList.concatenate(d1.getHead(), d2.getHead());
	newList.display(NULL, "CS");



	return 0;
}

void getData() {
	FILE * f1 = fopen("homework03-1.txt", "r");
	for (int i = 0; fscanf(f1, "%d") != EOF; i++) {
		fscanf(f1, "%c", &data1[i].name);
		fscanf(f1, "%d", &data1[i].id);
		fscanf(f1, "%s\n", &data1[i].major);
		fscanf(f1, "%c", &data1[i].grade);
	}

	FILE * f2 = fopen("homework03-2.txt", "r");
	for (int i = 0; fscanf(f2, "%d") != EOF; i++) {
		fscanf(f2, "%c", &data2[i].name);
		fscanf(f2, "%d", &data2[i].id);
		fscanf(f2, "%s\n", &data2[i].major);
		fscanf(f2, "%c", &data2[i].grade);
	}
}
