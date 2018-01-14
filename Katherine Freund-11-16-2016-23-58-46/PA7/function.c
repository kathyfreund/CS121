#include "header.h"

int print_menu(void)
{
	int value = 0;
	do
	{
		printf("Let's Do Some Math!\n\n");
		printf("  1 - Learn How to use this program\n  2 - Enter your initials\n  3 - Select difficulty\n  4 - Get Started\n  5 - Save and quit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &value);
		flushall();
		if ((value < 1) || (value > 5))
		{
			printf("\nError: invalid user input\n\n");
			system("pause");
			system("cls");
		}
	} while ((value < 1) || (value > 5));
	system("cls");
	return value;
}


void print_rules(void)
{
	printf("As problems appear on the screen, attempt to answer them correctly. A correct\nanswer results in a number of points equal to the difficulty level. An\nincorrect answer results in the loss of a single point, regardless of\ndifficulty. The difficulty will automatically start at level 1. When dividing,\ndo not include remainders, and enter all answers as integer values. Each round\nconsists of 10 questions.\n\n");
	system("pause");
	system("cls");
}


void get_initials(Stats player)
{
	char str[100] = { 0 };
	printf("Enter your initials: ");
	scanf("%s", &player.initials);
	system("pause");
	system("cls");
}


int get_difficulty(void)
{
	int value = 0;
	printf("Enter difficulty (1-5): ");
	scanf("%d", &value);
	flushall();
	printf("\n");
	system("pause");
	system("cls");
	return value;
}



void write_stats(Stats player, FILE *infile)
{
	//	fprintf (infile, "%s\n", player.initials);
	fprintf(infile, "%c%c%c\n", player.initials[0], player.initials[1], player.initials[2]);
	fprintf(infile, "%d", player.score);
}









//int simple_problem(int a, int op, int b)
//{
//	int value = 0;
//	if (op == 0) // addition
//	{
//		value = a + b;
//	}
//	else if (op == 1) // subtraction
//	{
//		value = a - b;
//	}
//	else if (op == 2) // multiplication
//	{
//		value = a*b;
//	}
//	else if (op == 3) // division
//	{
//		value = a / b;
//	}
//	return value;
//}
//
//
//
//int solve_helper(int set[7], int order[3], int temp)
//{
//	int value = 0;
//	value = simple_problem(set[order[0] - 1], set[order[0]], set[order[0] + 1]);
//	if (temp > 0) // 3 or 4 terms
//	{
//		value = simple_problem(value, set[order[0]], set[order[0] + 1]);
//		if (temp == 2) // 4 terms
//		{
//			value = simple_problem(value, set[order[0]], set[order[0] + 1]);
//		}
//	}
//	return value;
//}
//
//
//int order_helper(int n)
//{
//	int value = 0;
//	if ((n == 3) || (n == 2)) // multiplication and division have same precedence
//	{
//		value = 1;
//	}
//	return value;
//}



int solve_problem(int set[7], int temp)
{
	//int value = 0, i = 1, iterations = 0, order[3] = { 0 };
	//temp += 1;
	//iterations = temp * 2;
	//iterations += 1;
	//i = order[0];
	//for (i = 1; i < iterations; i + 2) // this determines order of operations
	//{
	//	if (order_helper(set[i]) > order_helper(set[order[0]]))
	//	{
	//		order[2] = order[1];
	//		order[1] = order[0];
	//		order[0] = i;
	//	}
	//	else if (order_helper(set[i]) > order_helper(set[order[1]]))
	//	{
	//		order[2] = order[1];
	//		order[1] = i;
	//	}
	//	else
	//	{
	//		order[2] = i;
	//	}
	//}
	//value = solve_helper(set, order, (temp - 1));
	//return value;



	//FIY, I REALLY REALLY HATED THIS PART, GOD DAMN UGH

	int value = 0, v1 = 0, v2 = 0;

	if (temp == 0) //two values
	{
		if (set[1] == 0)
		{
			value = set[0] + set[2];
		}
		else if (set[1] == 1)
		{
			value = set[0] - set[2];
		}
		else if (set[1] == 2)
		{
			value = set[0] * set[2];
		}
		else if (set[1] == 3)
		{
			value = set[0] / set[2];
		}
	}
	else if (temp == 1) //three values
	{
		if (set[1] == 2 || set[1] == 3) //if first operator is * or /
		{
			if (set[1] == 2) //first multiplication
			{
				v1 = set[0] * set[2];
				if (set[3] == 0)
				{
					value = v1 + set[4];
				}
				else if (set[3] == 1)
				{
					value = v1 - set[4];
				}
				else if (set[3] == 2)
				{
					value = v1 * set[4];
				}
				else if (set[3] == 3)
				{
					value = v1 / set[4];
					if (set[4] == 0)
					{
						value = 0;
					}
				}
			}
			else if (set[1] == 3) //first division
			{
				v1 = set[0] / set[2];
				if (set[3] == 0)
				{
					value = v1 + set[4];
				}
				else if (set[3] == 1)
				{
					value = v1 - set[4];
				}
				else if (set[3] == 2)
				{
					value = v1 * set[4];
				}
				else if (set[3] == 3)
				{
					value = v1 / set[4];
					if (set[4] == 0)
					{
						value = 0;
					}
				}
				if (set[2] == 0)
				{
					value = 0;
				}
			}
		}
		else if (set[3] == 2 || set[3] == 3) //if second operator is * or //
		{
			if (set[3] == 2) //second multiplication
			{
				v1 = set[2] * set[4];
				if (set[1] == 0)
				{
					value = set[0] + v1;
				}
				else if (set[1] == 1)
				{
					value = set[0] - v1;
				}
				else if (set[1] == 2)
				{
					value = set[0] * v1;
				}
				else if (set[1] == 3)
				{
					value = set[0] / v1;
				
				}
			}
			else if (set[3] == 3) //second division
			{
				v1 = set[2] / set[4];
				if (set[1] == 0)
				{
					value = set[0] + 0;
				}
				else if (set[3] == 1)
				{
					value = set[0] - v1;
				}
				else if (set[3] == 2)
				{
					value = set[0] * v1;
				}
				else if (set[3] == 3)
				{
					value = set[0] / v1;
				}
				if (set[4] == 0)
				{
					value = 0;
				}
			}
		}
		else if ((set[1] == 0 || set[1] == 1) && (set[3] == 0 || set[3] == 1)) //bug is here
		{
			if (set[1] == 0)
			{
				v1 = set[0] + set[2];
				if (set[3] == 0)
				{
					value = v1 + set[4];
				}
				else if (set[3] == 1)
				{
					value = v1 - set[4];
				}
			}
			else if (set[1] == 1)
			{
				v1 = set[0] - set[2];
				if (set[3] == 0)
				{
					value = v1 + set[4];
				}
				else if (set[3] == 1)
				{
					value = v1 - set[4];
				}
			}
		}
	}// end of three values

	else if (temp == 2)
	{
		if (set[1] == 2 || set[1] == 3) //first operator takes lead
		{
			if (set[1] == 2)
			{
				v1 = set[0] * set[2];
			}
			else if (set[1] == 3)
			{
				v1 = set[0] / set[2];
				if (set[2] == 0)
				{
					v1 = 0;
				}
			}

			if (set[5] == 2 || set[5] == 3)
			{
				if (set[5] == 2)
				{
					v2 = set[4] * set[6];
				}
				else if (set[5] == 3)
				{
					v2 = set[4] / set[6];
					if (set[6] == 0)
					{
						v2 = 0;
					}
				}
			}
			else if (set[5] == 0 || set[5] == 1)
			{
				if (set[5] == 0)
				{
					v2 = set[4] + set[6];
				}
				else if (set[5] == 1)
				{
					v2 = set[4] - set[6];
				}
			}
			if (set[3] == 2)
			{
				value = v1 * v2;
			}
			else if (set[3] == 3)
			{
				value = v1 / v2;
				if (v2 == 0)
				{
					value = 0;
				}
			}
			else if (set[3] == 0)
			{
				value = v1 + v2;
			}
			else if (set[3] == 0)
			{
				value = v1 - v2;
			}
		}



		else if ((set[3] == 2 || set[3] == 3) && (set[3] != 2 || set[3] != 3)) //second operator takes lead
		{
			if (set[3] == 2)
			{
				v1 = set[2] * set[4];
			}
			else if (set[3] == 3)
			{
				v1 = set[2] * set[4];
			}

			if (set[5] == 2)
			{
				v2 = v1 * set[6];
			}
			else if (set[5] == 3)
			{
				v2 = v1 / set[6];
				if (set[6] == 0)
				{
					v2 = 0;
				}
			}
			else if (set[5] == 0)
			{
				v2 = v1 + set[6];
			}
			else if (set[5] == 1)
			{
				v2 = v1 - set[6];
			}

			if (set[1] == 2)
			{
				value = set[0] * v2;
			}
			else if (set[1] == 3)
			{
				value = set[0] / v2;
				if (v2 == 0)
				{
					value = 0;
				}
			}
			else if (set[1] == 0)
			{
				value = set[0] + v2;
			}
			else if (set[1] == 1)
			{
				value = set[0] - v2;
			}

		}
		else if ((set[5] == 2 || set[5] == 3) && (set[3] != 2 || set[3] != 3)
			&& (set[1] != 2 || set[1] != 3)) // third operator takes lead
		{
				if (set[5] == 2)
				{
					v1 = set[4] * set[6];
				}
				else if (set[5] == 3)
				{
					v1 = set[4] / set[6];
					if (set[6] == 0)
					{
						v1 = 0;
					}
				}
				else if (set[5] == 0)
				{
					v1 = set[4] + set[6];
				}
				else if (set[5] == 1)
				{
					v1 = set[4] - set[6];
				}

				if (set[1] == 2)
				{
					v2 = set[0] * set[2];
				}
				else if (set[1] == 3)
				{
					v2 = set[0] / set[2];
					if (set[2] == 0)
					{
						v2 = 0;
					}
				}
				else if (set[1] == 0)
				{
					v2 = set[0] + set[2];
				}
				else if (set[1] == 1)
				{
					v2 = set[0] - set[2];
				}

				if (set[3] == 2)
				{
					value = v1 * v2;
				}
				else if (set[3] == 3)
				{
					value = v1 / v2;
					if (v2 == 0)
					{
						value = 0;
					}
				}
				else if (set[3] == 0)
				{
					value = v1 + v2;
				}
				else if (set[3] == 1)
				{
					value = v1 - v2;
				}
		}
	}
	return value;
}











int get_number(int level)
{
	int value = 0, temp = 0;
	temp = (rand() % 2);
	if (level == 5)
	{
		if (temp == 0)
		{
			value = (rand() % 100); // two-digit number
		}
		else if (temp == 1)
		{
			value = (rand() % 1000); // three-digit number
		}
	}
	else
	{
		value = (rand() % 10); // one-digit number
	}
	if ((level == 4) || (level == 5))
	{
		if (temp == 1)
		{
			value *= -1; // number is negative
		}
	}
	return value;
}


int get_operator(int level)
{
	int value = 0;
	if (level == 1)
	{
		value = (rand() % 2); // '+' or '-'
	}
	else if (level == 2)
	{
		value = 2; // '*'
	}
	else if (level == 3)
	{
		value = 3; // '/'
	}
	else if (level == 4)
	{
		value = (rand() % 4); // all operators
	}
	else if (level == 5)
	{
		value = (rand() % 4); // all operators
	}
	return value;
}


















void print_problem(int set[7], int temp)
{
	int i = 1, iterations = 0;
	temp += 1;
	iterations = temp * 2;
	printf("%d", set[0]);
	for (i = 1; i < iterations + 1; i++)
	{
		if ((i % 2) == 1) // operator cell
		{
			if (set[i] == 0)
			{
				printf(" + ");
			}
			else if (set[i] == 1)
			{
				printf(" - ");
			}
			else if (set[i] == 2)
			{
				printf(" * ");
			}
			else if (set[i] == 3)
			{
				printf(" / ");
			}
		}
		else // number cell
		{
			printf("%d", set[i]);
		}
	}
	printf(" = ");
}


int ask_problem(int level)
{
	int set[7] = { 0 }, value = 0, temp = 0, answer = 0, correct = 0;
	if (level == 1)
	{
		temp = (rand() % 2);
		if (temp == 0) // two terms
		{
			set[0] = get_number(level);
			set[1] = get_operator(level);
			set[2] = get_number(level);
		}
		else // three terms
		{
			set[0] = get_number(level);
			set[1] = get_operator(level);
			set[2] = get_number(level);
			set[3] = get_operator(level);
			set[4] = get_number(level);
		}
	}
	else if (level == 2)
	{
		temp = 0;
		set[0] = get_number(level);
		set[1] = get_operator(level);
		set[2] = get_number(level);
	}
	else if (level == 3)
	{
		temp = 0;
		set[0] = get_number(level);
		set[1] = get_operator(level);
		set[2] = get_number(level);
	}
	else if (level == 4)
	{
		temp = (rand() % 2);
		if (temp == 0) // two terms
		{
			set[0] = get_number(level);
			set[1] = get_operator(level);
			set[2] = get_number(level);
		}
		else // three terms
		{
			set[0] = get_number(level);
			set[1] = get_operator(level);
			set[2] = get_number(level);
			set[3] = get_operator(level);
			set[4] = get_number(level);
		}
	}
	else if (level == 5)
	{
		temp = (rand() % 3);
		if (temp == 0) // two terms
		{
			set[0] = get_number(level);
			set[1] = get_operator(level);
			set[2] = get_number(level);
		}
		else if (temp == 1) // three terms
		{
			set[0] = get_number(level);
			set[1] = get_operator(level);
			set[2] = get_number(level);
			set[3] = get_operator(level);
			set[4] = get_number(level);
		}
		else // four terms
		{
			set[0] = get_number(level);
			set[1] = get_operator(level);
			set[2] = get_number(level);
			set[3] = get_operator(level);
			set[4] = get_number(level);
			set[5] = get_operator(level);
			set[6] = get_number(level);
		}
	}
	print_problem(set, temp);
	scanf("%d", &answer);
	correct = solve_problem(set, temp);

	if (answer == correct)
	{
		value = 1;
		printf("Correct!\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		value = 0;
		printf("Wrong! Correct answer is %d\n\n", correct);
		system("pause");
		system("cls");
	}
	return value;
}


