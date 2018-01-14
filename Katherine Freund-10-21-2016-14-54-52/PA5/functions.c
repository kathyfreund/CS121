#include "header.h"

//Print Game Menu
int print_game_menu(void)
{
	int choice = 0;
	printf("1. Print Game Rules\n");
	printf("2. Start a game of Yahtzee\n");
	printf("3. Exit\n\n\n");
	scanf("%d", &choice);
	return choice;
}


//Print Game Rules
void print_game_rules(void)
{
	system("cls");

	printf("\n\nHere's how it works:\n\n");
	printf("-You get 5 dice.\n");
	printf("-You roll your 5 dice.\n");
	printf("-You get two roll your 5 dice a total of three times each round.\n");
	printf("-You get to hold whichever die value you want at any given roll\n\n\n");


	printf("There are 13 possible combinations to gain points:\n\n");

	printf("-Three of a Kind, three dice with same face.    Sum of all dice.\n");
	printf("-Four of a Kind, four dice with same face.      Sum of all dice.\n");
	printf("-Full House, one pair and three of a kind.      25 points.\n");
	printf("-Small Straight, sequencce of four dice.        30 points.\n");
	printf("-Large Straight, sequence of five dice.         40 points.\n");
	printf("-Yahtzee, five dice with the same face.         50 points.\n");
	printf("-Chance, any combination.                       Sum of all dice.\n");
	printf("-6 more combinations, each a face value.        Add all single face values.\n\n");

	printf("NOTE: EACH COMBINATION MAY ONLY BE USED ONCE (total of 13 rounds)\n\n");
	printf("Ready to Give it a Go?\n\n\n");

	system("pause");
}


//rolls SINGLE die
int roll_die(void)
{
	int value = 0;
	value = (rand() % 6) + 1;
	return value;
}


//roll all dice
int roll_all_dice(int dice_values[5], int roll_values[5])
{
	int index = 0;
	getchar();
	for (index = 0; index <= 4; index++)
	{
		if (roll_values[index] == 1)
		{
			dice_values[index] = roll_die();
		}
	}
}

//re roll dice, when prompted in main
int re_roll_dice(int roll_values[5])
{
	int re_roll = 2, x = 6, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;

	roll_values[0] = 0;
	roll_values[1] = 0;
	roll_values[2] = 0;
	roll_values[3] = 0;
	roll_values[4] = 0;

	while (re_roll == 2)
	{
		printf("How many dice would you like to re-roll? ");
		scanf("%d", &x);

		if (x == 0)
		{
			re_roll = 0;
		}
		else if (x == 1)
		{
			printf("Which dice would you like to re-roll? ");
			scanf("%d", &n1);
			roll_values[(n1)-1] = 1;
			re_roll = 1;
		}
		else if (x == 2)
		{
			printf("Which dice would you like to re-roll? ");
			scanf("%d%d", &n1, &n2);
			roll_values[(n1)-1] = 1;
			roll_values[(n2)-1] = 1;
			re_roll = 1;
		}
		else if (x == 3)
		{
			printf("Which dice would you like to re-roll? ");
			scanf("%d%d%d", &n1, &n2, &n3);
			roll_values[(n1)-1] = 1;
			roll_values[(n2)-1] = 1;
			roll_values[(n3)-1] = 1;
			re_roll = 1;
		}
		else if (x == 4)
		{
			printf("Which dice would you like to re-roll? ");
			scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
			roll_values[(n1)-1] = 1;
			roll_values[(n2)-1] = 1;
			roll_values[(n3)-1] = 1;
			roll_values[(n4)-1] = 1;
			re_roll = 1;
		}
		else if (x == 5)
		{
			printf("Which dice would you like to re-roll? ");
			scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);
			roll_values[(n1)-1] = 1;
			roll_values[(n2)-1] = 1;
			roll_values[(n3)-1] = 1;
			roll_values[(n4)-1] = 1;
			roll_values[(n5)-1] = 1;
			re_roll = 1;
		}
		else
		{
			printf("Error: invalid user input\n\n");
		}
	}
	return re_roll;
}


//Get count of die faces
void get_faces(int dice_values[5], int faces[7])
{
	int index = 0, n = 0;

	faces[1] = 0;
	faces[2] = 0;
	faces[3] = 0;
	faces[4] = 0;
	faces[5] = 0;
	faces[6] = 0;

	for (index = 0; index <= 4; index++)
	{
		n = dice_values[index];
		if ((n > 0) && (n < 7))
		{
			faces[n] += 1;
		}
	}
}

