#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME  20

struct student
{
	char name[MAX_NAME];
	int id;
	double averageGrade;
};
typedef struct student STUDENT;



void CheckAlloc(STUDENT* arr);
void recieveStudentsData(STUDENT* students, int size);
double average(STUDENT students[], int size);



void main()
{
	STUDENT* students;
	int NumberOfStudents;
	double AverageScore;

	scanf("%d", &NumberOfStudents);

	students = (STUDENT*)malloc(NumberOfStudents * sizeof(STUDENT));
	CheckAlloc(students);

	recieveStudentsData(students, NumberOfStudents);

	AverageScore = average(students, NumberOfStudents);
	printf("%.2lf", AverageScore);

}


void CheckAlloc(STUDENT* arr)
{
	if(arr == NULL)
	{
		printf("The Allocation was unsucessfull. The PROGRAM WILL NOW CLOSE\n\n");
		exit(0);
	}
}

void recieveStudentsData(STUDENT* students, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		//printf("enter the name of %d \n\n", i);
		scanf(" %s", students[i].name);
		//printf("please enter id of %d \n\n", i);
		scanf(" %d", &students[i].id);
		//printf("please enter the average of %d\n\n", i);
		scanf(" %lf", &students[i].averageGrade);
	}
}


double average(STUDENT students[], int size)
{
	int i;
	double finalAverage = 0;
	for(i = 0; i < size; i++)
	{
		finalAverage += students[i].averageGrade;
	}
	finalAverage = finalAverage / size;
	return finalAverage;
}



