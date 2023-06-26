/* This program offers the user 5 drinks and asks the  user to choose one, then,
it shows the amount of nis(money) required and asks the user to enter the amount of different coins to make the purchase,
and finally, tells the user the amount of spare change he has to recieve.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int drink, price, one, two, five, ten, payment, change;
	printf("Please choose:\n 1. Water.\n 2. Orange juice.\n 3. Apple juice.\n 4. Sprite.\n 5. Cola\n");
	scanf("%d", &drink);
	if(drink == 1)
		price = 9;
	else
	{
		if(drink == 2 || drink == 3)
			price = 8;
		else if(drink == 4 || drink == 5)
			price = 4;
	}
	if(1 > drink || 5 < drink)
	{
		printf("Invalid choice.");
	}
	else
	{
		printf("The price is %d nis.\n To pay please enter 4 numbers. The first number is the amount of 1 nis coins, the second is the amount of 2 nis coins, then 5 and 10\n Please enter payment (1, 2, 5, 10):\n", price);
		scanf("%d%d%d%d", &one, &two, &five, &ten);
		payment = one + (two * 2) + (five * 5) + (ten * 10);
		if(payment >= price)
		{
			change = payment - price;
			printf("Your change is : %d nis.", change);
		}
		else
		{
			printf("The amount does not suffice!");
		}
	}
}