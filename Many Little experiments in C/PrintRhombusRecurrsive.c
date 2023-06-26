#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printOpositeTriangles(int n);
void printTriangleLine(n);

void main()
{
	int n;
	//printf("Please enter a number for the base of the triangle of stars.\n");
	scanf("%d", &n);
	printOpositeTriangles(n);
}

void printOpositeTriangles(int n)
{
	if(n == 1)
	{
		printTriangleLine(n);
		printTriangleLine(n);
	}
	else
	{
		printTriangleLine(n);
		printOpositeTriangles(n - 1);
		printTriangleLine(n);

	}
}

void printTriangleLine(n)
{
	for(int i = 0; i < n; i++)
	{
		printf("*");
	}
	printf("\n");
}




