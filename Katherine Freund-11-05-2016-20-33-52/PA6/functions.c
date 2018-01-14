#include "header.h"

//Print Game Menu
int print_game_menu(void)
{
	int value = 0;
	printf("THIS IS BATTLESHIP!!!\n\n");
	printf("What would you like to do?\n\n   1 - RuL3Z\n   2 - Man up and Play\n   3 - Wimp out\n\n");
	printf("Enter choice (1,2,3): ");
	scanf("%d", &value);
	return value;
}

//New Game?
int ask_new_game(void)
{
	int value = 2;
	char n = '\0';
	while (value == 2)
	{
		printf("Are you good enought to play again? (Y/N): ");
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
			printf("Stupid, put in the right thing.\n\n");
		}
	}
	return value;
}

//Print Gamr Rules
void print_game_rules(void)
{
	system("cls");
	printf("Set-Up:\nThe Player and the Computer secretly place their ships horizontally or\nvertically on the grid. The ships cannot be moved during gameplay.\n\n");
	printf("Shooting:\nThe Player and the Computer alternate calling out shots at the opponent's ships.\nA shot is called with grid coordinates consisting of two numbers (ie 2 7). If\npart of a ship lies at that coordinate, a Hit (#) is called, otherwise the shot\nis a Miss (m).\n\n");
	printf("Sinking Ships:\nWhen all grid spaces that a ship lies on have been Hit, that ship is sunk. The\nnumber of spaces each ship occupies are:\n\n");
	printf("  Carrier    (C) = 5 spaces\n  Battleship (B) = 4 spaces\n  Cruiser    (R) = 3 spaces\n  Submarine  (S) = 3 spaces\n  Destroyer  (D) = 2 spaces\n\n");
	printf("Winning:\nThe Player or Computer wins when all of the opponent's ships have been sunk.\n\n");
	system("pause");
}

//Stats
void print_stats(FILE *outfile, Stats p1, Stats p2)
{
	if (p1.is_win == TRUE)
	{
		printf("\nWow, you actually won?!\n\n");
	}
	else if (p2.is_win == TRUE)
	{
		printf("\nHaha, you lost against a computer.!\n\n");
	}
	fprintf(outfile, "Player:\n%d Hits\n%d Misses\n%d Total\n%.2lf Hit/Miss Ratio\n\n", p1.shots_hit, p1.shots_miss, p1.shots_total, p1.shots_ratio);
	fprintf(outfile, "Computer:\n%d Hits\n%d Misses\n%d Total\n%.2lf Hit/Miss Ratio\n\n", p2.shots_hit, p2.shots_miss, p2.shots_total, p2.shots_ratio);
}

//Reset Board
void init_board(char board[10][10])
{
	int i_row = 0, i_col = 0;
	for (i_row = 0; i_row < 10; i_row++)
	{
		for (i_col = 0; i_col < 10; i_col++)
		{
			board[i_row][i_col] = WATER;
		}
	}
}

//Manual or Random?
int determine_setup(void)
{
	int value = 2;
	char n = '\0';
	while (value == 2)
	{
		printf("Do you want to get off your but and set up your ships by hand? (Y/N): ");
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
			printf("Stupid, put in the right thing.\n\n");
		}
	}
	return value;
}

//Random Ships
void placement_random(char board[10][10], char ship, int size)
{
	int direction = 0; // 0 = horizontal, 1 = vertical
	int row = 0, col = 0; // start coordinates
	int occupied = 1, index = 0, count = 0;
	while (occupied == 1)
	{
		direction = rand() % 2;
		if (direction == 0)
		{
			row = rand() % 10;
			col = rand() % (10 - (size - 1));
			if (board[row][col] == WATER)
			{
				count = 0;
				for (index = 0; index < size; index++)
				{
					if (board[row][col + index] == WATER)
					{
						count++;
					}
				}
				if (count == size)
				{
					for (index = 0; index < size; index++)
					{
						board[row][col + index] = ship;
					}
					occupied = 0;
				}
			}
		}
		else if (direction == 1)
		{
			col = rand() % 10;
			row = rand() % (10 - (size - 1));
			if (board[row][col] == WATER)
			{
				count = 0;
				for (index = 0; index < size; index++)
				{
					if (board[row + index][col] == WATER)
					{
						count++;
					}
				}
				if (count == size)
				{
					for (index = 0; index < size; index++)
					{
						board[row + index][col] = ship;
					}
					occupied = 0;
				}
			}
		}
	}
}

//Manual Ships
void placement_manual(char board[10][10], char ship, int size)
{
	int direction = 0, row = 0, col = 0, ok = 1, index = 0, valid = 0, alright = 0, okie_dokie = 0;
	while (valid == 0)
	{
		if (ship == 'C')
		{
			printf("\n");
			print_board(board);
			printf("\nCarrier:\n");
		}
		else if (ship == 'B')
		{
			printf("\n");
			print_board(board);
			printf("\nBattleship:\n");
		}
		else if (ship == 'R')
		{
			printf("\n");
			print_board(board);
			printf("\nCruiser:\n");
		}
		else if (ship == 'S')
		{
			printf("\n");
			print_board(board);
			printf("\nSubmarine:\n");
		}
		else if (ship == 'D')
		{
			printf("\n");
			print_board(board);
			printf("\nDestroyer:\n");
		}
		while (alright == 0)
		{
			printf("Enter direction (0 = horizontal, 1 = vertical): ");
			scanf("%d", &direction);
			if ((direction == 0) || (direction == 1))
			{
				alright = 1;
			}
		}
		while (okie_dokie == 0)
		{
			printf("Enter start position (row col): ");
			scanf("%d%d", &row, &col);
			if (((row >= 0) && (row <= 9)) && ((col >= 0) && (col <= 9)))
			{
				okie_dokie = 1;
			}
		}
		if (direction == 0)
		{
			for (index = 0; index < size; index++)
			{
				if (board[row][col + index] != WATER)
				{
					ok = 0;
				}
			}
		}
		else if (direction == 1)
		{
			for (index = 0; index < size; index++)
			{
				if (board[row + index][col] != WATER)
				{
					ok = 0;
				}
			}
		}
		if (ok == 0)
		{
			printf("Stupid, put in the right thing.\n");
		}
		else if (ok == 1)
		{
			valid = 1;
			if (direction == 0)
			{
				for (index = 0; index < size; index++)
				{
					board[row][col + index] = ship;
				}
			}
			else if (direction == 1)
			{
				for (index = 0; index < size; index++)
				{
					board[row + index][col] = ship;
				}
			}
		}
	}
}

