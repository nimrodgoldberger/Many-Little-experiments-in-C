#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int* blowUpArray(int numArray[], int amountArray[], int size);
void printArray(int arr[], int size);
void fillArray(int* arr, int size);
int getSize(int* arr, int size);
void CheckAlloc(int* arr);


void main()//[2,5,3,7,8], [5,2,0,4,3], 5
{
	int size;
	int	blowUpSize;
	int* numArray;
	int* amountArray;
	int* blowUp;
	scanf("%d", &size);
	numArray = (int*)malloc(size * sizeof(int));
	CheckAlloc(numArray);
	amountArray = (int*)malloc(size * sizeof(int));
	CheckAlloc(amountArray);
	fillArray(numArray, size);
	fillArray(amountArray, size);

	blowUpSize = getSize(amountArray, size);

	//blowUp = (int*)malloc(blowUpSize * sizeof(int));
	//CheckAlloc(blowUp);

	blowUp = blowUpArray(numArray, amountArray, size);

	printArray(blowUp, blowUpSize);//[2,2,2,2,2,5,5,7,7,7,7,8,8,8]
	free(numArray);
	free(amountArray);
	free(blowUp);
}


int* blowUpArray(int numArray[], int amountArray[], int size)
{
	int currentamount, i, j, skipped = 0, blowUpSize, counter = 0;
	blowUpSize = getSize(amountArray, size);
	int* blowUp = (int*)malloc(blowUpSize * sizeof(int));
	CheckAlloc(blowUp);
	for(i = 0; i < size; i++)
	{
		if(amountArray[i] != 0)
		{
			currentamount = amountArray[i];
			for(j = 0; (j < currentamount); j++)
			{
				blowUp[counter] = numArray[i];
				counter++;
			}

		}
	}
	return blowUp;
}

void CheckAlloc(int* arr)
{
	if(arr == NULL)
	{
		printf("The Allocation was unsucessfull. The PROGRAM WILL NOW CLOSE\n\n");
		exit(0);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void fillArray(int* arr, int size)
{
	int i, temp;
	for(i = 0; i < size; i++)
	{
		scanf("%d", &temp);
		*(arr + i) = temp;
	}
}

int getSize(int* arr, int size)
{
	int i, blowUpsize = 0;
	for(i = 0; i < size; i++)
	{
		blowUpsize += arr[i];
	}
	return blowUpsize;
}


