//Kathy Freund
//11485476
//Section 16-Alana
//10/19/2016

//PLAY THE GAME OF YAHTZEE WOOHOO
//new stuff: working with arrays (and pointers?)


#include "header.h"


int main(void)
{
	//declarations
	int new_game = 1, choice = 0, played = 0, round = 0, roll = 1, re_roll = 1, score1 = 0, score2 = 0;
	int dice_values[5] = { 0 }, roll_values[5] = { 1,1,1,1,1 }, combinations1[13] = { 0 }, combinations2[13] = { 0 }, faces[7] = { 0 };


	//stuff for random number generator
	srand((unsigned int)time(NULL));


	//do while loop - while user wants to keep playing
	do
	{
		played = 0;
		choice = print_game_menu();
		if (choice == 1) // print rules
		{
			print_game_rules();
		}
		else if (choice == 3) // exit
		{
			printf("Goodbye! Thanks for Playing!\n");
			return 0;
		}
		else if (choice == 2) // new game
		{
			//reset scorecards and combinations if user wants to play again
			score1 = 0;
			score2 = 0;
			reset_combinations(combinations1);
			reset_combinations(combinations2);

			for (round = 1; round <= 2; round++)
			{
				system("cls");
				////////////////////////Player 1////////////////////////
				printf("Round %d, Player 1\n\n", round);

				roll_values[0] = 1;
				roll_values[1] = 1;
				roll_values[2] = 1;
				roll_values[3] = 1;
				roll_values[4] = 1;
				re_roll = 1;
				roll = 1;

				while ((roll <= 3) && (re_roll == 1))
				{
					roll_all_dice(dice_values, roll_values);
					//Print dice values
					printf("\nDie 1: %d\nDie 2: %d\nDie 3: %d\nDie 4: %d\nDie 5: %d\n\n", dice_values[0], dice_values[1], dice_values[2], dice_values[3], dice_values[4]);

					//Can you roll again?
					if (roll < 3)
					{
						re_roll = re_roll_dice(roll_values);
					}
					roll++;
					system("pause");
				}

				//Final score for round x
				score1 += get_combo(faces, combinations1, dice_values);

				system("cls");

				/////////////////////////Player 2//////////////////////
				printf("Round %d, Player 2\n\n", round);

				roll_values[0] = 1;
				roll_values[1] = 1;
				roll_values[2] = 1;
				roll_values[3] = 1;
				roll_values[4] = 1;
				re_roll = 1;
				roll = 1;


				while ((roll <= 3) && (re_roll == 1))
				{
					roll_all_dice(dice_values, roll_values);

					//Print dice values
					printf("\nYou have:  %d  %d  %d  %d  %d\n\n", dice_values[0], dice_values[1], dice_values[2], dice_values[3], dice_values[4]);

					//Can you roll again?
					if (roll < 3)
					{
						re_roll = re_roll_dice(roll_values);
					}
					roll++;
					system("pause");
				}
				//final score for p2 for round x
				score2 += get_combo(faces, combinations2, dice_values);
			}

			system("pause");
			system("cls");

			//Total points in the end
			printf("Player 1: %d points\n", score1);
			printf("Player 2: %d points\n\n", score2);


			//Who wins?
			if (score1 > score2)
			{
				printf("Player 1 Wins!\n\n");
			}
			else if (score2 > score1)
			{
				printf("Player 2 Wins!\n\n");
			}
			else if (score1 == score2)
			{
				printf("Tie Game!\n\n");
			}

			played = 1;
		}
		else //invalid input in initial menu
		{
			printf("Error: invalid user input\n");
			system("pause");
		}


		//Ask user if they wanna play again
		if (played == 1)
		{
			new_game = ask_new_game();
		}
		system("cls");

		
	} while (new_game == 1);

	return 0;
}