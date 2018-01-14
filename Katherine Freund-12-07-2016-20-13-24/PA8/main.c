#include "Header.h"

int main()
{


	//Check to see if functions work:
	int choice = 0, n = 0, target = 0, tf = 0, i = 0, length = 0, num = 0, sum = 0, max_count = 0, x = 0, col = 0, row = 0, max_cons = 0, consec[3][3], *ptr_bub[3];
	unsigned int min[5];
	char source[20], dest[20] = { 0 }, *ptr_dest, *ptr_src, palindrome[20], max_occ[20], arr1, struct_occ[20], *bubble[3];
	char bin_srch[10] = { 2, 3, 6, 7, 10, 15, 19, 22, 24, 31 };
	char temp[3][20];
	do { //repeats menu until user quits

		printf("Select an Option:\n\n");
		printf("1. String Copy\n");
		printf("2. Binary Search\n");
		printf("3. Bubble Sort\n");
		printf("4. Palindrome Check\n");
		printf("5. Sum of Prime Numbers\n");
		printf("6. Max Occurence\n");
		printf("7. Smallest Sum Sequence\n");
		printf("8. (Extra Credit) Max Consecutive Integers\n");
		printf("9. Quit\n\n");

		scanf("%d", &choice);

		system("cls");

		if (choice == 1) //////////////////////////////////////////////
		{
			printf("What do you want to copy?\n"); //get string
			scanf("%s", &source);
			printf("How many characters do you want to copy?\n"); //get n
			scanf("%d", &n);

			ptr_dest = &dest; //initialize ptr

			ptr_dest = my_str_n_copy(dest, source, n);

			printf("This is your copy: %s\n", dest);
			system("pause");
			system("cls");
		}
		else if (choice == 2) /////////////////////////////////////////
		{
			printf("What is your target value?\n");
			scanf("%d", &target);

			i = 0; //initialize

			i = binary_search(bin_srch, target, 10);

			if (i >= 0)
			{
				printf("True, value found at index %d.\n", i);
			}
			else
			{
				printf("False, no value found.\n");
			}
			system("pause");
			system("cls");
		}
		else if (choice == 3) ////////////////////////////////////////// FIXFIXFIXFIXFIXFIX
		{
			printf("Please Enter 3 strings to sort:\n");
			
			
			for (i = 0; i < 3; i++)
			{
				printf("String %d: \n", i + 1);
				scanf("%s", &temp[i]);	
				bubble[i] = &temp[i];
				//ptr_bub[i] = &bubble[i];
			}

			bubble_sort(bubble, 3);

			printf("Here is your sorted list: ");
			for (i = 0; i < 3; i++)
			{
				printf("%s ", bubble[i]);
			}
			system("pause");
			system("cls");
		}
		else if (choice == 4) //////////////////////////////////////////
		{
			printf("Enter your attempted Palindrome:\n");
			scanf("%s", &palindrome);

			int length = 0;

			for (length = 0; palindrome[length] != '\0'; ++length); //length of string

			tf = is_palindrome(palindrome, length, 0);

			if (tf == 1)
			{
				printf("TRUE: Your word is a palindrome.\n");
			}
			else
			{
				printf("FALSE: Your word is not a palindrome.\n");
			}
			system("pause");
			system("cls");
		}
		else if (choice == 5)//////////////////////////////////////////////
		{
			printf("Enter your number: \n");
			scanf("%d", &num);
			sum = sum_primes(num);
			printf("The sum of primes is: %d\n\n", sum);
			system("pause");
			system("cls");

		}
		else if (choice == 6)///////////////////////////////////////////////
		{

			printf("Please enter your phrase:\n");
			scanf("%s", &max_occ);

			int *num = 0;
			struct Occurrences *arr1[25];

			maximum_occurrences(max_occ, max_count, arr1, 25);

			system("pause");
			system("cls");
		}
		else if (choice == 7)//////////////////////////////////////////////
		{
			printf("Please enter 5 random numbers: \n");
			n = 0;
			while (5 > n)
			{
				printf("Number %d: \n", (n+1));
				scanf("%d", &min[n]);
				n++;
			}
			sum = smallest_sum_sequence(min, 0, n); // FIXED: problem passing array over
			printf("The smallest sum of all possible subarrays is: %d.\n", sum);
			system("pause");
			system("cls");

		}
		else if (choice == 8) /////////////////////////////////////////////
		{
			printf("You have a 3 x 3 matrix to work with.\n");
			
			for (i = 0; i < 3; i++) //rows
			{
				for (n = 0; n < 3; n++) //columns
				{
					printf("Please input value for column %d, row %d.\n", i+1, n+1);
					scanf("%d", &consec[i][n]);
				}
			}

			max_cons = max_consecutive_integers(consec, 3, 3);
			printf("\n");

			printf("The max amount of consecutive integers is %d.\n", max_cons);
			system("pause");
			system("cls");

		}
		else if (choice == 9)
		{ //quit option
		}
		else
		{
			printf("Whoops! Please select one of the options listed below.\n\n\n");
			choice = 1;
		}

	} while ((choice > 0) && (choice < 9));

	return 0;
}