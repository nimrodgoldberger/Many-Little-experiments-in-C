#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int OrderStat(int array[], int size, int k);
void mergeSort(int arr[], int size);
int* merge(int a1[], int n1, int a2[], int n2);
void printArray(int arr[], int size);
void copyArr(int dest[], int src[], int size);

void main()
{
	int size, knum;
	int* arr;
	int temp;
	int k, i;
	//printf("Enter a size for the arr\n");
	scanf("%d", &size);
	//printf("Enter an arr\n");
	arr = (int*)malloc(size * sizeof(int));
	for(i = 0; i < size; i++)
	{
		scanf("%d", &temp);
		*(arr + i) = temp;
	}
	//printf("Enter a k for the function\n");
	scanf("%d", &k);
	//printf("Array before sort: \n");
	//printArray(arr, size);
	knum = OrderStat(arr, size, k);
	printf("%d", knum);
	//printf("the number in the k index would be: %d   \n\n\n", knum);
	free(arr);
}

int OrderStat(int array[], int size, int k)
{
	int kNum;
	int* tempArr;
	tempArr = (int*)malloc(size * sizeof(int));
	copyArr(tempArr, array, size);
	mergeSort(tempArr, size);
	kNum = *(tempArr + k - 1);
	//printf("Array after sort: \n");
	//printArray(tempArr, size);
	free(tempArr);
	return kNum;
}

void mergeSort(int arr[], int size)
{
	int* tmpArr = NULL;
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

int* merge(int a1[], int size1, int a2[], int size2)
{
	int ind1, ind2, resInd;
	int* res = (int*)malloc((size1 + size2) * sizeof(int));

	if(res)
	{
		ind1 = ind2 = resInd = 0;

		while((ind1 < size1) && (ind2 < size2))
		{
			if(a1[ind1] <= a2[ind2])
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

void printArray(int arr[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void copyArr(int dest[], int src[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		dest[i] = src[i];
}
