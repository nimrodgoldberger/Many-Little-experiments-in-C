#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void minMax(int arr[], int left, int right, int min_max[]);

void main()
{
	int arr[5], min_max[2], left, right;//1 -3 4 5 9 1 3
	scanf("%d%d%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &left, &right);
	if(left == right)
	{
		min_max[0] = arr[left];
		min_max[1] = arr[right];
	}
	else
	{
		min_max[0] = arr[left + 1];
		min_max[1] = arr[right - 1];
		minMax(arr, left, right, min_max);
	}
	printf("%d %d", min_max[0], min_max[1]);
}

void minMax(int arr[], int left, int right, int min_max[])
{
	if(left >= right)
		return;
	else
	{
		if(arr[left] > arr[right])
		{
			if(arr[left] >= min_max[1])
			{
				min_max[1] = arr[left];
				minMax(arr, left + 1, right, min_max);
			}
			if(arr[right] <= min_max[0])
			{
				min_max[0] = arr[right];
				minMax(arr, left + 1, right - 1, min_max);
			}
		}
		else if(arr[left] < arr[right])
		{
			if(arr[right] >= min_max[1])
			{
				min_max[1] = arr[right];
				minMax(arr, left, right - 1, min_max);
			}
			if(arr[left] <= min_max[0])
			{
				min_max[0] = arr[left];
				minMax(arr, left + 1, right - 1, min_max);
			}
		}
		else
		{
			if(arr[right] >= min_max[1])
			{
				min_max[1] = arr[right];
			}
			if(arr[right] <= min_max[0])
			{
				min_max[0] = arr[right];
			}
			minMax(arr, left + 1, right - 1, min_max);
		}
	}
}