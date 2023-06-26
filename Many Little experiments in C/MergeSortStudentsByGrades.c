#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME  20

struct student
{
	char name[MAX_NAME];
	int id;
	double averageGrade;
};
typedef struct student STUDENT;


//COLLECTIVE FUNCTIONS
void CheckAlloc(STUDENT* arr);
void recieveStudentsData(STUDENT* students, int size);

//FOR ALEF
double average(STUDENT students[], int size);

//FOR BET
void printGoodStudents(STUDENT students[], int size);

//FOR GIMEL
void sortStudents(STUDENT students[], int size);
void mergeSort(STUDENT arr[], int size);
STUDENT* merge(STUDENT a1[], int size1, STUDENT a2[], int size2);
void printSortedStudents(STUDENT arr[], int size);
void copyArr(STUDENT dest[], STUDENT src[], int size);
//FOR DALED


void main()
{
	STUDENT* students;
	int NumberOfStudents;
	double AverageScore;
	//printf("enter the amount of students\n");
	scanf("%d", &NumberOfStudents);

	students = (STUDENT*)malloc(NumberOfStudents * sizeof(STUDENT));
	CheckAlloc(students);
	recieveStudentsData(students, NumberOfStudents);

	//FOR ALEF
	//AverageScore = average(students, NumberOfStudents);
	//printf("%.2lf", AverageScore);

	//FOR BET
	//printGoodStudents(students, NumberOfStudents);

	//FOR GIMEL
	sortStudents(students, NumberOfStudents);

}

//COLLECTIVE FUNCTIONS	
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
//FOR ALEF
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

//FOR BET
void printGoodStudents(STUDENT students[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(students[i].averageGrade > 80.00)
			printf("%s ", students[i].name);
	}
}

//FOR GIMEL
void sortStudents(STUDENT students[], int size)
{
	mergeSort(students, size);
	printSortedStudents(students, size);
}

void mergeSort(STUDENT arr[], int size)
{
	STUDENT* tmpArr = NULL;
	if(size <= 1)
		return;

	mergeSort(arr, size / 2);
	mergeSort(arr + size / 2, size - size / 2);
	tmpArr = merge(arr, size / 2, arr + size / 2, size - size / 2);
	if(tmpArr)
	{
		copyArr(arr, tmpArr, size); // copy values from tmpArr to arr
		free(tmpArr);
	}
	else
	{
		printf("Memory allocation failure!!!\n");
		exit(1);	// end program immediately with code 1 (indicating an error)
	}
}

STUDENT* merge(STUDENT a1[], int size1, STUDENT a2[], int size2)
{
	int ind1, ind2, resInd;
	STUDENT* res = (STUDENT*)malloc((size1 + size2) * sizeof(STUDENT));

	if(res)
	{
		ind1 = ind2 = resInd = 0;

		while((ind1 < size1) && (ind2 < size2))
		{
			if(a1[ind1].id <= a2[ind2].id)
			{
				res[resInd] = a1[ind1];
				ind1++;
			}
			else
			{
				res[resInd] = a2[ind2];
				ind2++;
			}
			resInd++;
		}

		while(ind1 < size1)
		{
			res[resInd] = a1[ind1];
			ind1++;
			resInd++;
		}
		while(ind2 < size2)
		{
			res[resInd] = a2[ind2];
			ind2++;
			resInd++;
		}
	}
	return res;
}

void copyArr(STUDENT dest[], STUDENT src[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		strcpy(dest[i].name, src[i].name);
		dest[i].id = src[i].id;
		dest[i].averageGrade = src[i].averageGrade;
	}
}

void printSortedStudents(STUDENT arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%s ", arr[i].name);
		printf("%d ", arr[i].id);
		printf("%.2lf ", arr[i].averageGrade);
	}
}
//FOR DALED