//Print Board
void print_board(char board[10][10])
{
	int i_row = 0, i_col = 0;
	printf("   0 1 2 3 4 5 6 7 8 9\n");
	for (i_row = 0; i_row < 10; i_row++)
	{
		printf(" %d", (i_row));
		for (i_col = 0; i_col < 10; i_col++)
		{
			printf(" %c", board[i_row][i_col]);
		}
		printf("\n");
	}
}

//Who goes first?
int first_play(void)
{
	int value = 0;
	value = (rand() % 2);
	return value;
}

//Random Shot
void random_shot(char board[10][10], FILE *outfile, Stats p)
{
	int row = 0, col = 0, valid = 0;
	while (valid == 0)
	{
		row = (rand() % 10);
		col = (rand() % 10);
		if ((board[row][col] != HIT) && (board[row][col] != MISS))
		{
			valid = 1;
		}
	}
	if (board[row][col] == WATER)
	{
		p.shots_miss++;
		p.shots_total++;
		fprintf(outfile, "p2: %d,%d miss\n", row, col);
		board[row][col] = MISS;
	}
	else if (board[row][col] != WATER)
	{
		p.shots_hit++;
		p.shots_total++;
		fprintf(outfile, "p2: %d,%d hit\n", row, col);
		board[row][col] = HIT;
	}
}

//Single or Taken?
int check_over(char board[10][10])
{
	int value = 0, row = 0, col = 0;
	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			if ((board[row][col] != WATER) && (board[row][col] != MISS) && (board[row][col] != HIT))
			{
				value++;
			}
		}
	}
	return value;
}

//Manual Shot
void make_shot(char board[10][10], FILE *outfile, Stats p)
{
	int valid = 0, row = 0, col = 0;
	while (valid == 0)
	{
		printf("ATTAAAACK!!! ... butt where?: ");
		scanf("%d%d", &row, &col);
		if ((board[row][col] != HIT) && (board[row][col] != MISS) && (row >= 0) && (row <= 9) && (col >= 0) && (col <= 9))
		{
			valid = 1;
		}
		else
		{
			printf("Stupid, put in the right thing.\n");
		}
	}
	if (board[row][col] == WATER)
	{
		p.shots_miss++;
		p.shots_total++;
		fprintf(outfile, "p1: %d,%d miss\n", row, col);
		board[row][col] = MISS;
	}
	else if (board[row][col] != WATER)
	{
		p.shots_hit++;
		p.shots_total++;
		fprintf(outfile, "p1: %d,%d hit\n", row, col);
		board[row][col] = HIT;
	}
}

//Print Enemy board
void print_enemy(char board[10][10])
{
	int row = 0, col = 0;
	printf("   0 1 2 3 4 5 6 7 8 9\n");
	for (row = 0; row < 10; row++)
	{
		printf(" %d", (row));
		for (col = 0; col < 10; col++)
		{
			if ((board[row][col] == WATER) || (board[row][col] == HIT) || (board[row][col] == MISS))
			{
				printf(" %c", board[row][col]);
			}
			else
			{
				printf(" %c", WATER);
			}
		}
		printf("\n");
	}
}

//Check if sunk
int check_sunk(char board[10][10], char ship, int size)
{
	int value = 0, row = 0, col = 0;
	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			if (board[row][col] == ship)
			{
				value++;
			}
		}
	}
	return value;
}

//Are all the ships gone?
void check_all_sunk(char board[10][10], FILE *outfile)
{
	int c = 0, b = 0, r = 0, s = 0, d = 0;
	if ((check_sunk(board, 'C', 5) == 0) && (c == 0))
	{
		printf("Carrier? What carrier?\n");
		fprintf(outfile, "-> Carrier sunk.\n");
		c++;
	}
	else if ((check_sunk(board, 'B', 4) == 0) && (b == 0))
	{
		printf("Battleship is as dead as my fish.\n");
		fprintf(outfile, "-> Battleship sunk.\n");
		b++;
	}
	else if ((check_sunk(board, 'R', 3) == 0) && (r == 0))
	{
		printf("Cruiser is done, (just like the car)\n");
		fprintf(outfile, "-> Cruiser sunk.\n");
		r++;
	}
	else if ((check_sunk(board, 'S', 3) == 0) && (s == 0))
	{
		printf("I prefer Subway food chains anyway.\n");
		fprintf(outfile, "-> Submarine sunk\n");
		s++;
	}
	else if ((check_sunk(board, 'D', 2) == 0) && (d == 0))
	{
		printf("Destroyer my ass.\n");
		fprintf(outfile, "-> Destroyer sunk\n");
		d++;
	}
}

//Hits Misses Ratio
void calc_ratio(Stats p)
{
	p.shots_ratio = (p.shots_hit / p.shots_miss);
}