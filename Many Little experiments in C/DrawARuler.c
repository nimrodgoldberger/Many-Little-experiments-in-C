#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void drawRuler(int k);

void main()
{
	int k;
	//printf("Please enter a number for the length of the ruler.\n");
	scanf("%d", &k);
	drawRuler(k);
}

void drawRuler(int k)
{
	if(k == 1)
		printf("-\n");
	else
	{
		drawRuler(k - 1);
		for(int i = 0; i < k; i++)
		{
			printf("-");
		}
		printf("\n");
		drawRuler(k - 1);

	}

}

