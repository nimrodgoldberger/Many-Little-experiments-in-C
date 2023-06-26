/*
This program asks the user to pick a size for a drawing, then shows the user the menu of 5 drinks and has a total of 10 units,
the user then has to pay the price of the drink in 4 different coins and the program calculates the change with the least number of coins.
And finally prints a painting corresponding to each drink.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Sumnis(int n1, int n2, int n3, int n4);//function that calculates the money.
int Cashier(int amount, int price, int drink, int n);//function that calculates if need change.
void Menu();
void Painting(int drink, int n);
int payment(int finalprice, int drink, int n);


void main()
{
	int n;
	printf(" Please enter drawing's size: \n");
	scanf("%d", &n);
	if(n > 0)
	{
		int drink, nis1, nis2, nis5, nis10, finalprice = 0, amount = 0;
		int WaterPrice = 9, OrangeJuicePrice = 8, AppleJuicePrice = 8, SpritePrice = 4, ColaPrice = 4;
		int countWater = 10, countOrange = 10, countApple = 10, countSprite = 10, countCola = 10;
		Menu();
		scanf("%d", &drink);
		while(drink != 6)
		{
			if(drink > 6 || drink < 1)
			{
				printf("Invalid choice.\n");
			}
			else
			{
				switch(drink)
				{
				case 1:
				{
					if(countWater > 0)
					{
						countWater--;
						printf("The price is 9 nis.\n");
						finalprice = WaterPrice;
						payment(finalprice, drink, n);
						break;
					}
					else
					{
						printf("There are no bottles of water left.\n");
						break;
					}
				}
				case 2:
				{
					if(countOrange > 0)
					{
						countOrange--;
						printf("The price is 8 nis.\n");
						finalprice = OrangeJuicePrice;
						payment(finalprice, drink, n);
						break;
					}
					else
					{
						printf("There are no bottles of orange juice Left.\n");
						break;

					}
				}
				case 3:
				{
					if(countApple > 0)
					{
						countApple--;
						printf("The price is 8 nis.\n");
						finalprice = AppleJuicePrice;
						payment(finalprice, drink, n);
						break;
					}
					else
					{
						printf("There are no bottles of apple juice Left.\n");
						break;
					}
				}
				case 4:
				{
					if(countSprite > 0)
					{
						countSprite--;
						printf("The price is 4 nis.\n");
						finalprice = SpritePrice;
						payment(finalprice, drink, n);
						break;

					}
					else
					{
						printf("There are no bottles of sprite Left.\n");
						break;
					}
				}
				case 5:
				{
					if(countCola > 0)
					{
						countCola--;
						printf("The price is 4 nis.\n");
						finalprice = ColaPrice;
						payment(finalprice, drink, n);
						break;

					}
					else
					{
						printf("There are no bottles of cola Left.\n");
						break;
					}

				}
				}

			}
			amount = 0;
			finalprice = 0;
			Menu();
			scanf("%d", &drink);

		}
		printf("Good bye.");
	}
	else
	{
		printf("Invalid size.");
	}
}
//functions
void Menu()
{
	printf("********************\n");
	printf("* Please choose:   *\n");
	printf("* 1. Water.        *\n");
	printf("* 2. Orange juice. *\n");
	printf("* 3. Apple juice.  *\n");
	printf("* 4. Sprite.       *\n");
	printf("* 5. Cola.         *\n");
	printf("* 6. exit.         *\n");
	printf("********************\n");

}
int Sumnis(int n1, int n2, int n5, int n10)
{
	return (n1 + n2 * 2 + n5 * 5 + n10 * 10);
}
int Cashier(int amount, int price, int drink, int n)
{
	int nis1, nis2, nis5, nis10;
	while(price > amount)
	{
		printf("The amount does not suffice! please enter %d more nis.\n", price - amount);
		printf("To pay please enter 4 numbers. The first number is the amount of \n1 nis coins, the second is the amount of 2 nis coins , then 5 and 10\n");
		printf("Please enter payment (1, 2, 5, 10):\n\n");
		scanf("%d%d%d%d", &nis1, &nis2, &nis5, &nis10);
		amount = amount + Sumnis(nis1, nis2, nis5, nis10);
	}
	printf("your change is: %d nis.\n", amount - price);
	printf("You get back (1, 2, 5, 10): %d %d %d %d.\n", ((((amount - price) % 10) % 5) % 2) / 1, (((amount - price) % 10) % 5) / 2, ((amount - price) % 10) / 5, (amount - price) / 10);
	printf("\nThank you for buying!\n\n");
	Painting(drink, n);
}
void Painting(int drink, int n)
{
	switch(drink)
	{
	case 1:
	{
		for(int j = 1; j < n; j++)
		{
			for(int i = 1; i <= 2 * n; i++)
			{
				printf("W");
			}
			printf("\n");
		}
		printf("W");
		for(int z = 1; z <= ((n * 2) - 2); z++)
		{
			printf(" ");
		}
		printf("W\n");
		printf("W");
		for(int z = 1; z <= ((n * 2) - 2); z++)
		{
			printf(" ");
		}
		printf("W\n");
		for(int j = 1; j < n; j++)
		{
			for(int i = 1; i <= 2 * n; i++)
			{
				printf("W");
			}
			printf("\n");
		}
		break;
	}
	case 2:
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				printf("O");
			}
			printf("\n");
		}
		break;
	}
	case 3:
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < n - i; j++)
			{
				printf(" ");
			}
			for(int z = 1; z <= i; z++)
			{
				printf("A");
			}
			printf("\n");
		}
		break;
	}
	case 4:
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < n - i; j++)
			{
				printf(" ");
			}
			for(int j = 1; j <= ((i * 2) - 1); j++)
			{
				printf("S");
			}
			for(int j = 0; j < n - i; j++)
			{
				printf(" ");
			}
			printf("\n");
		}
		break;
	}
	case 5:
	{
		int row, space, C, numOfSpaces = 0;

		for(row = n; row >= 1; row -= 2) // loop for rows
		{
			// sequence of spaces
			for(space = 0; space < numOfSpaces; space++)
			{
				printf(" ");
			}

			// sequence of stars
			for(C = 1; C <= row; C++)
			{
				printf("C");
			}

			// print ENTER
			printf("\n");
			numOfSpaces++;
		}
		numOfSpaces--;
		for(row = 1; row <= n; row += 2) // loop for rows
		{
			// sequence of spaces
			for(space = 0; space < numOfSpaces; space++)
			{
				printf(" ");
			}

			for(C = 1; C <= row; C++)
			{
				printf("c");
			}

			// print ENTER
			printf("\n");
			numOfSpaces--;
		}
		break;
	}
	}
}
int payment(int finalprice, int drink, int n)
{
	int nis1, nis2, nis5, nis10, amount = 0;
	printf("To pay please enter 4 numbers. The first number is the amount of \n1 nis coins, the second is the amount of 2 nis coins , then 5 and 10\n");
	printf("Please enter payment (1, 2, 5, 10):\n");
	scanf("%d%d%d%d", &nis1, &nis2, &nis5, &nis10);
	amount = Sumnis(nis1, nis2, nis5, nis10);
	if(amount != finalprice)
	{
		Cashier(amount, finalprice, drink, n);
	}
	else
	{
		printf("Thank you for buying!\n");
		Painting(drink, n);
	}
}