#include "header.h"
//Katherine Freund
//ID: 11485476
//TA: Alana
//Date: 10/7/2016
//PA4


int main(void)
{

	double wager = 0, balance = 0, starting_balance = 0;
	int die1 = 0, die2 = 0, sum = 0, check_wager = 0, win_loss_point, point_value = 0, result = 0, play_again = 0, roll = 0;
	srand((unsigned int)time(NULL)); 

	//Print Rules Games and Get Balance
	print_game_rules();
	starting_balance = get_bank_balance();

	printf("Alright, here we go!\n");

	play_again = 1;

	//Loop Starts for Play again
	while (play_again == 1)
	{

		//Wagers
		wager = get_wager_amount();
		check_wager = check_wager_amount(wager, balance);

		//Intial Roll
		die1 = roll_die();
		die2 = roll_die();
		sum = calculate_sum_dice(die1, die2);
		roll++;
		printf("Die 1 was %d.\nDie 2 was %d.\nYour die sum is: %d!\n", die1, die2, sum);

		//Check if Win or Lose or other
		win_loss_point = is_win_loss_or_point(sum);

	
		//If other
		if (win_loss_point == -1)
		{
			printf("You got a point!\n");
			point_value = sum;
			
			//start loop for other
			while (win_loss_point == -1)
			{
				die1 = roll_die();
				die2 = roll_die();
				sum = calculate_sum_dice(die1, die2);
				win_loss_point = is_point_loss_or_neither(sum, point_value);
				roll++;
				printf("Die 1 was %d.\nDie 2 was %d.\nYour die sum is: %d!\n", die1, die2, sum);
				system("pause");
				printf("\n");
				
			}
		}

		//Win
		if (win_loss_point == 1)
		{
			printf("You win!\n\n");
		}

		//Lose
		else if (win_loss_point == 0)
		{
			printf("You lose :(\n\n");
		}

		//Break from Game
		system("pause");


		//Display adjusted balance
		balance = adjust_bank_balance(starting_balance, wager, win_loss_point);
		printf("Bank Balance: %lf\n\n", balance);

		//Chatter messages
		chatter_messages(roll, win_loss_point, starting_balance, balance);

		//Prompt user to play again
		printf("Would you like to play again? Press 1 for yes, or 0 for no: ");
		scanf(" %d", &play_again);

		starting_balance = balance;

		
	}


	return 0;
}