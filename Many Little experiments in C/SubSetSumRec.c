#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool subsetSum(int numbers[], int size, int sum);


void main()
{
	int sum;
	int numbers[5];
	int size = 5;
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &numbers[i]);
	}
	scanf("%d", &sum);

	printf("%d", subsetSum(numbers, size, sum));
}

bool subsetSum(int numbers[], int size, int sum)//1,5,3,9,10   14
{
	if(sum < 0 || size == 0)//5
	{
		return false;
	}
	else if(sum > 0)
	{
		if(subsetSum(numbers, size - 1, sum) == true || subsetSum(numbers, size - 1, sum - numbers[size - 1]) == true)
			return true;
		else
		{
			return false;
		}
	}
	else if(sum == 0)
		return true;
}




