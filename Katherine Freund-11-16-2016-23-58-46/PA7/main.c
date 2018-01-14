
#include "header.h"

int main(void)
{
	Stats player = { '\0', 0 };
	FILE *infile = NULL;
	int choice = 0, level = 0, i = 0, value = 0;

	infile = fopen("pa8_stats.txt", "w");
	srand((unsigned int)time(NULL));

	do
	{
		choice = print_menu();
		if (choice == 1) // learn about program
		{
			print_rules();
		}
		else if (choice == 2) // enter initials
		{
			get_initials(player);
		}
		else if (choice == 3) // set difficulty
		{
			level = get_difficulty();
		}
		else if (choice == 4) // run problems
		{
			
			if (level == 1 || (level == 2) || (level == 3) || (level == 4) || (level == 5))
			{
				for (i = 0; i < 10; i++)
				{
					value = ask_problem(level);
					if (value == 1)
					{
						player.score += level;
					}
					else
					{
						player.score -= 1;
					}
				}
			}
			else
			{
				printf("Whoops, please go back and select a level!\n\n");
			}
		}
	} while (choice != 5);

	write_stats(player, infile);
	fclose(infile);

	return 0;
}