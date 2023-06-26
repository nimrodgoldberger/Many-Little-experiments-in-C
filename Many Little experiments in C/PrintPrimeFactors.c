#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printPrimeFactors(int num);

void main()
{
	int num;
	scanf("%d", &num);
	printPrimeFactors(num);
}

void printPrimeFactors(int num)
{
	if(num < 2)
		return;
	else
	{
		//the smallest prime number
		int i = 2;//45

		while(num % i != 0 && i <= num)//search for next divider from the minimal prime so bigger non primes that divide the num won't even be here 
		{
			i++;
		}
		printf("%d ", i);
		printPrimeFactors(num / i);
	}
}