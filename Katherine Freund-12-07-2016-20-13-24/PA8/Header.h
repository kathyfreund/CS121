#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct occurences
{
	int num_occurences;
	double frequency;
} Occurrences;


char *my_str_n_copy(char *dest, char*source, int n);

int binary_search(char arr[], int target, int n);

void bubble_sort(char *str_arr[], int num_str);

int is_palindrome(char *str, int length, int start);

int sum_primes(unsigned int n);

int check_prime(unsigned int n);

void maximum_occurrences(char str[], int *num, Occurrences *arr1, int arrsize);

int smallest_sum_sequence(int *A, int lo, int hi);

int max_consecutive_integers(int i2d, int rows, int col);