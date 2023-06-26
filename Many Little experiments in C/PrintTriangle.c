#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printTriangle(int n);

void main()
{
	int n;
	scanf("%d", &n);
	printTriangle(n);
}

void printTriangle(int n)
{
	if(n == 1)
	{
		printf("*\n");
	}

	else
	{
		printTriangle(n - 1);
		int i;
		for(i = 0; i < n; i++)
		{
			printf("*");
		}
		printf("\n");
	}

}
