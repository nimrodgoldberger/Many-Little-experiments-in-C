/*
This program offers the user 5 drinks and asks the  user to choose one,
if there are bottles left,
it shows the amount of nis(money) required and asks the user to enter the amount of different coins to make the purchase,
and finally, tells the user the amount and different coins of spare change he has to recieve.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int waternum = 10, orangenum = 10, applenum = 10, spritenum = 10, colanum = 10, finalprice = 0;
	int drink, coin1, coin2, coin5, coin10, payment = 0, change;
	printf("Please choose:\n 1. Water.\n 2. Orange juice.\n 3. Apple juice.\n 4. Sprite.\n 5. Cola.\n 6. exit.\n");
	scanf("%d", &drink);

	while(drink != 6)
	{
		if(1 > drink || 6 < drink)
		{
			printf("Invalid choice.\n");
		}
		else
		{
			switch(drink)
			{
			case 1:
				if(waternum > 0)
				{
					waternum--;
					finalprice = 9;
					break;
				}
				else
				{
					printf("There are no bottles of water left.\n");
					break;
				}
			case 2:
				if(orangenum > 0)
				{
					orangenum--;
					finalprice = 8;
					break;
				}
				else
				{
					printf("There are no bottles of orange juice left.\n");
					break;
				}
			case 3:
				if(applenum > 0)
				{
					applenum--;
					finalprice = 8;
					break;
				}
				else
				{
					printf("There are no bottles of apple juice left.\n");
					break;
				}
			case 4:
				if(spritenum > 0)
				{
					spritenum--;
					finalprice = 4;
					break;
				}
				else
				{
					printf("There are no bottles of sprite left.\n");
					break;
				}
			case 5:
				if(colanum > 0)
				{
					colanum--;
					finalprice = 4;
					break;
				}
				else
				{
					printf("There are no bottles of cola left.\n");
					break;
				}
			}
			while(finalprice > payment)
			{
				printf("The price is %d nis.\n To pay please enter 4 numbers. The first number is the amount of 1 nis coins, the second is the amount of 2 nis coins, then 5 and 10\n Please enter payment (1, 2, 5, 10):\n", finalprice);
				scanf("%d%d%d%d", &coin1, &coin2, &coin5, &coin10);
				payment = coin1 + (coin2 * 2) + (coin5 * 5) + (coin10 * 10);
				if(finalprice > payment)
				{
					printf("The amount does not suffice! please enter %d more nis.\n", finalprice - payment);
					printf("To pay please enter 4 numbers. The first number is the amount of 1 nis coins, the second is the amount of 2 nis coins, then 5 and 10\n Please enter payment (1, 2, 5, 10):\n", finalprice);
					scanf("%d%d%d%d", &coin1, &coin2, &coin5, &coin10);
					payment = payment + coin1 + coin2 * 2 + coin5 * 5 + coin10 * 10;
				}
			}
			if(payment > finalprice)
			{
				printf("your change is %d nis.\n", payment - finalprice);
				printf("You get back (1, 2, 5, 10): %d %d %d %d.\n", ((((payment - finalprice) % 10) % 5) % 2) / 1, (((payment - finalprice) % 10) % 5) / 2, ((payment - finalprice) % 10) / 5, (payment - finalprice) / 10);
				printf("Thank you for buying!\n");
			}
			else
			{
				if((payment == finalprice) && (finalprice != 0))
				{
					printf("Thank you for buying!\n");
				}
			}
		}
		payment = 0;
		finalprice = 0;
		printf("Please choose:\n 1. Water.\n 2. Orange juice.\n 3. Apple juice.\n 4. Sprite.\n 5. Cola\n 6. exit.\n");
		scanf("%d", &drink);
	}
	printf("Good bye.");
}