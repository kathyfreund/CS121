#include "header.h"

void print_game_rules(void)
{
	printf("THE GAME IS CALLED CRAPS! \n\nThese are the Rules: \n");
	printf("You will roll two dice, then take the sum of the two dice.\n");
	printf("If you roll a sum of 7 or 11 on the first throw, you win!\n");
	printf("If you roll a sum of 2, 3, or 12 on the first throw, you lose.\n\n");
	printf("If you roll a sum of 4, 5, 6, 8, 9, or 10 on the first throw, your sum becomes your 'point'\n");
	printf("If you get a point, you must continue rolling until you hit your point again.\n");
	printf("Be careful though! If you roll a sum of 7 while trying to hit your point, you lose!\n\n");
	printf("How 'bout it? Ready to give it a go?\n\n\n\n");
}

//Finances
double get_bank_balance(void)
{
	double balance = 0.0;
	printf("Please enter the amount you want to play with (bank balance): ");
	scanf("%lf", &balance);
	return balance;
}
double get_wager_amount(void)
{
	double wager = 0.0;
	printf("What is your wager? ");
	scanf("%lf", &wager);
	return wager;
}
int check_wager_amount(double wager, double balance)
{
	int subtract = 0;
	subtract = balance - wager;
	if (subtract <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}




//Luck of the draw
int roll_die(void)
{
	int num = 0;
	num = rand() % 6 + 1;
	return num;
}
int calculate_sum_dice(int die1, int die2)
{
	int sum = 0;
	sum = die1 + die2;
	return sum;
}






//If you didnt win nor lose
int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int result = 0;
	if (sum_dice == 7)
	{
		printf("You lose :(\n");
		result = 0;
		return result;
	}
	else if (sum_dice == point_value)
	{
		printf("You Win!\n");
		result = 1;
		return result;
	}
	else
	{
		printf("Keep going!\n\n");
		result = -1;
		system("pause");
	}
}




//Adjust Finances
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	double new_bank_balance = 0;
	if (add_or_subtract == 1)
	{
		new_bank_balance = bank_balance + wager_amount;
		return new_bank_balance;
	}
	else if (add_or_subtract == 0)
	{
		new_bank_balance = bank_balance - wager_amount;
		return new_bank_balance;
	}
}





//Chatter messages
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	if (number_rolls >= 10)
	{
		printf("Lot of Rolls there buddy, do you have a life?\n");
	}

	if (win_loss_neither == 1)
	{
		printf("Wow, you won! You wanna try your luck again?\n");
	}
	else if (win_loss_neither == 0)
	{
		printf("Ugh, tought luck buddy, maybe next time.\n");
	}

	if (initial_bank_balance > current_bank_balance)
	{
		printf("Dude, you're losing money. STEP IT UP!\n");
	}
	if (initial_bank_balance < current_bank_balance)
	{
		printf("Okay rich guy, calm down\n");
	}
}