//Get combos
int get_combo(int faces[7], int combinations[13], int dice_values[5])
{
	int n = 0, error = 0, score = 0, size = 0;
	do
	{
		error = 0;
		printf("\n1 = Faces of 1    7 = Three-of-a-Kind\n2 = Faces of 2    8 = Four-of-a-Kind\n3 = Faces of 3    9 = Full House\n4 = Faces of 4   10 = Small Straight\n5 = Faces of 5   11 = Large Straight\n6 = Faces of 6   12 = Yahtzee\n                 13 = Chance");
		printf("\n\nWhich combination would you like to select? ");
		scanf("%d", &n);

		if ((n > 13) || (n < 1))
		{
			printf("Error: invalid user input\n");
			error = 1;
		}
		else if (combinations[n - 1] == 1)
		{
			printf("Error: combination already used");
			error = 1;
		}
		else if ((combinations[n - 1] == 0) && (error == 0))
		{
			if (n == 1) // Faces of 1
			{
				score = faces[1];
				combinations[0] = 1;
			}
			else if (n == 2) // Faces of 2
			{
				score = faces[2] * 2;
				combinations[1] = 1;
			}
			else if (n == 3) // Faces of 3
			{
				score = faces[3] * 3;
				combinations[2] = 1;
			}
			else if (n == 4) // Faces of 4
			{
				return faces[4] * 4;
				combinations[3] = 1;
			}
			else if (n == 5) // Faces of 5
			{
				score = faces[5] * 5;
				combinations[4] = 1;
			}
			else if (n == 6) // Faces of 6
			{
				score = faces[6] * 6;
				combinations[5] = 1;
			}
			else if (n == 7) // Three-of-a-Kind
			{
				if ((faces[1] == 4) || (faces[2] == 4) || (faces[3] == 4) || (faces[4] == 4) || (faces[5] == 4) || (faces[6] == 4) || (faces[1] == 3) || (faces[2] == 3) || (faces[3] == 3) || (faces[4] == 3) || (faces[5] == 3) || (faces[6] == 3))
				{
					score = dice_values[0] + dice_values[1] + dice_values[2] + dice_values[3] + dice_values[4];
					combinations[6] = 1;
				}
				else
				{
					score = 0;
					combinations[6] = 1;
				}
			}
			else if (n == 8) // Four-of-a-Kind
			{
				if ((faces[1] == 4) || (faces[2] == 4) || (faces[3] == 4) || (faces[4] == 4) || (faces[5] == 4) || (faces[6] == 4))
				{
					score = dice_values[0] + dice_values[1] + dice_values[2] + dice_values[3] + dice_values[4];
					combinations[7] = 1;
				}
				else
				{
					score = 0;
					combinations[7] = 1;
				}
			}
			else if (n == 9) // Full House
			{
				if (((faces[1] == 3) || (faces[2] == 3) || (faces[3] == 3) || (faces[4] == 3) || (faces[5] == 3) || (faces[6] == 3)) && ((faces[1] == 2) || (faces[2] == 2) || (faces[3] == 2) || (faces[4] == 2) || (faces[5] == 2) || (faces[6] == 2)))
				{
					score = 25;
					combinations[8] = 1;
				}
				else
				{
					score = 0;
					combinations[8] = 1;
				}
			}
			else if (n == 10) // Small Straight
			{
				size = test_straight(faces, 4);
				if (size >= 4)
				{
					score = 30;
					combinations[9] = 1;
				}
				else
				{
					score = 0;
					combinations[9] = 1;
				}
			}
			else if (n == 11) // Large Straight
			{
				size = test_straight(faces, 5);
				if (size >= 5)
				{
					score = 40;
					combinations[10] = 1;
				}
				else
				{
					score = 0;
					combinations[10] = 1;
				}
			}
			else if (n == 12) // Yahtzee
			{
				if ((faces[1] == 5) || (faces[2] == 5) || (faces[3] == 5) || (faces[4] == 5) || (faces[5] == 5) || (faces[6] == 5))
				{
					score = 50;
					combinations[11] = 1;
				}
				else
				{
					score = 0;
					combinations[11] = 1;
				}
			}
			else // Chance
			{
				score = dice_values[0] + dice_values[1] + dice_values[2] + dice_values[3] + dice_values[4];
				combinations[12] = 1;
			}
		}
	} while (error == 1);
	return score;
}



//Is the claimed straight really a straight?
int test_straight(int faces[7], int straight_size)
{
	int n = 0, index = 1;
	for (index = 1; index <= 6; index++)
	{
		if (faces[index] != 0)
		{
			n++;
		}
		else if (faces[index] == 0)
		{
			n = 0;
		}
		if (n == straight_size)
		{
			return n;
		}
	}
	return n;
}



//Wanna play again?
int ask_new_game(void)
{
	int value = 2;
	char n = '\0';
	while (value == 2)
	{
		printf("Would you like to play again? (Y/N): ");
		scanf(" %c", &n);
		if ((n == 'Y') || (n == 'y'))
		{
			value = 1;
		}
		else if ((n == 'N') || (n == 'n'))
		{
			value = 0;
		}
		else
		{
			printf("Error: invalid user input\n\n");
		}
	}
	return value;
}



//Reset combos if user wants to play again
void reset_combinations(int combinations[13])
{
	int index = 0;
	for (index = 0; index <= 12; index++)
	{
		combinations[index] = 0;
	}
}