#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool haveSameElems(int arr1[], int arr2[], int size);
bool SearchIfInArray(int arr1[], int arr2[], int size);

void main()
{
	int size = 5;
	int arr1[5];// 1 2 6 5 1
	int arr2[5];//2 5 6 2 1
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &arr2[i]);
	}
	//scanf("%d", &size);


	printf("%d", haveSameElems(arr1, arr2, size));//true
}


bool haveSameElems(int arr1[], int arr2[], int size)
{
	if(size == 0)
	{
		return true;
	}

	else
	{
		if(SearchIfInArray(arr1, arr2, size) == true)
			haveSameElems(arr1, arr2, size - 1);
		else
		{
			return false;
		}

	}
}


bool SearchIfInArray(int arr1[], int arr2[], int size)
{
	bool isORnot = false;
	for(int j = 0; j < size; j++)
	{
		if(arr1[size - 1] == arr2[j])
		{
			int temp = arr2[j];
			arr2[j] = arr2[size - 1];
			arr2[size - 1] = temp;
			isORnot = 1;
		}
	}
	return isORnot;
}
