#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int numWays(int n);

void main()
{
	int num, res;
	scanf("%d", &num);
	res = numWays(num);
	printf("The number ow ways to climb is: %d\n", res);
}

int numWays(int n)
{
	if(n <= 1)
		return 1;
	else
		return numWays(n - 1) + numWays(n - 2);
}