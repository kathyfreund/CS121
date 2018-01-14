
//Kathy Freund
//Alana Evey
//ID: 11485476
//PA6

#include "header.h"


int main(void)
{

	FILE *outfile = NULL;
	int new_game = 1, choice = 0, played = 0, setup = 0, first = 0, over = 1;
	char p1_board[10][10], p2_board[10][10];
	Stats p1 = { 0,0,0,0.0,FALSE }, p2 = { 0,0,0,0.0,FALSE };

	srand((unsigned int)time(NULL));

	do
	{
		played = 0;
		choice = print_game_menu();

		//Print Rules
		if (choice == 1)
		{
			print_game_rules();
		}

		//Exit
		else if (choice == 3)
		{
			return 0;
		}

		//New Game
		else if (choice == 2)
		{
			init_board(p1_board);
			init_board(p2_board);
			outfile = fopen("battleship.log", "w");

			placement_random(p2_board, 'C', 5);
			placement_random(p2_board, 'B', 4);
			placement_random(p2_board, 'R', 3);
			placement_random(p2_board, 'S', 3);
			placement_random(p2_board, 'D', 2);

			setup = determine_setup();

			//Random Ships
			if (setup == 0)
			{
				placement_random(p1_board, 'C', 5);
				placement_random(p1_board, 'B', 4);
				placement_random(p1_board, 'R', 3);
				placement_random(p1_board, 'S', 3);
				placement_random(p1_board, 'D', 2);
			}
			//Manual Ships
			else if (setup == 1)
			{
				placement_manual(p1_board, 'C', 5);
				placement_manual(p1_board, 'B', 4);
				placement_manual(p1_board, 'R', 3);
				placement_manual(p1_board, 'S', 3);
				placement_manual(p1_board, 'D', 2);
			}

			system("cls");

			first = first_play();
			//User goes first
			if (first == 0)
			{
				while (over != 0)
				{
					if (over != 0)
					{
						printf("Player's turn:\n\n");
						print_enemy(p2_board);
						make_shot(p2_board, outfile, p1);
						system("cls");
						printf("Player's turn:\n\n");
						print_enemy(p2_board);
						check_all_sunk(p2_board, outfile);
						over = check_over(p2_board);
						system("pause");
						system("cls");
					}
					//Computer plays
					if (over != 0)
					{
						printf("Computer's turn:\n\n");
						random_shot(p1_board, outfile, p2);
						print_board(p1_board);
						check_all_sunk(p1_board, outfile);
						over = check_over(p1_board);
						system("pause");
						system("cls");
					}
				}
			}
			//computer goes first
			else if (first == 1)
			{
				while (over != 0)
				{
					if (over != 0)
					{
						printf("Computer's turn:\n\n");
						random_shot(p1_board, outfile, p2);
						print_board(p1_board);
						check_all_sunk(p1_board, outfile);
						over = check_over(p1_board);
						system("pause");
						system("cls");
					}
					//User plays
					if (over != 0)
					{
						printf("Player's turn:\n\n");
						print_enemy(p2_board);
						make_shot(p2_board, outfile, p1);
						system("cls");
						printf("Player's turn:\n\n");
						print_enemy(p2_board);
						check_all_sunk(p2_board, outfile);
						over = check_over(p2_board);
						system("pause");
						system("cls");
					}
				}
			}

			//Computer wins
			if (check_over(p1_board) == 0)
			{
				fprintf(outfile, "Computer Wins, wow good job.\n\n");
				printf("Computer Wins!\n");
			}
			//User Wins
			else if (check_over(p2_board) == 0)
			{
				fprintf(outfile, "Player Wins, wow, you want a metal or something?\n\n");
				printf("Player Wins!\n");
			}

			calc_ratio(p1);
			calc_ratio(p2);
			print_stats(outfile, p1, p2);
			fclose(outfile);
			played = 1;
		}
		else
		{
			printf("Stupid, type in the right thing, sheesh.\n");
			system("pause");
		}

		if (played == 1)
		{
			new_game = ask_new_game();
		}
		system("cls");
	} while (new_game == 1);



	return 0;
}