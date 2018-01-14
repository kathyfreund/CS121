#include "Header.h"






//Alana, need help on 3. Bubble Sort, and 6. Max Occurence









//10 pts, string copy without string.h
char * my_str_n_copy(char *dest, char *source, int n)
{
	int i = 0, size = 0;
	
	for (size = 0; dest[size] != '\0'; ++size); //length of string

	for (i = 0; (i < n) && (source[i] != '\0'); i++)
	{
		dest[i] = source[i];
	}
	return dest;
}
















//10 pts, recall binary search
int binary_search(char arr[], int target, int n)
{
	//where to we get the sorted integer values?
	//do i just make an array filled with random numbers?

	int left = 1, right = n, found = 0, i = -1, mid = 0;
	while ((found == 0) && (left <= right))
	{
		mid = (left + right) / 2;
		if (target == arr[mid])
		{
			found = 1;
			i = mid;
		}
		else if (target < arr[mid])
		{
			right = mid - 1;
		}
		else if (target > arr[mid])
		{
			left = mid + 1;
		}
	}
	return i;
}





















//okay, so here, i just followed what andy said to do on the assignment.
//i'm not sure how the strings are suppose to be sorted though

//10 pts, bubble sort
void bubble_sort(char *str_arr[], int num_str)    //ON PAUSE IDK HELP
{

	// error with reading the array
	int c = 0, u = 0;
	char *ptr_temp = NULL;

	u = num_str - 1;

	while (u - 1 != 0)
	{
		c = 1;

		while (c < u)
		{
			if (strcmp(str_arr[c - 1], str_arr[c]) > 0)
			{
				ptr_temp = str_arr[c - 1];
				str_arr[c - 1] = str_arr[c];
				str_arr[c] = ptr_temp;
			}
			c++;
		}
		u--;
	}
}
















int is_palindrome(char *str, int length, int start) //FIXED: FIX, always comes out as false
{
	if (start >= length)
	{
		return 1;
	}
	//if ((str[start] == str[length - 1]) && (start != '\0'))
	if (str[start] == str[length - 1])
	{
		return is_palindrome(str, length - 1, start + 1);
	}
	else
	{
		return 0;
	}
}


















int sum_primes(unsigned int n) //choice 5
{
	if (n > 1)
	{
		n = check_prime(n) + sum_primes(n - 1);
		return n;
	}
	else
	{
		return 0;
	}

}


int check_prime(unsigned int n)
{
	int i = 2;
	int remainder = n % 2;

	while (i != n && remainder != 0) 
	{
		remainder = n % i;
		i++;
	}
	if (i == n) 
	{
		return n;
	}
	else
	{
		return 0; 
	}
}























//HELP HELP HELP HELP

// O.K. PS ON THIS, I HAD HANNAH AND JOSH HELP ME ON THIS AND 
//HANNAH ALMOST CRIED AND JOSH WAS CONFUSED SO IF YOU CAN FIGURE IT OUT
//YOU WILL BE A DEITY TO ME

void maximum_occurrences(char str[], int *num, Occurrences *arr1, int arrsize)
{
	int i = 0, j = 0, length = 0, temp, max = 0, k = 0;
	double f = 0;
	char maxch = '\0';

	length = strlen(str);

	for (k = 0; k < length; k++)
	{
		arr1[k].num_occurences = 0;
	}

	for (i = 0; i < length; i++)  //count each character
	{
		temp = (str[i] - 97); //something in this cuts the string 
		arr1[temp].num_occurences = arr1[temp].num_occurences + 1;
	}

	for (j = 0; j < 26; j++) //check to see which character occurs the most
	{
		if (max < arr1[j].num_occurences)
		{
			max = arr1[j].num_occurences;
			maxch = j + 97;
		}
	}

	f = ((double)max / (double)length);

	printf("The letter %c occurred the most at %d times. Frequency: %.3lf \n", maxch, max, f);

	return;

}


























int smallest_sum_sequence(int *arr, int lo, int hi) //FIXED: problem with the array passing through
{
	int left = lo, right = lo, sum = INT_MAX, currentMinSum = 0, minLeft = lo, minRight = lo;
	for (int i = lo; i < hi; i++)
	{
		currentMinSum += arr[i];
		if (currentMinSum < sum) 
		{
			sum = currentMinSum;
			right = i;
			minLeft = left;
			minRight = right;
		}
		if (currentMinSum > 0)
		{
			left = i + 1;
			right = left;
			currentMinSum = 0;
		}
	}
	return sum;
}



























int max_consecutive_integers(int i2d[][3], int rows, int col)
{
	int max = 0, temp = 0, i = 0, j = 0, num[9], count[9], n = 0, k = 0, index = 0, length = 0;
	char ch[9];

	while (n < 9) //initialize arrays
	{
		num[n] = 0;
		count[n] = 0;
		n++;
	}
	n = 0;
	for (i = 0; i < rows; i++) //count all subarrays
	{
		for (j = 0; j < col; j++)
		{
			if ((i != 0) || (j != 0))
			{
				if ((i2d[i][j] != i2d[i][j - 1]) || (i2d[i][j] != i2d[i - 1][j + 2]))
				{

					n++;
				}
			}
			num[n] = i2d[i][j];
			count[n]++;

		}
	}

	for (length = 0; num[length] != '\0'; length++);

	//which is largest?
	for (k = 1; k < length; k++)
	{
		temp = count[k];
		if (temp > count[k-1])
		{
			max = temp;
			index = k;
		}
		else if (count[k - 1] > temp)
		{
			max = count[k - 1];
			index = k - 1;
		}
	}


	//index is index where in count, holds the highest number and in num, holds the actual value.

	
	for (i = 0; i < rows; i++) //print matrix
	{
		printf("| ");
		for (j = 0; j < col; j++)
		{
			printf("%d | ", i2d[i][j]);
		}
		printf("\n\n");
	}

	return max;
	
}