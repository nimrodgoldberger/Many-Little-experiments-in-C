#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void intToStr(unsigned int num, char s[]);
unsigned int NumofDig(unsigned int num);


void main()
{
	unsigned int num;
	char s[10];
	printf("Enter a number\n");
	scanf("%u", &num);
	intToStr(num, s);
	printf("%s", s);
}


void intToStr(unsigned int num, char s[])//256
{
	int size = NumofDig(num);
	if(size == 1)
	{
		s[0] = num + '0';
	}
	else
	{
		intToStr(num / 10, s);
		s[size - 1] = num % 10 + '0';
		s[size] = '\0';
	}
}


unsigned int NumofDig(unsigned int num)
{
	int dignum = 0;
	while(num != 0)
	{
		num = num / 10;
		dignum++;
	}
	return dignum;
}