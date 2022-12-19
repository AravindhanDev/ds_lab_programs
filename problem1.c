#include "stdio.h"
#include "stdbool.h"

typedef struct Student {
	char name[30];
	int regno;
	int marks[3];
	int score;
	int rank;
} Student;

void setUpData(Student*, int);
void printUsersDetails(Student*, int);
Student* rankList(Student*, int);

void main() {
	int noOfStudents;
	printf("Enter no of students: ");
	scanf("%d", &noOfStudents);
	Student s[noOfStudents];
	setUpData(s, noOfStudents);
	Student* newStudent = rankList(s, noOfStudents);
	printUsersDetails(s, noOfStudents);
}

Student* rankList(Student* s, int noOfStudents) {
	for (int i = 0; i < noOfStudents; i++) {
		bool swapMade = false;
		for (int j = 0; j < noOfStudents - i - 1; j++) {
			if (s[j].score > s[j+1].score) {
				Student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				swapMade = true;
			}
		}
		if (!swapMade) break;
	}
	for (int i = 0; i < noOfStudents; i++) {
		s[i].rank = noOfStudents - i;
	}
	return s;
}

void setUpData(Student *s, int noOfStudents) {
	for (int i = 0; i < noOfStudents; i++) {
		printf("\nEnter name for %d: ", i+1);
		getchar();
		fgets(s[i].name, 30, stdin);
		printf("Enter register no for %d: ", i+1);
		scanf("%d", &s[i].regno);
		printf("Enter marks for %d subjects: ", i+1);
		for (int j = 0; j < 3; j++) {
			scanf("%d", &s[i].marks[j]);
		}
	}
	for (int i = 0; i < noOfStudents; i++) {
		int score = 0;
		for (int j = 0; j < 3; j++) {
			score += s[i].marks[j];
		}
		s[i].score = score;
	}
}

void printUsersDetails(Student* s, int noOfStudents) {
	for (int i = 0; i < noOfStudents; i++) {
		printf("\nname: %sregno: %d \nscore: %d \nrank: %d\n", s[i].name, s[i].regno, s[i].score, s[i].rank);
	}
	printf("\n");
}
